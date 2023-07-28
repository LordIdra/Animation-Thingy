#include "DFAState.hpp"


namespace scanner {
    DFAState::DFAState(const set<shared_ptr<NFAState>> &states) {
        this->states = states;
        this->accepting = false;
        for (const shared_ptr<NFAState> &state : states) {
            if (state->IsAccepting()) {
                accepting = true;
            }
        }
    }

    auto DFAState::AddTransition(const char character, const shared_ptr<DFAState> &state) -> void {
        transitions.insert(make_pair(character, state));
    }

    auto DFAState::HasTransition(const char character) const -> bool {
        return transitions.contains(character);
    }

    auto DFAState::GetTransition(const char character) -> shared_ptr<DFAState> {
        return transitions.at(character);
    }
    
    auto DFAState::GetTransitions() -> unordered_map<char, shared_ptr<DFAState>> {
        return transitions;
    }

    auto DFAState::GetNfaStates() -> set<shared_ptr<NFAState>> {
        return states;
    }

    auto DFAState::IsAccepting() const -> bool {
        return accepting;
    }
}