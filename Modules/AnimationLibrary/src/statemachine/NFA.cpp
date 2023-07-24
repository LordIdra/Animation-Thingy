#include "NFA.hpp"
#include "Types.hpp"
#include <algorithm>
#include <unordered_map>


namespace statemachine {
    NFA::NFA() {
        // Initialize state 0, the root
        NewState();
    }

    auto NFA::GetState() const -> NFAState {
        return currentState;
    }

    auto NFA::GetPreviousState() const -> NFAState {
        return previousState;
    }

    auto NFA::GetEpsilonStates() const -> set<NFAState> {
        set<NFAState> epsilonStates;
        for (pair<char, NFAState> transitions : transitions.at(currentState)) {
            if (transitions.first == EPSILON) {
                epsilonStates.insert(transitions.second);
            }
        }

        return epsilonStates;
    }

    // Does not transition to the new state, only creates it
    auto NFA::NewState() -> NFAState {
        nextFreeState++;
        transitions.insert(make_pair(nextFreeState-1, vector<pair<char, NFAState>>()));
        return nextFreeState-1;
    }

    auto NFA::NewTransition(const char character, const NFAState state) -> void {
        transitions.at(currentState).push_back(make_pair(character, state));
    }

    auto NFA::GetTransitions() -> vector<pair<char, NFAState>> {
        return transitions.at(currentState);
    }

    auto NFA::SetAcceptingState(const int token) -> void {
        acceptingStates.insert(make_pair(currentState, token));
    }

    auto NFA::IsAcceptingState() -> bool {
        return acceptingStates.contains(currentState);
    }

    auto NFA::GetAcceptingState() -> NFAState {
        return acceptingStates.at(currentState);
    }

    auto NFA::Goto(const NFAState state) -> void {
        previousState = currentState;
        currentState = state;
    }

    auto NFA::GotoOrigin() -> void {
        Goto(0);
    }
}