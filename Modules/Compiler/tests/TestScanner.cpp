#include <catch2/catch_message.hpp>
#include <catch2/catch_test_macros.hpp>
#include "Types.hpp"
#include "errors/Errors.hpp"
#include "files/ReadFile.hpp"
#include "../src/language/Language.hpp"
#include "language/Symbols.hpp"
#include "scanner/Scanner.hpp"

using namespace language;
using namespace scanner;


TEST_CASE("TestScannerFail") {
    Errors::Reset();

    const vector<string> input = ReadFile::Read("../../../../Modules/Compiler/tests/resources/TestScannerFail.txt");
    REQUIRE(Errors::GetErrorCount() == 0);

    const vector<Line> expectedOutput = {
        Line{.number = 1, .indentationLevel = 0,
            .terminals = { 
                Terminal{PUB, "pub"}, Terminal{NEWLINE, ""} }},

        Line{.number = 2, .indentationLevel = 0,
            .terminals = { 
                Terminal{PUB, "pub"}, Terminal{NEWLINE, ""} }},

        Line{.number = 3, .indentationLevel = 1,
            .terminals = { 
                Terminal{INDENT_PLUS, ""}, Terminal{IDENTIFIER, "yoo5"}, Terminal{NEWLINE, ""}, Terminal{INDENT_MINUS, ""}, Terminal{END_OF_FILE, ""} }},
    };

    const vector<Line> actualOutput = scanner::Scan("test", input);

    for (int i = 0; i < actualOutput.size(); i++) {
        REQUIRE(expectedOutput.at(i) == actualOutput.at(i));
    }

    REQUIRE(Errors::GetErrorCount() == 3);
}

TEST_CASE("TestScannerSuccess") {
    Errors::Reset();

    const vector<string> input = ReadFile::Read("../../../../Modules/Compiler/tests/resources/TestScannerSuccess.txt");
    Errors::PrintErrors();
    REQUIRE(Errors::GetErrorCount() == 0);

    const vector<Line> expectedOutput = {
        //Line{.number = 1, .indentationLevel = 0,
        //    .terminals = {Terminal{NEWLINE, ""}}},

        Line{.number = 2, .indentationLevel = 0,
            .terminals = { 
                Terminal{CLOSE_SQUARE_BRACKET, "]"}, 
                Terminal{OPEN_SQUARE_BRACKET, "["},
                Terminal{OPEN_ROUND_BRACKET, "("}, 
                Terminal{DOT, "."}, 
                Terminal{CLOSE_ROUND_BRACKET, ")" },
                Terminal{NEWLINE, ""}}},

        Line{.number = 3, .indentationLevel = 1,
            .terminals = { 
                Terminal{INDENT_PLUS, ""}, 
                Terminal{PUB, "pub"}, 
                Terminal{TYPE_LINE, "line"}, 
                Terminal{TYPE_RECT, "rect"}, 
                Terminal{TYPE_CIRCLE, "circle"}, 
                Terminal{TYPE_TEXT, "text"},
                Terminal{NEWLINE, ""}}},

        Line{.number = 4, .indentationLevel = 1, 
            .terminals = { 
                Terminal{LITERAL_STRING, "\"this is a string\""}, 
                Terminal{LITERAL_STRING, "\"\""},
                Terminal{TYPE_STRING, "string"}, 
                Terminal{TYPE_BOOL, "bool"},
                Terminal{NEWLINE, ""}}},

        Line{.number = 5, .indentationLevel = 2,
            .terminals = { 
                Terminal{INDENT_PLUS, ""}, 
                Terminal{LITERAL_BOOL, "true"}, 
                Terminal{LITERAL_BOOL, "false"},
                Terminal{NEWLINE, ""}}},

        Line{.number = 6, .indentationLevel = 1,
            .terminals = {Terminal{INDENT_MINUS, ""}, Terminal{IDENTIFIER, "hi"}, Terminal{NEWLINE, ""}}},

        Line{.number = 8, .indentationLevel = 0,
            .terminals = { 
                Terminal{INDENT_MINUS, ""},
                Terminal{LITERAL_INT, "0"}, 
                Terminal{LITERAL_FLOAT, "0.4"},
                Terminal{DOT, "."} ,
                Terminal{LITERAL_INT, "5"}, 
                Terminal{LITERAL_FLOAT, "50.3"}, 
                Terminal{LITERAL_FLOAT, "-23.8"}, 
                Terminal{LITERAL_INT, "-5"},
                Terminal{NEWLINE, ""}}},

        Line{.number = 9, .indentationLevel = 0,
            .terminals = { 
                Terminal{IDENTIFIER, "hello"}, 
                Terminal{IDENTIFIER, "h3ll0"}, 
                Terminal{IDENTIFIER, "HELo"}, 
                Terminal{IDENTIFIER, "h3LO"}, 
                Terminal{IDENTIFIER, "pubidentifier"}, 
                Terminal{IDENTIFIER, "notacircle"},
                Terminal{NEWLINE, ""},
                Terminal{END_OF_FILE, ""}}}};

    const vector<Line> actualOutput = scanner::Scan("TestScannerSuccess", input);

    Errors::PrintErrors();
    REQUIRE(Errors::GetErrorCount() == 0);

    for (int i = 0; i < actualOutput.size(); i++) {
        REQUIRE(expectedOutput.at(i) == actualOutput.at(i));
    }
}