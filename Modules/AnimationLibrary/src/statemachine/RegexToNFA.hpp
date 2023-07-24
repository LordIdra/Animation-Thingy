#pragma once

#include "Types.hpp"
#include "NFA.hpp"


namespace statemachine {
    auto BuildNFA(const unordered_map<int, string> &terminalRegexes) -> NFA;
}   