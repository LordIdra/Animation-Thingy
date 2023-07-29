#include "Tables.hpp"
#include "errors/Errors.hpp"
#include "language/Symbols.hpp"
#include "parser/State.hpp"
#include "parser/sets/Follow.hpp"
#include "parser/sets/Sets.hpp"



namespace Tables {
    namespace {
        bool initialised = false;
       
        map<TableKey, shared_ptr<State>> gotoTable;
        map<TableKey, Action> actionTable;

        auto FormatState(const shared_ptr<State> &state) -> string {
            string formatted;
            for (const ProductionItem &item : state->GetItems()) {
                formatted += "    ";
                formatted += language::ToString(item.left);
                formatted += " ->";
                for (const SymbolType type : item.right) {
                    formatted += " " + language::ToString(type);
                }
                formatted += "\n";
            }
            formatted += "\n";
            return formatted;
        }

        auto AddAction(const shared_ptr<State> &state, const SymbolType symbolType, const Action &action) -> void {
            const auto key = make_pair(state, symbolType);
            if (!actionTable.contains(key)) {
                actionTable.insert(make_pair(key, action));
                return;
            }

            string error = "Duplicate action!\n";
            error += "  [State]\n";
            error += FormatState(state);
            error += "  [SymbolType]\n";
            error += "    " + language::ToString(symbolType);
            error += "  [Previous Action]\n";
            error += "    " + actionTable.at(key).Format() + "\n";
            error += "  [New Action]\n";
            error += "    " + action.Format() + "\n";
            Errors::InternalError(error);
        }

        auto Initialise() -> void {
            const set<shared_ptr<State>> states = State::GetStates();
            for (const shared_ptr<State> &state : states) {
                for (const ProductionItem &item : state->GetItems()) {

                    // accept
                    if (item.left == language::PROGRAM && !item.IsAtEnd() && item.GetCurrentSymbol() == language::END_OF_FILE) {
                        actionTable.insert(make_pair(make_pair(state, item.GetCurrentSymbol()), 
                        Action{.type = ACCEPT}));

                    // reduce
                    } else if (item.IsAtEnd()) {
                        for (SymbolType symbolType : item.lookahead) {
                            actionTable.insert(make_pair(
                                make_pair(state, symbolType), 
                                Action{.type = REDUCE, .item = item}));
                        }

                    // shift
                    } else if (sets::IsSymbolTerminal(item.GetCurrentSymbol())) {
                        actionTable.insert(make_pair(
                            make_pair(state, item.GetCurrentSymbol()), 
                            Action{.type = SHIFT, .state = state->GetTransition(item.GetCurrentSymbol())}));

                    // goto
                    } else {
                        gotoTable.insert(make_pair(
                            make_pair(state, item.GetCurrentSymbol()), 
                            state->GetTransition(item.GetCurrentSymbol())));
                    }
                }
            }
        }
    }

    auto GetActionTable() -> map<TableKey, Action> {
        if (!initialised) {
            Initialise();
            initialised = true;
        }
        return actionTable;
    }

    auto GetGotoTable() -> map<TableKey, shared_ptr<State>> {
        if (!initialised) {
            Initialise();
            initialised = true;
        }
        return gotoTable;
    }

    auto GetGoto(const shared_ptr<State> &state, const SymbolType symbolType) -> shared_ptr<State> {
        return GetGotoTable().at(make_pair(state, symbolType));
    }

    auto GetAction(const shared_ptr<State> &state, const SymbolType symbolType) -> Action {
        return GetActionTable().at(make_pair(state, symbolType));
    }

    auto HasAction(const shared_ptr<State> &state, const SymbolType symbolType) -> bool {
        return GetActionTable().contains(make_pair(state, symbolType));
    }
}