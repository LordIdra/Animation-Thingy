#include "Errors.hpp"

#include "Colors.hpp"

#include <iostream>
#include <stdexcept>
#include <string>



namespace Errors {
    namespace {
        vector<Error> errors;

        auto Prefix(const ErrorLevel level, const string &path) -> string {
            string prefix;

            if (level == ERROR) { prefix.append(Colors::BRIGHT_RED + Colors::BOLD + "err "); }
            if (level == WARNING) { prefix.append(Colors::BRIGHT_YELLOW + Colors::BOLD + "warn "); }

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
}