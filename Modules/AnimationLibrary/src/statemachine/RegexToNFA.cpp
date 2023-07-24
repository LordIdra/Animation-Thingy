#include "RegexToNFA.hpp"
#include "NFA.hpp"
#include <unordered_map>


namespace statemachine {
    const string NUMERIC_CHARACTERS_MARKER = "[numericCharacters]";
    const string IDENTIFIER_CHARACTERS_1_MARKER = "[identifierCharacters1]";
    const string IDENTIFIER_CHARACTERS_2_MARKER = "[identifierCharacters2]";

    const set<char> NUMERIC_CHARACTERS = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    const set<char> IDENTIFIER_CHARACTERS_1 = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '_'};

    // Yes, it's annoying we have to duplicate the first set, but the alternative requires an initialize function, which is even more annoying (screw C++)
    const set<char> IDENTIFIER_CHARACTERS_2 = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '_', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    namespace {
        auto AddCharacters(NFA &stateMachine, const set<char> &characters) -> void {
            const int nextState = stateMachine.NewState();
            for (const char character : characters) {
                stateMachine.NewTransition(character, nextState);
            }
            stateMachine.Goto(nextState);
        }

        auto AddKleeneClosure(NFA &stateMachine) -> void {
            stateMachine.NewTransition(NFA::EPSILON, stateMachine.GetPreviousState());
        }

        auto AddAlternation(NFA &stateMachine) -> void {
            stateMachine.Goto(stateMachine.GetPreviousState());
        }

        auto AddAcceptingState(NFA &stateMachine, const int terminal) -> void {
            stateMachine.SetAcceptingState(terminal);
        }

        auto NextStringMatches(const string regex, const string match, const int index) -> bool {
            return regex.size() >= match.length() && regex.substr(index, match.length()) == match;
        }

        auto ParseRegex(NFA &stateMachine, const int terminal, string regex) -> void {
             int index = 0;
             while (index <= regex.size()) {
                
                if (NextStringMatches(regex, NUMERIC_CHARACTERS_MARKER, index)) {
                    AddCharacters(stateMachine, NUMERIC_CHARACTERS);
                    index += NUMERIC_CHARACTERS_MARKER.length();
                    continue;
                }

                if (NextStringMatches(regex, IDENTIFIER_CHARACTERS_1_MARKER, index)) {
                    AddCharacters(stateMachine, IDENTIFIER_CHARACTERS_1);
                    index += IDENTIFIER_CHARACTERS_1_MARKER.length();
                    continue;
                }

                if (NextStringMatches(regex, IDENTIFIER_CHARACTERS_2_MARKER, index)) {
                    AddCharacters(stateMachine, IDENTIFIER_CHARACTERS_2);
                    index += IDENTIFIER_CHARACTERS_2_MARKER.length();
                    continue;
                }

                if (NextStringMatches(regex, "*", index)) {
                    AddKleeneClosure(stateMachine);
                    index += 1;
                    continue;
                }

                // TODO fix this lmao
                if (NextStringMatches(regex, "|", index)) {
                    AddAlternation(stateMachine);
                    index += 1;
                    continue;
                }

                if (NextStringMatches(regex, "\\", index)) {
                    index += 1;
                    AddCharacters(stateMachine, set<char>{ regex.at(index) });
                    index += 1;
                    continue;
                }

                AddCharacters(stateMachine, set<char>{ regex.at(index) });
             }
            
            AddAcceptingState(stateMachine, terminal);
        }
    }
    
    // Supports * and |
    auto BuildNFA(const unordered_map<int, string> &terminalRegexes) -> NFA {
        NFA stateMachine;

        for (const pair<int, string> &terminalRegex : terminalRegexes) {
            ParseRegex(stateMachine, terminalRegex.first, terminalRegex.second);
        }

        return stateMachine;
    }
}