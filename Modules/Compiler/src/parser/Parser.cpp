#include "Parser.hpp"
#include "State.hpp"
#include "errors/Errors.hpp"
#include "language/Language.hpp"
#include "language/Symbols.hpp"
#include "parser/Tables.hpp"

using language::Symbol;



namespace parser {
    namespace {
        bool initialized = false;
        shared_ptr<State> root;
    }

    auto Parse(const string &path, const vector<Line> &lines) -> shared_ptr<NonTerminal> {
        if (!initialized) {
            root = State::BuildRoot();
            initialized = true;
        }

        stack<shared_ptr<State>> stateStack;
        stack<Symbol> symbolStack;
        stateStack.push(root);
        int lineIndex = 0;
        int terminalIndex = 0;
        bool parseComplete = false;

        while (!parseComplete) {
            Terminal currentTerminal = lines.at(lineIndex).terminals.at(terminalIndex);

            cout << "[" << lineIndex << ":" << terminalIndex << "] NEW STATE" << "\n";

            cout << " next terminal | " << language::ToString(lines.at(lineIndex).terminals.at(terminalIndex).type) << "\n";

            cout << " symbols | ";
            for (stack<Symbol> clone = symbolStack; !clone.empty(); clone.pop()) {
                cout << language::ToString(clone.top().type) << " ";
            }
            cout << "\n";

            cout << " state |" << "\n";
            for (auto x : stateStack.top()->GetItems()) {
                cout << "  " << language::ToString(x.left) << " -> ";
                for (auto y : x.right) {
                    cout << language::ToString(y) << " ";
                }
                cout << "(" << x.position << ") { ";
                for (auto y : x.lookahead) {
                    cout << language::ToString(y) << " ";
                }
                cout << "}\n";
            }

            cout << " possible transitions |" << "\n";
            for (auto x : Tables::GetActionTable()) {
                if (x.first.first != stateStack.top()) {
                    continue;
                }
                cout << "  " << language::ToString(x.first.second) << " -> ";
                switch (x.second.type) {
                    case Tables::ACCEPT: cout << "ACCEPT"; break;
                    case Tables::SHIFT: cout << "SHIFT " << x.second.state; break;
                    case Tables::REDUCE: cout << "REDUCE " << language::ToString(x.second.item.left); break;
                }
                cout << "\n";
            }

            if (!Tables::HasAction(stateStack.top(), currentTerminal.type)) {
                Errors::InvalidSyntax(path, lines.at(lineIndex).number, currentTerminal);
                return nullptr;
            }

            Tables::Action action = Tables::GetAction(stateStack.top(), currentTerminal.type);

            cout << " action | ";
            switch (action.type) {
                case Tables::ACCEPT: cout << "ACCEPT"; break;
                case Tables::SHIFT: cout << "SHIFT " << action.state; break;
                case Tables::REDUCE: cout << "REDUCE " << language::ToString(action.item.left); break;
            }
            cout << "\n";
            cout << "\n";

            switch (action.type) {
                case Tables::ACCEPT:
                    parseComplete = true;
                    break;

                case Tables::SHIFT:
                    stateStack.push(action.state);
                    symbolStack.push(currentTerminal.type);
                    terminalIndex++;
                    if (terminalIndex == lines.at(lineIndex).terminals.size()) {
                        terminalIndex = 0;
                        lineIndex++;
                    }
                    break;

                case Tables::REDUCE:
                    for (int i = 0; i < action.item.right.size(); i++) {
                        stateStack.pop();
                        symbolStack.pop();
                    }
                    symbolStack.push(action.item.left);
                    stateStack.push(Tables::GetGoto(stateStack.top(), action.item.left));
                    break;
            }
        }

        return nullptr;
    }
}