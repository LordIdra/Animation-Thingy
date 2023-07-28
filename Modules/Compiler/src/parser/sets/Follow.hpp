#pragma once

#include <Types.hpp>
#include <language/Language.hpp>

using language::SymbolType;


namespace follow {
    auto GetFollowSet() -> unordered_map<SymbolType, set<SymbolType>>&;
}