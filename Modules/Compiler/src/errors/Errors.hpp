#pragma once

#include "Colors.hpp"
#include "language/Language.hpp"
#include "language/Symbols.hpp"



// https://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal
// https://en.wikipedia.org/wiki/ANSI_escape_code
namespace Errors {
    enum ErrorLevel {
        INTERNAL,
        ERROR,
        WARNING
    };

    enum ErrorType {
        INTERNAL_ERROR,
        FILE_NOT_FOUND,
        UNRECOGNIZED_SYMBOL,
        INVALID_SYNTAX
    };

    struct Error {
        const ErrorLevel level;
        const ErrorType type;
        const string path;
        const int line;
        const string message;
    };

    auto Reset() -> void;
    auto PrintErrors() -> void;
    auto GetErrorCount() -> int;

    auto InternalError(const string &message) -> void;
    auto FileNotFound(const string &path) -> void;
    auto UnrecognizedSymbol(const string &path, const int line, const string &token) -> void;
    auto InvalidSyntax(const string &path, const int line, const language::Terminal &actual) -> void;
}