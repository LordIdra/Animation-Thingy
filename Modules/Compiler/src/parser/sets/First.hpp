#pragma once

#include "language/Language.hpp"

using language::SymbolType;


namespace first {
    auto GetFirstSet() -> unordered_map<SymbolType, set<SymbolType>>&;
    auto AddFirstSet(set<SymbolType> &addTo, const SymbolType nonTerminal) -> void;
    auto AddFirstSet(vector<SymbolType> &addTo, const SymbolType nonTerminal) -> void;
}