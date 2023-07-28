#pragma once

#include "Types.hpp"
#include "scanner/DFA/DFAState.hpp"
#include "scanner/NFA/NFAState.hpp"
#include <memory>
#include <unordered_map>


namespace scanner {
    class DFAState {
    private:
        set<shared_ptr<NFAState>> states;
        unordered_map<char, shared_ptr<DFAState>> transitions;
        bool accepting;

    public:
        DFAState(const set<shared_ptr<NFAState>> &states);
        
        auto AddTransition(const char character, const shared_ptr<DFAState> &state) -> void;
        auto HasTransition(const char character) const -> bool;
        auto GetTransition(const char character) -> shared_ptr<DFAState>;
        auto GetTransitions() -> unordered_map<char, shared_ptr<DFAState>>;
        auto GetNfaStates() -> set<shared_ptr<NFAState>>;
        auto IsAccepting() const -> bool;
    };
}