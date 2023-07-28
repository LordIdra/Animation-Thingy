#include "../NFA/NFAState.hpp"
#include <memory>


namespace scanner {
    auto NFAState::SetAccepting(const bool accepting) -> void {
        this->accepting = accepting;
    }

    auto NFAState::IsAccepting() const -> bool {
        return accepting;
    }

    auto NFAState::AddTransition(const char character, const shared_ptr<NFAState> &state) -> void {
        transitions.insert(make_pair(character, state));
    }

    auto NFAState::AddEpsilonTransition(const shared_ptr<NFAState> &state) -> void {
        epsilonStates.insert(state);
    }

    auto NFAState::HasTransition(const char character) -> bool {
        return transitions.contains(character);
    }

    auto NFAState::GetTransitions() -> unordered_map<char, shared_ptr<NFAState>> {
        return transitions;
    }

    auto NFAState::GetTransition(const char character) -> shared_ptr<NFAState> {
        return transitions.at(character);
    }

    auto NFAState::GetEpsilonStates() -> set<shared_ptr<NFAState>> {
        return epsilonStates;
    }

    auto NFAState::GetRecursiveEpsilonClosure(const set<shared_ptr<NFAState>> &states) -> set<shared_ptr<NFAState>> {
        stack<shared_ptr<NFAState>> statesToTraverse;
        set<shared_ptr<NFAState>> epsilonClosure;

        for (shared_ptr<NFAState> state : states) {
            statesToTraverse.push(state);
            epsilonClosure.insert(state);
        }

        while (!statesToTraverse.empty()) {
            shared_ptr<NFAState> state = statesToTraverse.top();
            statesToTraverse.pop();
            for (shared_ptr<NFAState> epsilonState : state->GetEpsilonStates()) {
                if (!epsilonClosure.contains(epsilonState)) {
                    epsilonClosure.insert(epsilonState);
                    statesToTraverse.push(epsilonState);
                }
            }
        }
        return epsilonClosure;
    }
}