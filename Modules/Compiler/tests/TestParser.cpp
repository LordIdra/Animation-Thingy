#include "errors/Errors.hpp"
#include "files/ReadFile.hpp"
#include "language/Language.hpp"
#include "parser/sets/First.hpp"
#include "parser/sets/Follow.hpp"
#include "../src/parser/Parser.hpp"
#include "scanner/Scanner.hpp"
#include <cassert>
#include <catch2/catch_test_macros.hpp>
#include <memory>



TEST_CASE("TestParserFail1") {
    Errors::Reset();

    const vector<string> input = ReadFile::Read("../../../../Modules/Compiler/tests/resources/TestParserFail1.txt");
    REQUIRE(Errors::GetErrorCount() == 0);
    const vector<scanner::Line> scannedInput = scanner::Scan("TestParserFail1", input);
    REQUIRE(Errors::GetErrorCount() == 0);
    const shared_ptr<NonTerminal> parsedInput = parser::Parse("TestParserFail1", scannedInput);
    REQUIRE(Errors::GetErrorCount() == 1);
}

TEST_CASE("TestParserFail2") {
    Errors::Reset();

    const vector<string> input = ReadFile::Read("../../../../Modules/Compiler/tests/resources/TestParserFail2.txt");
    REQUIRE(Errors::GetErrorCount() == 0);
    const vector<scanner::Line> scannedInput = scanner::Scan("TestParserFail2", input);
    REQUIRE(Errors::GetErrorCount() == 0);
    const shared_ptr<NonTerminal> parsedInput = parser::Parse("TestParserFail2", scannedInput);
    REQUIRE(Errors::GetErrorCount() == 1);
}

TEST_CASE("TestParserSuccessPrimitives") {
    Errors::Reset();

    const vector<string> input = ReadFile::Read("../../../../Modules/Compiler/tests/resources/LAN-WAN/primitives.apg");
    Errors::PrintErrors();
    REQUIRE(Errors::GetErrorCount() == 0);

    const vector<scanner::Line> scannedInput = scanner::Scan("TestParserSuccessPrimitives", input);
    Errors::PrintErrors();
    REQUIRE(Errors::GetErrorCount() == 0);

    const shared_ptr<NonTerminal> parsedInput = parser::Parse("TestParserSuccessPrimitives", scannedInput);
    Errors::PrintErrors();
    REQUIRE(Errors::GetErrorCount() == 0);
}

TEST_CASE("TestParserSuccessDevices") {
    Errors::Reset();

    const vector<string> input = ReadFile::Read("../../../../Modules/Compiler/tests/resources/LAN-WAN/devices.apg");
    Errors::PrintErrors();
    REQUIRE(Errors::GetErrorCount() == 0);

    const vector<scanner::Line> scannedInput = scanner::Scan("TestParserSuccessDevices", input);
    Errors::PrintErrors();
    REQUIRE(Errors::GetErrorCount() == 0);

    const shared_ptr<NonTerminal> parsedInput = parser::Parse("TestParserSuccessDevices", scannedInput);
    Errors::PrintErrors();
    REQUIRE(Errors::GetErrorCount() == 0);
}

TEST_CASE("TestParserSuccessMain") {
    Errors::Reset();

    const vector<string> input = ReadFile::Read("../../../../Modules/Compiler/tests/resources/LAN-WAN/main.apg");
    Errors::PrintErrors();
    REQUIRE(Errors::GetErrorCount() == 0);

    const vector<scanner::Line> scannedInput = scanner::Scan("TestParserSuccessMain", input);
    Errors::PrintErrors();
    REQUIRE(Errors::GetErrorCount() == 0);

    const shared_ptr<NonTerminal> parsedInput = parser::Parse("TestParserSuccessMain", scannedInput);
    Errors::PrintErrors();
    REQUIRE(Errors::GetErrorCount() == 0);
}