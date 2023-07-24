#include "Errors.hpp"

#include "Colors.hpp"

#include <iostream>
#include <stdexcept>
#include <string>



namespace Errors {
    namespace {
        auto Prefix(const string &file, const int line) -> string {
            return Colors::YELLOW + "[" + file + " | line " + to_string(line) + "] ";
        }
    }

    FileNotFound::FileNotFound(const string &path) : std::runtime_error(
            Colors::RED + "File not found: " + Colors::WHITE + path + Colors::WHITE + "\n") {}

    DuplicateAcceptingState::DuplicateAcceptingState(const int current, const int newState) : std::runtime_error(
            Colors::RED + "Duplicate accepting state: " + 
            Colors::WHITE + "current state " + Colors::CYAN + to_string(current) + 
            Colors::WHITE + "new state" + Colors::CYAN + to_string(newState) + "\n") {}
}