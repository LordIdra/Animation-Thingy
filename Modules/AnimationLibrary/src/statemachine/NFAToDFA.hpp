#pragma once

#include "statemachine/DFA.hpp"
#include "statemachine/NFA.hpp"


namespace statemachine {
    auto ConvertNFAToDFA(const NFA &nfa) -> DFA;
}