#include "Errors.hpp"

#include "Colors.hpp"
#include "language/Language.hpp"
#include "language/Symbols.hpp"

#include <iostream>
#include <stdexcept>
#include <string>

using language::Terminal;
using language::ToString;



namespace Errors {
    namespace {
        vector<Error> errors;

        auto Prefix(const ErrorLevel level) -> string {
            string prefix;
            if (level == INTERNAL) { prefix.append(Colors::BRIGHT_RED + Colors::BOLD + "[!] internal [!] "); }
            if (level == ERROR) { prefix.append(Colors::BRIGHT_RED + Colors::BOLD + "err "); }
            if (level == WARNING) { prefix.append(Colors::BRIGHT_YELLOW + Colors::BOLD + "warn "); }
            return prefix;
        }

        auto Prefix(const ErrorLevel level, const string &path) -> string {
            string prefix = Prefix(level);
            prefix.append(Colors::BRIGHT_BLUE + path  + Colors::RESET);
            return prefix;
        }

        auto Prefix(const ErrorLevel level, const string &path, const int line) -> string {
            return Prefix(level, path) + Colors::BRIGHT_BLUE + Colors::BOLD + ":" + to_string(line) + Colors::RESET;
        }
    }

    auto Reset() -> void {
        errors.clear();
    }

    auto PrintErrors() -> void {
        for (const Error &error : errors) {
            std::cout << error.message;
        }
    }

    auto GetErrorCount() -> int {
        return errors.size();
    }

    auto InternalError(const string &message) -> void {
        errors.push_back(Error {
            .level = INTERNAL, .type = INTERNAL_ERROR, .path = "", .line = -1,
            .message = Prefix(INTERNAL) + message + "\n"});
    }

    auto FileNotFound(const string &path) -> void {
        errors.push_back(Error {
            .level = ERROR, .type = FILE_NOT_FOUND, .path = path, .line = -1,
            .message = Prefix(ERROR, path) + " file not found" + "\n"});
    }

    auto UnrecognizedSymbol(const string &path, const int line, const string &token) -> void {
        errors.push_back(Error {
            .level = ERROR, .type = UNRECOGNIZED_SYMBOL, .path = path, .line = line,
            .message = Prefix(ERROR, path, line) + " unrecognized symbol '" + token + "'" + "\n"});
    }

    auto InvalidSyntax(const string &path, const int line, const Terminal &actual) -> void {
        errors.push_back(Error {
            .level = ERROR, .type = UNRECOGNIZED_SYMBOL, .path = path, .line = line,
            .message = Prefix(ERROR, path, line) 
                + " invalid syntax: unexpected " + ToString(actual.type)
                + ((actual.text == "" || actual.text == ToString(actual.type)) ? "" : (" '" + actual.text + "'")) + "\n"});
    }
}