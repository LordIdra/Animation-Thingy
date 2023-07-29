#include "language/Language.hpp"
#include "Follow.hpp"
#include "parser/sets/First.hpp"
#include "parser/sets/Sets.hpp"

#include <iostream>

using language::ProductionRight;


namespace follow {
    namespace {
        bool initialized = false;

        unordered_map<SymbolType, set<SymbolType>> followSet;

        auto AddFollowSet(set<SymbolType> &addTo, const SymbolType terminalOrNonTerminal) -> void {
                set<SymbolType> followSetForNonTerminal = followSet.at(terminalOrNonTerminal);
                for (const SymbolType x : followSetForNonTerminal) {
                    if ((addTo.count(x)) == 0) {
                        addTo.insert(x);
                    }
                }
            }

        namespace AddUnexpandedSymbols {
            auto ProcessPoduction_NextSymbolExists(const SymbolType productionLeft, const ProductionRight &productionRight, int i) -> void {
                // Add FIRST(b) to FOLLOW(a)
                const SymbolType originalSymbol = productionRight.at(i);
                const SymbolType nextSymbol = productionRight.at(i+1);
                first::AddFirstSet(followSet.at(originalSymbol), nextSymbol);
            }

            auto ProcessProduction_EndOfNonTerminal(const SymbolType productionLeft, const SymbolType currentSymbol) -> void {
                // Add FOLLOW(A)
                followSet.at(currentSymbol).insert(productionLeft);
            }

            auto ProcessProduction(const SymbolType productionLeft, const ProductionRight &productionRight) -> void {
                for (int i = 0; i < productionRight.size(); i++) {

                    // If x -> ...ab...
                    if (i+1 < productionRight.size()) {
                        ProcessPoduction_NextSymbolExists(productionLeft, productionRight, i);
                    }

                    // If A -> ...a
                    else if (i+1 == productionRight.size()) {
                        const SymbolType currentSymbol = productionRight.at(i);
                        ProcessProduction_EndOfNonTerminal(productionLeft, currentSymbol);
                    }
                }
            }

            auto AddUnexpandedSymbols() -> void {
                for (const auto &pair : language::nonTerminalProductions) {
                    for (const ProductionRight &production : pair.second) {
                        ProcessProduction(pair.first, production);
                    }
                }
            }
        }

        namespace ExpandFollowSets { 
            auto ContainsFollowSetOfNonTerminal(set<SymbolType> &symbols, const SymbolType nonTerminal) -> bool {
                // Check if terminalsAndNonTerminals contains all characters in FOLLOW(nonTerminal)
                for (const SymbolType newSymbol : followSet.at(nonTerminal)) {
                    if (symbols.count(newSymbol) == 0) {
                        return false;
                    }
                }
                return true;
            }

            auto ExpandFollowSetsOneIteration(bool &setChanged, set<SymbolType> &symbols) -> void {
                // Expand all the nested follow sets in the given non-terminal set
                set<SymbolType> newSymbols;
                for (const SymbolType symbol : symbols) {

                    // If current symbol is a terminal
                    if (sets::IsSymbolTerminal(symbol)) {
                        newSymbols.insert(symbol);

                    // If current symbol is a non-terminal
                    } else {

                        // Add the follow set corresponding to the non-terminal
                        if (!ContainsFollowSetOfNonTerminal(symbols, symbol)) {
                            AddFollowSet(newSymbols, symbol);
                            setChanged = true;
                        }
                    }
                }
                symbols = newSymbols;
            }

            auto ExpandFollowSets() -> void {
                bool setChanged = true;
                while (setChanged) {
                    setChanged = false;
                    for (auto &pair : followSet) {
                        ExpandFollowSetsOneIteration(setChanged, pair.second);
                    }
                }
            }
        }
    }

    auto GetFollowSet() -> unordered_map<SymbolType, set<SymbolType>>& {
        if (!initialized) {
            sets::AddEmptyTerminalEntries(followSet);
            sets::AddEmptyNonTerminalEntries(followSet);
            AddUnexpandedSymbols::AddUnexpandedSymbols();
            ExpandFollowSets::ExpandFollowSets();
            initialized = true;
        }

        return followSet;
    }
}