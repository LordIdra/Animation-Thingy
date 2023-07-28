#pragma once

#include "Types.hpp"
#include "DFAState.hpp"
#include "scanner/NFA/NFA.hpp"
#include "scanner/NFA/NFAState.hpp"
#include <memory>
#include <unordered_map>


namespace scanner {
    class DFA {
    private:
        shared_ptr<DFAState> initialState;
        shared_ptr<DFAState> currentState;

        static auto GetStatesReachableByCharacter(const shared_ptr<DFAState> &state, const char &character) -> set<shared_ptr<NFAState>>;
        static auto FindState(const set<shared_ptr<DFAState>> &allDfaStates, const set<shared_ptr<NFAState>> &nfaStates) -> optional<shared_ptr<DFAState>>;

    public:
        DFA(const set<shared_ptr<NFAState>> &states);

        auto GetInitialState() const -> shared_ptr<DFAState>;
        auto CanTraverse(const char &character) const -> bool;
        auto Traverse(const char &character) -> void;
        auto IsAtAcceptingState() const -> bool;

        static auto FromNFA(const NFA &nfa) -> DFA;
    };
}