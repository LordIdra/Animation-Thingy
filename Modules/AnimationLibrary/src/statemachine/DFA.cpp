#include "DFA.hpp"
#include "Types.hpp"
#include <algorithm>
#include <unordered_map>


namespace statemachine {
    DFA::DFA() {}

    auto DFA::Traverse(const char character) -> void {
        Goto(transitions.at(currentState).at(character));
    }

    auto DFA::GetState() -> DFAState {
        return currentState;
    }

    auto DFA::GetPreviousState() -> DFAState {
        return previousState;
    }

    auto DFA::HasState(const set<int> &nfaStatesIn) -> bool {
        return existingNfaStates.contains(nfaStatesIn);
    }

    auto DFA::GetNFAStates() -> set<int> {
        return nfaStates.at(currentState);
    }

    // Does not transition to the new state, only creates it
    auto DFA::NewState(const set<int> &correspondingNFAStates) -> DFAState {
        nextFreeState++;
        transitions.insert(make_pair(nextFreeState-1, unordered_map<char, DFAState>()));
        existingNfaStates.insert(correspondingNFAStates);
        return nextFreeState-1;
    }

    auto DFA::NewTransition(const char character, const DFAState state) -> void {
        transitions.at(currentState).insert(make_pair(character, state));
    }

    auto DFA::SetAcceptingState(const int token) -> void {
        acceptingStates.insert(make_pair(currentState, token));
    }

    auto DFA::IsAcceptingState() -> bool {
        return acceptingStates.contains(currentState);
    }

    auto DFA::GetAcceptingState() -> int {
        return acceptingStates.at(currentState);
    }

    auto DFA::HasTransition(const char character) const -> bool {
        return transitions.at(currentState).contains(character);
    }

    auto DFA::Goto(const DFAState state) -> void {
        previousState = currentState;
        currentState = state;
    }
}