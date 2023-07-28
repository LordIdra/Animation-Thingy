#pragma once

#include "State.hpp"
#include "language/Language.hpp"
#include "language/Symbols.hpp"

typedef pair<shared_ptr<State>, SymbolType> TableKey;



namespace Tables {
    enum ActionType {
        SHIFT,
        REDUCE,
        ACCEPT
    };

    struct Action {
        ActionType type;
        shared_ptr<State> state;
        ProductionItem item;
    };

    auto GetGoto(const shared_ptr<State> &state, const SymbolType symbolType) -> shared_ptr<State>;
    auto GetAction(const shared_ptr<State> &state, const SymbolType symbolType) -> Action;
}