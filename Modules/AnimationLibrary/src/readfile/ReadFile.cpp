#include "ReadFile.hpp"
#include "errors/Errors.hpp"
#include "Colors.hpp"
#include <fstream>
#include <iostream>

using std::ifstream;



namespace ReadFile {
    auto Read(const string &path) -> vector<string> {
        ifstream file(path);

        // Check the file exists
        if (!file) {
            throw Errors::FileNotFound(path);
        }

        // Read the file lines into a vector
        vector<string> lines;
        string currentLine;
        while (std::getline(file, currentLine)) {
            lines.push_back(currentLine);
        }

        return lines;
    }
}