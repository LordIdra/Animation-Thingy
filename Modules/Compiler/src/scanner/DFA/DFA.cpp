#include "DFA.hpp"
#include "../../language/Language.hpp"
#include "scanner/DFA/DFAState.hpp"
#include "scanner/NFA/NFAState.hpp"
#include <memory>


namespace scanner {
    auto DFA::GetStatesReachableByCharacter(const shared_ptr<DFAState> &state, const char &character) -> set<shared_ptr<NFAState>> {
        set<shared_ptr<NFAState>> statesReachableByCharacter;
        for (const shared_ptr<NFAState> &nfaState : state->GetNfaStates()) {
            if (nfaState->HasTransition(character)) {
                statesReachableByCharacter.insert(nfaState->GetTransition(character));
            }
        }
        return statesReachableByCharacter;
    }

    auto DFA::FindState(const set<shared_ptr<DFAState>> &allDfaStates, const set<shared_ptr<NFAState>> &nfaStates) -> optional<shared_ptr<DFAState>> {
        for (shared_ptr<DFAState> state : allDfaStates) {
            if (state->GetNfaStates() == nfaStates) {
                return state;
            }
        }
        return {};
    }

    DFA::DFA(const set<shared_ptr<NFAState>> &states) {
        initialState = make_shared<DFAState> (states);
        currentState = initialState;
    }

    auto DFA::GetInitialState() const -> shared_ptr<DFAState> {
        return initialState;
    }

    auto DFA::CanTraverse(const char &character) const -> bool {
        return currentState->HasTransition(character);
    }

    auto DFA::Traverse(const char &character) -> void {
        currentState = currentState->GetTransition(character);
    }

    auto DFA::IsAtAcceptingState() const -> bool {
        return currentState->IsAccepting();
    }

    auto DFA::FromNFA(const NFA &nfa) -> DFA {
        set<shared_ptr<NFAState>> shallowEpsilonClosure = nfa.GetInitialState()->GetEpsilonStates();
        shallowEpsilonClosure.insert(nfa.GetInitialState());

        DFA dfa = DFA(NFAState::GetRecursiveEpsilonClosure(shallowEpsilonClosure));
        stack<shared_ptr<DFAState>> unprocessedStates;
        set<shared_ptr<DFAState>> allDfaStates;
        unprocessedStates.push(dfa.initialState);
        allDfaStates.insert(dfa.initialState);

        while (!unprocessedStates.empty()) {

            // Get latest unprocessed state
            shared_ptr<DFAState> currentState = unprocessedStates.top();
            unprocessedStates.pop();

            // Process the state for every character in the language
            for (const char character : language::characters) {

                // Get all the states reachable by a transition to the character (including the epsilon closure of those states)
                const set<shared_ptr<NFAState>> statesReachableByCharacter = GetStatesReachableByCharacter(currentState, character);
                const set<shared_ptr<NFAState>> epsilonClosure = NFAState::GetRecursiveEpsilonClosure(statesReachableByCharacter);

                // If there are no states reachable by this character
                if (epsilonClosure.empty()) {
                    continue;
                }

                optional<shared_ptr<DFAState>> newState = FindState(allDfaStates, epsilonClosure);

                // If no DFA state containing the states reachable by this character exists, create a new one with said states
                if (!newState.has_value()) {
                    newState = make_shared<DFAState>(epsilonClosure);
                    allDfaStates.insert(newState.value());
                    unprocessedStates.push(newState.value());
                }

                currentState->AddTransition(character, newState.value());
            }
        }

        return dfa;
    }
}