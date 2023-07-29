#pragma once

#include "State.hpp"
#include "Types.hpp"
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

        inline auto Format() const -> string {
            string format;
            switch (type) {
                case Tables::ACCEPT: format += "ACCEPT"; break;
                case Tables::SHIFT: format += "SHIFT "; break;
                case Tables::REDUCE: format += "REDUCE " + ToString(item.left); break;
            }
            return format;
        }
    };

    auto GetActionTable() -> map<TableKey, Action>;
    auto GetGotoTable() -> map<TableKey, shared_ptr<State>>;
    auto GetGoto(const shared_ptr<State> &state, const SymbolType symbolType) -> shared_ptr<State>;
    auto GetAction(const shared_ptr<State> &state, const SymbolType symbolType) -> Action;
    auto HasAction(const shared_ptr<State> &state, const SymbolType symbolType) -> bool;
}