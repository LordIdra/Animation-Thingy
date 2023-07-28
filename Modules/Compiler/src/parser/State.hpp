#pragma once

#include "language/Language.hpp"
#include "language/Symbols.hpp"
#include <memory>

using language::SymbolType;
using language::ProductionRight;
using language::ProductionList;
using language::ProductionPair;



struct ProductionItem {
    SymbolType left;
    vector<SymbolType> right;
    int position;
    vector<SymbolType> lookahead;

    auto GetCurrentSymbol() const -> SymbolType {
        return right.at(position);
    }

    auto GetNextSymbol() const -> SymbolType {
        return right.at(position+1);
    }

    auto IsAtEnd() const -> bool {
        return right.size() == position;
    }

    auto operator==(const ProductionItem &other) const -> bool {
        return left == other.left && right == other.right && position == other.position && lookahead == other.lookahead;
    }
};

class State {
private:
    vector<ProductionItem> items;
    map<SymbolType, shared_ptr<State>> transitions;
    static set<shared_ptr<State>> states;

    auto Increment() -> void;
    auto ExpandClosure() -> void;
    auto BuildNextStates() -> void;
    auto AddTransition(const SymbolType type, const shared_ptr<State> &state) -> void;
    auto StateAlreadyExists(const vector<ProductionItem> &productionList) -> optional<shared_ptr<State>>;

public:
    State();
    State(const vector<ProductionItem> &items);

    static auto BuildRoot() -> shared_ptr<State>;
    static auto GetStates() -> set<shared_ptr<State>>;

    auto GetItems() -> vector<ProductionItem>;
    auto GetTransition(const SymbolType symbolType) -> shared_ptr<State>;
};