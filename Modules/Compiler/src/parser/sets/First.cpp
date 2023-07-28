#include "First.hpp"
#include "language/Language.hpp"
#include "language/Symbols.hpp"
#include "parser/sets/Sets.hpp"


namespace first {

    namespace {
        bool initialized = false;
        unordered_map<SymbolType, set<SymbolType>> firstSet = unordered_map<SymbolType, set<SymbolType>>();

        auto AddInternalFirstSet(set<SymbolType> &addTo, const SymbolType nonTerminal) -> void {
            set<SymbolType> firstSetForNonTerminal = firstSet.at(nonTerminal);
            for (const SymbolType y : firstSetForNonTerminal) {
                if (addTo.count(y) == 0) {
                    if (y != 0) {
                        addTo.insert(y);
                    }
                }
            }
        }

        namespace AddUnexpandedSymbols {

            auto AddProductionRightToFirstSetRight(const ProductionRight &productionRight, set<SymbolType> &firstSetRight) -> void {
                // Does not add duplicate entries
                if (firstSetRight.count(productionRight[0]) == 0) {
                    firstSetRight.insert(productionRight[0]);
                }
            }

            auto AddUnexpandedSymbols() -> void {
                for (const auto &pair : language::nonTerminalProductions) {
                    for (const ProductionRight &productionRight : pair.second) {
                        AddProductionRightToFirstSetRight(productionRight, firstSet[pair.first]);
                    }
                }
            }
        }

        namespace ExpandFirstSets { 
            auto ContainsFirstSetOfNonTerminal(set<SymbolType> &symbols, const SymbolType nonTerminal) -> bool {
                // Check if terminalsAndNonTerminals contains all characters in FIRST(nonTerminal)
                for (const SymbolType newSymbol : firstSet.at(nonTerminal)) {
                    if (symbols.count(newSymbol) == 0) {
                        return false;
                    }
                }
                return true;
            }
            
            auto ExpandFirstSetsOneIteration(bool &setChanged, set<SymbolType> &symbols) -> void {
                // Expand all the nested first sets in the given non-terminal set
                set<SymbolType> newSymbols;
                for (const SymbolType symbol : symbols) {

                    // If current symbol is a terminal
                    if (sets::IsSymbolTerminal(symbol)) {
                        newSymbols.insert(symbol);

                    // If current symbol is a non-terminal
                    } else {
                        
                        // Add the first set corresponding to the non-terminal
                        if (!ContainsFirstSetOfNonTerminal(symbols, symbol)) {
                            AddInternalFirstSet(newSymbols, symbol);
                            setChanged = true;
                        }
                    }
                }
                symbols = newSymbols;
            }

            auto ExpandFirstSets() -> void {
                bool setChanged = true;
                while (setChanged) {
                    
                    setChanged = false;
                    for (auto x : firstSet) {
                        std::cout << language::ToString(x.first) << " -> ";
                        for (auto y : x.second) {
                            std::cout << language::ToString(y) << " ";
                        }
                        std::cout << "\n";
                    }
                    for (auto &pair : firstSet) {
                        ExpandFirstSetsOneIteration(setChanged, pair.second);
                    }
                }
            }
        }
    }

    auto GetFirstSet() -> unordered_map<SymbolType, set<SymbolType>>& {
        if (!initialized) {
            sets::AddEmptyNonTerminalEntries(firstSet);
            sets::AddEmptyTerminalEntries(firstSet);
            AddUnexpandedSymbols::AddUnexpandedSymbols();
            ExpandFirstSets::ExpandFirstSets();
            sets::PopulateFirstTerminalEntries(firstSet);
            initialized = true;
        }

        return firstSet;
    }

    auto AddFirstSet(set<SymbolType> &addTo, const SymbolType nonTerminal) -> void {
            set<SymbolType> firstSetForNonTerminal = GetFirstSet().at(nonTerminal);
            for (const SymbolType y : firstSetForNonTerminal) {
                if (addTo.count(y) == 0) {
                    if (y != 0) {
                        addTo.insert(y);
                    }
                }
            }
        }

    auto AddFirstSet(vector<SymbolType> &addTo, const SymbolType nonTerminal) -> void {
        set<SymbolType> firstSetForNonTerminal = GetFirstSet().at(nonTerminal);
        for (const SymbolType y : firstSetForNonTerminal) {
            if (find(addTo.begin(), addTo.end(), y) == addTo.end()) {
                if (y != 0) {
                    addTo.push_back(y);
                }
            }
        }
    }
}