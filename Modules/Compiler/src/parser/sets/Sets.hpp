#pragma once

#include "language/Language.hpp"
#include "scanner/Scanner.hpp"
#include <Types.hpp>

using language::SymbolType;
using language::ProductionRight;
using language::ProductionPair;



namespace sets {
    auto AddEmptyNonTerminalEntries(unordered_map<SymbolType, set<SymbolType>> &addTo) -> void;
    auto AddEmptyTerminalEntries(unordered_map<SymbolType, set<SymbolType>> &addTo) -> void;

    auto PopulateFirstTerminalEntries(unordered_map<SymbolType, set<SymbolType>> &addTo) -> void;

    auto IsSymbolTerminal(const SymbolType symbol) -> bool;

    auto RulesEqual(const ProductionPair  &v1, const ProductionPair &v2) -> bool;
}