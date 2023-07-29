#include "Scanner.hpp"
#include "errors/Errors.hpp"
#include "../language/Language.hpp"
#include "language/Symbols.hpp"
#include "scanner/DFA/DFA.hpp"
#include <optional>
#include <vector>


namespace scanner {
    namespace {
        auto GetTerminalDfas() -> map<SymbolType, DFA> {
            map<SymbolType, DFA> terminalDfas;
            for (const auto &terminalPair : language::terminalRegex) {
                terminalDfas.insert(make_pair(terminalPair.first, DFA::FromNFA(NFA::FromRegex(terminalPair.second))));
            }
            return terminalDfas;
        }

        auto ComputeIndentationLevel(string line) -> int {
            int level = 0;
            while (line.starts_with("    ")) {
                line = line.substr(4, line.size()-4);
                level++;
            }
            return level;
        }

        auto ComputerIndentationTerminals(const int currentIndentation, const int previousIndentation) -> vector<Terminal> {
            vector<Terminal> indentationTerminals;
            const int indentationChange = currentIndentation - previousIndentation;
            if (indentationChange > 0) {
                for (int i = 0; i < indentationChange; i++) {
                    indentationTerminals.push_back(Terminal(language::INDENT_PLUS, ""));
                }
            }
            if (indentationChange < 0) {
                for (int i = 0; i < -indentationChange; i++) {
                    indentationTerminals.push_back(Terminal(language::INDENT_MINUS, ""));
                }
            }
            return indentationTerminals;
        }

        auto ComputeFinalTerminals(const Line &lastLine) -> vector<Terminal> {
            vector<Terminal> terminals;
            for (int i = 0; i < lastLine.indentationLevel; i++) {
                terminals.push_back(Terminal(language::INDENT_MINUS, ""));
            }
            terminals.push_back(Terminal(language::END_OF_FILE, ""));
            return terminals;
        }

        auto FindAcceptingTerminal(const map<SymbolType, DFA> &activeDfas) -> optional<SymbolType> {
            optional<SymbolType> firstAcceptingTerminal;
            for (const auto &terminalPair : activeDfas) {
                if (terminalPair.second.IsAtAcceptingState()) {
                    firstAcceptingTerminal = terminalPair.first;
                    break;
                }
            }
            return firstAcceptingTerminal;
        }

        auto ParseLine(const map<SymbolType, DFA> &terminalDfas, const string &line, const string &path, const int lineNumber) -> vector<Terminal> {
            // Match DFAs until no further transitions are possible, at which point create a new terminal and start again
            vector<Terminal> terminals;
            int i = 0;
            int previousCharacterStartIndex = 0;
            map<SymbolType, DFA> activeDfas = terminalDfas;
            while (i < line.size()) {

                // Check if any DFAs can traverse to the next character
                bool anyDfasCanTraverse = false;
                for (const auto &terminalPair : activeDfas) {
                    if (terminalPair.second.CanTraverse(line.at(i))) {
                        anyDfasCanTraverse = true;
                    }
                }

                // If no DFAs can traverse, try and finish the current terminal and reset the active DFAs
                if (!anyDfasCanTraverse) {
                    optional<SymbolType> firstAcceptingTerminal = FindAcceptingTerminal(activeDfas);

                    // No DFA is in an accepting state
                    if (!firstAcceptingTerminal.has_value()) {
                        Errors::UnrecognizedSymbol(path, lineNumber, line.substr(previousCharacterStartIndex, i-previousCharacterStartIndex));
                        return terminals;
                    }

                    // If the terminal is a comment character, just don't parse the rest of the line
                    if (firstAcceptingTerminal.value() == language::COMMENT) {
                        break;
                    }

                    // Push terminal back if not whitespace
                    if (firstAcceptingTerminal.value() != language::WHITESPACE) {
                        terminals.push_back(Terminal(
                            firstAcceptingTerminal.value(),
                            line.substr(previousCharacterStartIndex, i-previousCharacterStartIndex)));
                    }

                    activeDfas = terminalDfas;
                    previousCharacterStartIndex = i;
                }

                // Remove DFAs that cannot traverse the current character
                for (auto iterator = activeDfas.begin(); iterator != activeDfas.end();) {
                    if (!iterator->second.CanTraverse(line.at(i))) {
                        iterator = activeDfas.erase(iterator);
                    } else {
                        iterator++;
                    }
                }

                // Traverse remaining DFAs to the next character
                for (auto &terminalPair : activeDfas) {
                    terminalPair.second.Traverse(line.at(i));
                }

                i++;
            }

            // We are at the end of the line; try and finish the terminal
            optional<SymbolType> firstAcceptingTerminal = FindAcceptingTerminal(activeDfas);

            // No DFA is in an accepting state
            if (!firstAcceptingTerminal.has_value()) {
                Errors::UnrecognizedSymbol(path, lineNumber, line.substr(previousCharacterStartIndex, i-previousCharacterStartIndex));
                return terminals;
            }

            // Push terminal back if not whitespace or comment
            if (firstAcceptingTerminal.value() != language::WHITESPACE && firstAcceptingTerminal.value() != language::COMMENT) {
                terminals.push_back(Terminal(
                            firstAcceptingTerminal.value(),
                            line.substr(previousCharacterStartIndex, i-previousCharacterStartIndex)));
            }

            return terminals;
        }
    }

    ostream& operator<<(ostream& stream, const Line& line) {
        stream << "line " << line.number << " | indent " << line.indentationLevel << " | terminals";
        for (Terminal terminal : line.terminals) {
            stream << " [" << terminal.type << " " << terminal.text + "]";
        }
        return stream;
    }

    auto Scan(const string &path, const vector<string> &lines) -> vector<Line> {
        const map<SymbolType, DFA> terminalDfas = GetTerminalDfas();
        vector<Line> scannedLines;
        int lineNumber = 1;
        for (const string &line : lines) {

            if (line.empty()) {
                lineNumber++;
                continue;
            }

            vector<Terminal> indentationTerminals;
            const int indentationLevel = ComputeIndentationLevel(line);
            if (scannedLines.size() > 0) {
                for (const Terminal &terminal : ComputerIndentationTerminals(indentationLevel, scannedLines.at(scannedLines.size()-1).indentationLevel)) {
                    indentationTerminals.push_back(terminal);
                }
            }

            vector<Terminal> lineTerminals;
            for (const Terminal &terminal : ParseLine(terminalDfas, line, path, lineNumber)) {
                lineTerminals.push_back(terminal);
            }

            // Don't push back lines that are entirely whitespace
            if (lineTerminals.empty()) {
                lineNumber++;
                continue;
            }

            // Combine terminal vectors together
            vector<Terminal> terminals;
            for (const Terminal &terminal : indentationTerminals) {
                terminals.push_back(terminal);
            }
            for (const Terminal &terminal : lineTerminals) {
                terminals.push_back(terminal);
            }
            terminals.push_back(Terminal(language::NEWLINE, ""));

            scannedLines.push_back(Line{ 
                    .number = lineNumber,
                    .indentationLevel = indentationLevel,
                    .terminals = terminals});

            lineNumber++;
        }

        for (const Terminal terminal : ComputeFinalTerminals(scannedLines.at(scannedLines.size()-1))) {
            scannedLines.at(scannedLines.size()-1).terminals.push_back(terminal);
        }

        return scannedLines;
    }
}