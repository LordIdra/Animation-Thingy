#pragma once

#include "errors/Errors.hpp"
#include "statemachine/DFA.hpp"
#include "statemachine/NFA.hpp"
#include <unordered_map>


namespace statemachine {
    namespace {
        // Returns the set of states reachable from the current state of the NFA via epsilon transitions
        // This will traverse the NFA and will *not* return to the initial state
        auto ComputeEpsilonClosure(NFA &nfa) -> set<int> {
            const int initialState = nfa.GetState();
            set<int> epsilonStates = nfa.GetEpsilonStates();
            set<int> recursiveEpsilonStates = set<int>();

            // Recursively compute all the states reachable via epsilon transitions from the states we just computed
            for (const int state : epsilonStates) {
                nfa.Goto(state);
                for (int recursiveState : ComputeEpsilonClosure(nfa)) {
                    recursiveEpsilonStates.insert(recursiveState);
                }
            }

            // Add the initial state itself, since this is included in 'zero or more epsilon transitions'
            epsilonStates.insert(initialState);

            // Concatenate the two state sets
            for (int state : recursiveEpsilonStates){
                epsilonStates.insert(state);
            }

            return epsilonStates;

        }
    }

    // Uses subset construction to convert a nondeterministic finite automaton to a deterministic one
    auto ConvertNFAToDFA(NFA &nfa) -> DFA {
        DFA dfa;
        queue<pair<int, set<int>>> stateWorkList;

        // Start at state 0
        stateWorkList.push(make_pair(dfa.GetState(), nfa.GetEpsilonStates()));

        while (!stateWorkList.empty()) {
            // Pop first value off work list and go to DFA work state
            const auto D = stateWorkList.front();
            stateWorkList.pop();
            dfa.Goto(D.first);

            // Find every transition from the NFA state contained in the DFA to any other NFA state via a character
            unordered_map<char, set<int>> transitions;
            for (const int nfaState : D.second) {
                nfa.Goto(nfaState);
                for (pair<char, int> nfaTransition : nfa.GetTransitions()) {
                    if (!transitions.contains(nfaTransition.first)) {
                        transitions.insert(make_pair(nfaTransition.first, set<int>()));
                    }
                    transitions.at(nfaTransition.first).insert(nfaTransition.second);
                }
            }

            // Find the epsilon closure of all those states we just found
            unordered_map<char, set<int>> newTransitions;
            for (const pair<char, set<int>> transition : transitions) {
                set<int> newStates;
                // TODO insert only if 
                for (const int nfaState : transition.second) {
                    nfa.Goto(nfaState);
                    for (const int epsilonState : nfa.GetEpsilonStates()) {
                        newStates.insert(epsilonState);
                    }
                }
                newTransitions.insert(make_pair(transition.first, newStates));
            }

            // Create a new DFA state for every transition, containing the corresponding NFA states
            for (pair<char, set<int>> transition : transitions) {
                dfa.NewTransition(transition.first, dfa.NewState(transition.second));
            }
        }

        return dfa;
    }
}