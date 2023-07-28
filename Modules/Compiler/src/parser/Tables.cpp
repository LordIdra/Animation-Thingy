#include "Tables.hpp"
#include "language/Symbols.hpp"
#include "parser/sets/Follow.hpp"
#include "parser/sets/Sets.hpp"



namespace Tables {
    namespace {
        bool initialised = false;
       
        map<TableKey, shared_ptr<State>> gotoTable;
        map<TableKey, Action> actionTable;

        auto Initialise() -> void {
            const set<shared_ptr<State>> states = State::GetStates();
            for (const shared_ptr<State> &state : states) {
                for (const ProductionItem &item : state->GetItems()) {

                    // accept
                    if (item.left == language::PROGRAM && item.IsAtEnd()) {
                        actionTable.insert(make_pair(make_pair(state, item.left), 
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

    auto GetGoto(const shared_ptr<State> &state, const SymbolType symbolType) -> shared_ptr<State> {
        if (!initialised) {
            Initialise();
            initialised = true;
        }
        return gotoTable.at(make_pair(state, symbolType));
    }

    auto GetAction(const shared_ptr<State> &state, const SymbolType symbolType) -> Action {
        if (!initialised) {
            Initialise();
            initialised = true;
        }
        return actionTable.at(make_pair(state, symbolType));
    }
}