#include "NFA.hpp"
#include "../../language/Language.hpp"
#include <memory>


namespace scanner {
    auto NFA::GetSubExpressionEndOffset(const string &regex, int &i) -> int {
        int offset = 1; // the offset in the subexpression from the initial '('
        int parenthesisNestingLevel = 1;

        // Find the index of the corresponding closing bracket
        while (parenthesisNestingLevel > 0) {
            if (regex[i+offset] == '(') {
                parenthesisNestingLevel++;
            } else if (regex[i+offset] == ')') {
                parenthesisNestingLevel--;
            }
            offset++;
        }

        return offset;
    }

    auto NFA::ConstructUnion(const NFA &nfa1, const NFA &nfa2) -> NFA {
        NFA newNfa = NFA();
        newNfa.initialState->AddEpsilonTransition(nfa1.initialState);
        newNfa.initialState->AddEpsilonTransition(nfa2.initialState);
        nfa1.acceptingState->AddEpsilonTransition(newNfa.acceptingState);
        nfa2.acceptingState->AddEpsilonTransition(newNfa.acceptingState);
        return newNfa;
    }

    auto NFA::ConstructStar(const NFA &nfa) -> NFA {
        NFA newNfa = NFA();
        newNfa.initialState->AddEpsilonTransition(nfa.initialState);
        newNfa.initialState->AddEpsilonTransition(newNfa.acceptingState);
        newNfa.acceptingState->AddEpsilonTransition(newNfa.initialState);
        nfa.acceptingState->AddEpsilonTransition(newNfa.acceptingState);
        return newNfa;
    }

    auto NFA::ConstructPlus(const NFA &nfa) -> NFA {
        NFA newNfa = NFA();
        newNfa.initialState->AddEpsilonTransition(nfa.initialState);
        newNfa.acceptingState->AddEpsilonTransition(newNfa.initialState);
        nfa.acceptingState->AddEpsilonTransition(newNfa.acceptingState);
        return newNfa;
    }

    auto NFA::ConstructOptional(const NFA &nfa) -> NFA {
        NFA newNfa = NFA();
        newNfa.initialState->AddEpsilonTransition(nfa.initialState);
        newNfa.initialState->AddEpsilonTransition(newNfa.acceptingState);
        nfa.acceptingState->AddEpsilonTransition(newNfa.acceptingState);
        return newNfa;
    }

    auto NFA::ConstructDot() -> NFA {
        NFA newNfa = NFA();
        for (char character : language::characters) {
            newNfa.initialState->AddTransition(character, newNfa.acceptingState);
        }
        return newNfa;
    }

    auto NFA::ConstructCharacter(const char character) -> NFA {
        NFA newNfa = NFA();
        newNfa.initialState->AddTransition(character, newNfa.acceptingState);
        return newNfa;
    }

    auto NFA::ConstructCharacterRange(const char startCharacter, const char endCharacter) -> NFA {
        NFA newNfa = NFA();
        int startIndex = 0;
        int endIndex = 0;

        for (int i = 0; i < language::characters.size(); i++) {
            if (language::characters.at(i) == startCharacter) {
                startIndex = i;
            } else if (language::characters.at(i) == endCharacter) {
                endIndex = i;
            }
        }

        for (int i = startIndex; i <= endIndex; i++) {
            newNfa.initialState->AddTransition(language::characters.at(i), newNfa.acceptingState);
        }

        return newNfa;
    }

    auto NFA::ConstructUpArrow(const char exceptCharacter) -> NFA {
        NFA newNfa = NFA();
        for (const char character : language::characters) {
            if (character != exceptCharacter) {
                newNfa.initialState->AddTransition(character, newNfa.acceptingState);
            }
        }
        return newNfa;
    }

    auto NFA::ConstructConcatenation(const NFA &nfa1, const NFA &nfa2) -> NFA {
        NFA newNfa = NFA();
        newNfa.initialState->AddEpsilonTransition(nfa1.initialState);
        nfa1.acceptingState->AddEpsilonTransition(nfa2.initialState);
        nfa2.acceptingState->AddEpsilonTransition(newNfa.acceptingState);
        return newNfa;
    }

    NFA::NFA() {
        initialState = make_shared<NFAState>();
        acceptingState = make_shared<NFAState>();
    }

    auto NFA::GetInitialState() const -> shared_ptr<NFAState> {
        return initialState;
    }

    auto NFA::FromRegex(const string &regex) -> NFA {
        stack<NFA> workStack;
        stack<OperationType> operationStack; // The current NFA should be <operation> to the previous element
        int i = 0;

        // Iterate through all characters in the regex and apply the rule for each character
        while (i < regex.length()) {

            if (regex.at(i) == '(') {
                const int offset = GetSubExpressionEndOffset(regex, i);
                const string subExpressionRegex = regex.substr(i+1, offset-2);
                workStack.push(FromRegex(subExpressionRegex));
                workStack.top().acceptingState->SetAccepting(false);
                operationStack.push(CONCATENATION);
                i += offset;

            } else if (regex.at(i) == '|') {
                operationStack.pop();
                operationStack.push(UNION);
                i++;

            } else if (regex.at(i) == '*') {
                const NFA nfa = workStack.top();
                workStack.pop();
                workStack.push(ConstructStar(nfa));
                operationStack.push(CONCATENATION);
                i++;

            } else if (regex.at(i) == '+') {
                const NFA nfa = workStack.top();
                workStack.pop();
                workStack.push(ConstructPlus(nfa));
                operationStack.push(CONCATENATION);
                i++;

            } else if (regex.at(i) == '?') {
                const NFA nfa = workStack.top();
                workStack.pop();
                workStack.push(ConstructOptional(nfa));
                operationStack.push(CONCATENATION);
                i++;

            } else if (regex.at(i) == '[') {
                workStack.push(ConstructCharacterRange(regex.at(i+1), regex.at(i+3)));
                operationStack.push(CONCATENATION);
                i += 5;

            } else if (regex.at(i) == '.') {
                workStack.push(ConstructDot());
                operationStack.push(CONCATENATION);
                i++;
            
            } else if (regex.at(i) == '^') {
                workStack.push(ConstructUpArrow(regex.at(i+1)));
                operationStack.push(CONCATENATION);
                i += 2;

            } else if (regex.at(i) == '\\') {
                workStack.push(ConstructCharacter(regex.at(i+1)));
                operationStack.push(CONCATENATION);
                i += 2;
            
            } else {
                workStack.push(ConstructCharacter(regex.at(i)));
                operationStack.push(CONCATENATION);
                i++;
            }
        }

        operationStack.pop();

        // Concatenate everything on the stack into one long NFA
        while (workStack.size() > 1) {
            if (operationStack.top() == CONCATENATION) {
                const NFA nfa2 = workStack.top();
                workStack.pop();
                const NFA nfa1 = workStack.top();
                workStack.pop();
                workStack.push(ConstructConcatenation(nfa1, nfa2));

            } else if (operationStack.top() == UNION) {
                const NFA nfa2 = workStack.top();
                workStack.pop();
                const NFA nfa1 = workStack.top();
                workStack.pop();
                workStack.push(ConstructUnion(nfa1, nfa2));
            }

            operationStack.pop();
        }

        workStack.top().acceptingState->SetAccepting(true); // todo this breaks w/ nested calls

        return workStack.top();
    }
}