#include <catch2/catch_test_macros.hpp>
#include "Types.hpp"
#include "errors/Errors.hpp"
#include "readfile/ReadFile.hpp"


TEST_CASE("TestRead1") {
    try {
        ReadFile::Read("../yooo.txt");
    } catch (const Errors::FileNotFound &_) {
        REQUIRE(true);
        return;
    }

    REQUIRE(false);
}

TEST_CASE("TestRead2") {
    const vector<string> expected = {
        "The Duckling is yellow and fluffy...",
        "...and goes",
        "",
        "quack quack quack",
    };

    const vector<string> actual = ReadFile::Read("../../../../Modules/AnimationLibrary/tests/resources/TestRead.txt");

    REQUIRE(actual == expected);
}