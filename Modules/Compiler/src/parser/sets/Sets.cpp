#include "Sets.hpp"
#include "language/Language.hpp"
#include "parser/sets/First.hpp"
#include "parser/sets/Follow.hpp"

using language::terminals;
using language::nonTerminals;


namespace sets {

    auto AddEmptyNonTerminalEntries(unordered_map<SymbolType, set<SymbolType>> &addTo) -> void {
        // Generate a set which consists of all non terminals mapped to empty vectors
        for (auto type : nonTerminals) {
            addTo.insert(make_pair(type.first, set<SymbolType>()));
        }
    }

    auto AddEmptyTerminalEntries(unordered_map<SymbolType, set<SymbolType>> &addTo) -> void {
        for (auto type : terminals) {
            addTo.insert(make_pair(type.first, set<SymbolType>()));
        }
    }

    auto PopulateFirstTerminalEntries(unordered_map<SymbolType, set<SymbolType>> &addTo) -> void {
        for (auto type : terminals) {
            addTo[type.first] = {type.first};
        }
    }
    
    auto IsSymbolTerminal(const SymbolType symbol) -> bool {
        return terminals.contains(symbol);
    }

    auto RulesEqual(const ProductionPair &v1, const ProductionPair &v2) -> bool {
        if (v1.first != v2.first) {
            return false;
        }
        
        if (v1.second.size() != v2.second.size()) {
            return false;
        }

        for (int i = 0; i < v1.second.size(); i++) {
            if (v1.second[i] != v2.second[i]) {
                return false;
            }
        }

        return true;
    }
}