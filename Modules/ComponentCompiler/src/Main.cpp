#include "language/Terminals.hpp"
#include "statemachine/RegexToNFA.hpp"
#include "../../AnimationLibrary/src/statemachine/NFA.hpp"


auto main() -> int {
    const NFA stateMachine = RegexToNFA::BuildNFA(terminalRegex);
}