#pragma once

#include "Colors.hpp"



// https://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal
// https://en.wikipedia.org/wiki/ANSI_escape_code
namespace Errors {
    enum ErrorLevel {
        ERROR,
        WARNING
    };

    enum ErrorType {
        FILE_NOT_FOUND,
        UNRECOGNIZED_SYMBOL
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
    auto FileNotFound(const string &path) -> void;
    auto UnrecognizedSymbol(const string &path, const int line, const string &token) -> void;
}