#pragma once

#include "Types.hpp"
#include <string>


enum Terminal {
    INDENT,
    NEWLINE,
    COMMENT,


    OPEN_SQUARE_BRACKET,
    CLOSE_SQUARE_BRACKET,
    OPEN_ROUND_BRACKET,
    CLOSE_ROUND_BRACKET,

    OUTLINE,
    PUB,

    LINE,
    RECT,
    CIRCLE,
    TEXT,

    WIDTH,
    OPACITY,
    COLOR,
    STYLE,
    BOLD,

    BOOLEAN,
    INTEGER,
    DECIMAL,
    IDENTIFIER
};

const unordered_map<int, string> terminalRegex {
    {INDENT, "    "},
    {NEWLINE, "\n"},
    {COMMENT, "//"},


    {OPEN_SQUARE_BRACKET, "["},
    {CLOSE_SQUARE_BRACKET, "]"},
    {OPEN_ROUND_BRACKET, "("},
    {CLOSE_ROUND_BRACKET, ")"},

    {PUB, "pub"},
    {OUTLINE, "outline"},

    {LINE, "line"},
    {RECT, "rect"},
    {CIRCLE, "circle"},
    {TEXT, "text"},

    {WIDTH, "width"},
    {OPACITY, "opacity"},
    {COLOR, "color"},
    {STYLE, "style"},
    {BOLD, "bold"},

    {BOOLEAN, "true|false"},
    {INTEGER, "[numericCharacters][numericCharacters]*"},
    {DECIMAL, "[numericCharacters][numericCharacters]*.[numericCharacters][numericCharacters]*"},
    {IDENTIFIER, "[identifierCharacters1][identifierCharacters2]*"},
};