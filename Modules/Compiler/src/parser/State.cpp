#include "State.hpp"
#include "language/Symbols.hpp"
#include "parser/sets/First.hpp"
#include "parser/sets/Sets.hpp"
#include <vector>



set<shared_ptr<State>> State::states = set<shared_ptr<State>>();

auto State::Increment() -> void {
    // Increment the location of all items and remove items that we have fully traversed
    vector<ProductionItem> incrementedItems;
    for (const ProductionItem &item : items) {
        if (!item.IsAtEnd()) {
            incrementedItems.push_back(ProductionItem{
                .left = item.left,
                .right = item.right, 
                .position = item.position+1,
                .lookahead = item.lookahead});
        }
    }
    items = incrementedItems;
}

auto State::ExpandClosure() -> void {
    // Expand all non-terminals to right of dot until no new productions are added
    bool hasChanged = true;
    while (hasChanged) {
        hasChanged = false;
        vector<ProductionItem> newProductions;
        for (const ProductionItem &item : items) {

            // If we're already at the end of the production, don't try and expand the next symbol
            if (item.IsAtEnd()) {
                continue;
            }

            // Only proceed if next symbol is a non-terminal
            const SymbolType nextSymbolType = item.GetCurrentSymbol();
            if (sets::IsSymbolTerminal(nextSymbolType)) {
                continue;
            }

            // Add all productions with an LHS of nextSymbolType
            for (const ProductionRight &productionRight : language::nonTerminalProductions.at(nextSymbolType)) {
                vector<SymbolType> lookahead;
                if (item.position == item.right.size()-1) {
                    lookahead = item.lookahead;
                } else {
                    first::AddFirstSet(lookahead, nextSymbolType);
                }
                newProductions.push_back(ProductionItem{
                    .left = nextSymbolType, 
                    .right = productionRight, 
                    .position = 0,
                    .lookahead = lookahead});
            }
        }

        // Add our new productions to the items list
        for (ProductionItem item : newProductions) {
            bool itemAlreadyExists = false;
            for (const ProductionItem existingItem : items) {
                if (item == existingItem) {
                    itemAlreadyExists = true;
                    break;
                }
            }
            if (!itemAlreadyExists) {
                items.push_back(item);
                hasChanged = true;
            }
        }
    }
}

auto State::BuildNextStates() -> void {
    // Build a new list containing all the items that we are not at the end of yet
    vector<ProductionItem> unfinishedItems;
    for (const ProductionItem &item : items) {
        if (!item.IsAtEnd()) {
            unfinishedItems.push_back(item);
        }
    }

    // Each symbol on the left side of the items will be a transition to a new state
    set<SymbolType> nextSymbols;
    for (const ProductionItem &item : unfinishedItems) {
        nextSymbols.insert(item.GetCurrentSymbol());
    }

    // Find the productions that should be in each new state
    map<SymbolType, vector<ProductionItem>> newProductions;
    for (SymbolType symbol : nextSymbols) {
        newProductions.insert(make_pair(symbol, vector<ProductionItem>()));
    }
    for (const ProductionItem &item : unfinishedItems) {
        if (!item.IsAtEnd()) {
            newProductions.at(item.GetCurrentSymbol()).push_back(item);
        }
    }

    // Build the new states if they do not already exists
    set<shared_ptr<State>> newStates;
    for (const pair<SymbolType, vector<ProductionItem>> &pair : newProductions) {

        // Build the next state
        shared_ptr<State> newState = make_shared<State>(State(pair.second));
        newState->Increment();
        newState->ExpandClosure();

        // Check if the state already exists - if so, use the existing state
        optional<shared_ptr<State>> existingState = StateAlreadyExists(newState->items);
        if (!existingState.has_value()) {
            newStates.insert(newState);
            states.insert(newState);
        } else {
            newState = existingState.value();
        }

        AddTransition(pair.first, newState);
    }

    // DEBUG
    cout << "STATE " << "\n";
    for (auto x : items) {
        cout << " " << language::ToString(x.left) << " ->";
        for (auto y : x.right) {
            cout << " " << language::ToString(y);
        }
        cout << " (" << x.position << ")";
        cout << " {";
        for (auto y : x.lookahead) {
            cout << " " << language::ToString(y);
        }
        cout << "}\n";
    }
    cout << "transitions to ";
    for (auto x : transitions) {
        cout << language::ToString(x.first) << " ";
    }
    std::cout << "\n\n";

    // Initialise the newly created states
    for (const shared_ptr<State> &newState : newStates) {
        newState->BuildNextStates();
    }
}

auto State::AddTransition(const SymbolType type, const shared_ptr<State> &state) -> void {
    transitions.insert(make_pair(type, state));
}

auto State::StateAlreadyExists(const vector<ProductionItem> &productionList) -> optional<shared_ptr<State>> {
    for (shared_ptr<State> state : states) {
        if (state->items == productionList) {
            return state;
        }
    }
    return {};
}

State::State() {}

State::State(const vector<ProductionItem> &items) {
    this->items = items;
}

auto State::BuildRoot() -> shared_ptr<State> {
    shared_ptr<State> state = make_shared<State>();
    for (ProductionRight productionRight : language::nonTerminalProductions.at(language::PROGRAM)) {
        state->items.push_back(ProductionItem{
            .left = language::PROGRAM,
            .right = productionRight,
            .position = 0,
            .lookahead = {language::END_OF_FILE}});
    }
    states.insert(state);
    state->ExpandClosure();
    state->BuildNextStates();
    return state;
}

auto State::GetStates() -> set<shared_ptr<State>> {
    return states;
}

auto State::GetItems() -> vector<ProductionItem> {
    return items;
}

auto State::GetTransition(const SymbolType symbolType) -> shared_ptr<State> {
    return transitions.at(symbolType);
}