#pragma once

#include "Types.hpp"
#include "language/Language.hpp"
#include "scanner/Scanner.hpp"

using scanner::Line;
using language::Symbol;
using language::Terminal;
using language::NonTerminal;


namespace parser {
    auto Parse(const string &path, const vector<Line> &lines) -> shared_ptr<NonTerminal>;
}