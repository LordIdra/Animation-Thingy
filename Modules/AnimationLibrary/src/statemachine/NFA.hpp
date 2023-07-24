#pragma once

#include "Types.hpp"
#include <unordered_map>


namespace statemachine {
    class NFA {
    private:
        NFAState nextFreeState = 0;
        NFAState previousState = 0;
        NFAState currentState = 0;
        unordered_map<NFAState, vector<pair<char, NFAState>>> transitions;
        unordered_map<NFAState, int> acceptingStates;

    public:
        static const char EPSILON = '\0';

        NFA();

        auto GetState() const -> NFAState;
        auto GetPreviousState() const -> int;
        auto GetEpsilonStates() const -> set<NFAState>;

        auto NewState() -> NFAState;
        auto NewTransition(const char character, const NFAState state) -> void;
        auto GetTransitions() -> vector<pair<char, NFAState>>;

        auto SetAcceptingState(const int token) -> void;
        auto IsAcceptingState() -> bool;
        auto GetAcceptingState() -> NFAState;

        auto Goto(const int state) -> void;
        auto GotoOrigin() -> void;
    };
}