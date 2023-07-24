#pragma once

#include "Types.hpp"
#include <unordered_map>


namespace statemachine {
    class DFA {
    private:
        NFAState nextFreeState = 0;
        DFAState previousState;
        DFAState currentState;
        unordered_map<DFAState, unordered_map<char, DFAState>> transitions;
        unordered_map<DFAState, int> acceptingStates;
        unordered_map<DFAState, set<int>> nfaStates;
        set<set<int>> existingNfaStates; // Acts as a cache so we don't have to search the values of nfaStates


    public:
        static const char EPSILON = '\0';

        DFA();

        auto Traverse(const char character) -> void;
        auto GetState() -> DFAState;
        auto GetPreviousState() -> DFAState;

        auto HasState(const set<int> &nfaStatesIn) -> bool;
        auto GetNFAStates() -> set<int>;

        auto NewState(const set<int> &correspondingNFAStates) -> DFAState;
        auto NewTransition(const char character, const DFAState state) -> void;
        auto HasTransition(const char character) const -> bool;

        auto SetAcceptingState(const int token) -> void;
        auto IsAcceptingState() -> bool;
        auto GetAcceptingState() -> int;

        auto Goto(const DFAState state) -> void;
        auto GotoOrigin() -> void;
    };
}