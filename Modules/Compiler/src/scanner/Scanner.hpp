#pragma once

#include "Types.hpp"
#include "../language/Language.hpp"

using language::SymbolType;
using language::Terminal;


namespace scanner {
    struct Line {
        const int number;
        const int indentationLevel;
        vector<Terminal> terminals;

        auto operator==(const Line &other) const -> bool {
            return number == other.number && indentationLevel == other.indentationLevel && terminals == other.terminals;
        }
    };

    ostream& operator<<(ostream& stream, const Line& line);
    auto Scan(const string &path, const vector<string> &lines) -> vector<Line>;
}