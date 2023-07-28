#include "OldParser.hpp"
#include "language/Language.hpp"
#include "language/Symbols.hpp"
#include "parser/sets/Sets.hpp"

using language::ProductionRight;
using language::ProductionList;
using language::ProductionPair;

typedef pair<ProductionPair, int> ProductionLocationPair;


namespace parser {
    namespace {
        struct State {
            set<ProductionLocationPair> productionList;
            map<SymbolType, shared_ptr<State>> transitions;
        };

        bool initialized = false;
        set<shared_ptr<State>> processedStates;
        set<shared_ptr<State>> states;

        auto GetState(const set<ProductionLocationPair> &productionList) -> optional<shared_ptr<State>> {
            for (shared_ptr<State> state : states) {
                if (state->productionList == productionList) {
                    return state;
                }
            }
            return {};
        }

        auto ExpandClosure(set<ProductionLocationPair> &productionList) -> void {
            // Expand all non-terminals to right of dot until no new productions are added
            bool hasChanged = true;
            while (hasChanged) {
                hasChanged = false;
                set<ProductionLocationPair> newProductions;
                for (const ProductionLocationPair &productionLocationPair : productionList) {
                    // If we're already at the end of the production, no need to proceed
                    if (productionLocationPair.first.second.size() == productionLocationPair.second) {
                        continue;
                    }

                    const SymbolType nextSymbolType = productionLocationPair.first.second.at(productionLocationPair.second);

                    // Only proceed if symbol is non-terminal
                    if (sets::IsSymbolTerminal(nextSymbolType)) {
                        continue;
                    }

                    // Add all productions with LHS of the symbol type
                    for (const ProductionRight &productionRight : language::nonTerminalProductions.at(nextSymbolType)) {
                        newProductions.insert(make_pair(make_pair(nextSymbolType, productionRight), 0));
                    }
                }

                // Add our new productions to the list
                for (pair<ProductionPair, int> productionPair : newProductions) {
                    if (!productionList.contains(productionPair)) {
                        productionList.insert(productionPair);
                        hasChanged = true;
                    }
                }
            }
        }

        auto BuildNextStates(shared_ptr<State> &state) -> void {
            if (processedStates.contains(state)) {
                return;
            }
            processedStates.insert(state);
            
            // Build a new list containing all the productions that will exist in the next states
            set<ProductionLocationPair> newProductionList;
            for (const ProductionLocationPair &production : state->productionList) {
                
                // Don't push productions that we've reached the end of
                if (production.second == production.first.second.size()) {
                    continue;
                }

                newProductionList.insert(make_pair(production.first, production.second)); // todo increment locations
            }

            // Increment all the locations
            // I HATE THIS LANGUAGE SO MUCH PLEASE JUST LET ME UPDATE ELEMENTS IN A SET
            // AND IF I CAN'T, AT LEAST TELL ME WHY NOT AAAAAAAAAAAAAAAAAAAAAAA
            set<ProductionLocationPair> incrementedNewProductionList;
            for (const ProductionLocationPair &locationPair : newProductionList) {
                incrementedNewProductionList.insert(make_pair(locationPair.first, locationPair.second+1));
            }

            ExpandClosure(incrementedNewProductionList);

            // Find all the symbol types that will lead to new states
            set<SymbolType> symbolsToNextStates;
            for (const ProductionLocationPair &locationPair : incrementedNewProductionList) {
                symbolsToNextStates.insert(locationPair.first.second.at(locationPair.second));
            }

            // Split the productions up according to the symbol at the location ('after the dot')
            map<SymbolType, set<ProductionLocationPair>> newProductionListBySymbol;
            for (const SymbolType symbolType : symbolsToNextStates) {
                newProductionListBySymbol.insert(make_pair(symbolType, set<ProductionLocationPair>()));
            }
            for (const pair<ProductionPair, int> &locationPair : incrementedNewProductionList) {
                newProductionListBySymbol.at(locationPair.first.second.at(locationPair.second)).insert(locationPair);
            }

            // Build the new states and insert transitions
            for (const pair<SymbolType, set<ProductionLocationPair>> &productionPair : newProductionListBySymbol) {
                optional<shared_ptr<State>> newState = GetState(productionPair.second);

                // If no state corresponding to the production list exists, create a new one
                if (!newState.has_value()) {
                    newState = make_shared<State>(State{
                        .productionList = productionPair.second,
                        .transitions = {}});
                    states.insert(newState.value());
                }

                state->transitions.insert(make_pair(productionPair.first, newState.value()));
            }

            cout << "STATE " << state << "\n";
            for (auto x : state->productionList) {
                cout << " " << language::ToString(x.first.first) << " ->";
                for (auto y : x.first.second) {
                    cout << " " << language::ToString(y);
                }
                cout << " (" << x.second << ")" << "\n";
            }
            cout << "transitions to ";
            for (auto x : state->transitions) {
                cout << language::ToString(x.first) << " ";
            }
            std::cout << "\n\n";

            // Recursively build the next states
            for (pair<SymbolType, shared_ptr<State>> statePair : state->transitions) {
                BuildNextStates(statePair.second);
            }
        }

        auto BuildStates() -> void {
            shared_ptr<State> stateZero = make_shared<State> (State { .productionList = {}, .transitions = {} });
        }
    }

    auto Parse(const string &path, const vector<Line> &lines) -> shared_ptr<NonTerminal> {
        if (!initialized) {
            BuildStates();
            initialized = true;
        }

        shared_ptr<NonTerminal> root = make_shared<NonTerminal>(NonTerminal(language::PROGRAM, nullptr, {}));
        return root;
    }
}