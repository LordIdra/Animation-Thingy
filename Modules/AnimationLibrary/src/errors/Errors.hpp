#pragma once

#include "Colors.hpp"



// https://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal
// https://en.wikipedia.org/wiki/ANSI_escape_code
namespace Errors {
    class FileNotFound : public std::runtime_error {
    public:
        FileNotFound(const string &path);
    };

    class DuplicateAcceptingState : public std::runtime_error {
    public:
        DuplicateAcceptingState(const int current, const int newState);
    };
}