#include <catch2/catch_test_macros.hpp>
#include "Types.hpp"
#include "errors/Errors.hpp"
#include "files/ReadFile.hpp"


TEST_CASE("TestReadFail") {
    Errors::Reset();

    ReadFile::Read("../yooo.txt");

    REQUIRE(Errors::GetErrorCount() == 1);
}

TEST_CASE("TestReadSuccess") {
    Errors::Reset();

    const vector<string> expected = {
        "The Duckling is yellow and fluffy...",
        "...and goes",
        "",
        "quack quack quack",
    };

    const vector<string> actual = ReadFile::Read("../../../../Modules/Compiler/tests/resources/TestRead.txt");

    REQUIRE(Errors::GetErrorCount() == 0);
    REQUIRE(actual == expected);
}