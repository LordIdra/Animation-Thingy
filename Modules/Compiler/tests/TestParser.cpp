#include "errors/Errors.hpp"
#include "files/ReadFile.hpp"
#include "language/Language.hpp"
#include "parser/sets/First.hpp"
#include "parser/sets/Follow.hpp"
#include "../src/parser/Parser.hpp"
#include "scanner/Scanner.hpp"
#include <catch2/catch_test_macros.hpp>
#include <memory>



TEST_CASE("TestParserFail1") {
    Errors::Reset();

    const vector<string> input = ReadFile::Read("../../../../Modules/Compiler/tests/resources/TestParserFail1.txt");
    const vector<scanner::Line> scannedInput = scanner::Scan("TestParserFail1", input);
    const shared_ptr<NonTerminal> parsedInput = parser::Parse("TestParserFail1", scannedInput);
    std::cout << "existence is pain" << "\n";
}