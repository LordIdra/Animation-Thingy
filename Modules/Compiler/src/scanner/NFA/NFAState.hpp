#pragma once

#include "Types.hpp"
#include <memory>


namespace scanner {
    class NFAState {
    private:
        unordered_map<char, shared_ptr<NFAState>> transitions;
        set<shared_ptr<NFAState>> epsilonStates;
        bool accepting;

    public:
        auto SetAccepting(const bool accepting) -> void;
        auto IsAccepting() const -> bool;
        auto AddTransition(const char character, const shared_ptr<NFAState> &state) -> void;
        auto AddEpsilonTransition(const shared_ptr<NFAState> &state) -> void;
        auto HasTransition(const char character) -> bool;
        auto GetTransitions() -> unordered_map<char, shared_ptr<NFAState>>;
        auto GetTransition(const char character) -> shared_ptr<NFAState>;
        auto GetEpsilonStates() -> set<shared_ptr<NFAState>>;
        static auto GetRecursiveEpsilonClosure(const set<shared_ptr<NFAState>> &states) -> set<shared_ptr<NFAState>>;
    };
}