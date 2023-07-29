#pragma once

#include "Types.hpp"


namespace language {
    enum SymbolType {
        END_OF_FILE,
        WHITESPACE,
        NEWLINE,
        INDENT_PLUS,
        INDENT_MINUS,
        COMMENT,

        OPEN_SQUARE_BRACKET,
        CLOSE_SQUARE_BRACKET,
        OPEN_ROUND_BRACKET,
        CLOSE_ROUND_BRACKET,
        DOT,
        COMMA,
        COLON,
        ARROW,

        EXCLAMATION_MARK,
        AMPERSAND,
        VERTICAL_LINE,
        PLUS,
        MINUS,
        STAR,
        SLASH,
        PERCENT,

        DOUBLE_EQUALS,
        GREATER,
        LESS,
        GREATER_EQUALS,
        LESS_EQUALS,
        
        EQUALS,
        PLUS_EQUALS,
        DASH_EQUALS,
        STAR_EQUALS,
        SLASH_EQUALS,
        PERCENT_EQUALS,

        PUB,
        FUN,
        CLASS,
        USE,
        IMPORT,
        SETCENTER,
        VAR,
        CONST,
        RET,

        TYPE_LINE,
        TYPE_RECT,
        TYPE_CIRCLE,
        TYPE_TEXT,
        TYPE_BOOL,
        TYPE_INT,
        TYPE_FLOAT,
        TYPE_STRING,
        TYPE_COORD,
        TYPE_RGB,
        TYPE_LIST,

        LITERAL_BOOL,
        LITERAL_INT,
        LITERAL_FLOAT,
        LITERAL_STRING,
        LITERAL_LIST,
        
        IDENTIFIER,



        PROGRAM,
        GLOBAL_STATEMENT_SEQUENCE,

        GLOBAL_STATEMENT,
        IMPORT_STATEMENT,
        USE_STATEMENT,
        FUNCTION_DECLARATION,
        CLASS_DECLARATION,

        ASSIGNMENT,
        LOCAL_STATEMENT,
        VARIABLE_DECLARATION,
        ATTRIBUTE_DECLARATION,
        FUNCTION_CALL,
        PRIMITIVE_CALL,
        SETCENTER_CALL,

        FUNCTION_PREFIX,
        CLASS_PREFIX,
        RETURN_SUFFIX,
        ARGUMENT_LIST,
        PARAMETER_LIST,
        PARAMETER,
        RETURN_STATEMENT,

        FUNCTION_BLOCK_SEQUENCE,
        ATTRIBUTE_BLOCK_SEQUENCE,
        CLASS_BLOCK_SEQUENCE,
        FUNCTION_BLOCK,
        CLASS_BLOCK,
        
        DATATYPE,
        PRIMITIVE_DATATYPE,

        TERM_BOOL,
        TERM_NOT,
        TERM_AND,
        TERM_OR,
        TERM_LESS,
        TERM_LESS_EQUALS,
        TERM_GREATER,
        TERM_GREATER_EQUALS,

        NAMESPACED_IDENTIFIER,
        NAMESPACED_VALUE,
        LITERAL_LIST_SEQUENCE,
        LITERAL_COORD,
        LITERAL_RGB,
        LITERAL,
        VALUE
    };

    typedef vector<SymbolType> ProductionRight;
    typedef pair<SymbolType, vector<ProductionRight>> ProductionList;
    typedef pair<SymbolType, ProductionRight> ProductionPair;

    const map<SymbolType, string> terminals = {
        {END_OF_FILE, "end-of-file"},
        {WHITESPACE, "whitespace"},
        {NEWLINE, "newline"},
        {INDENT_PLUS, "indent"},
        {INDENT_MINUS, "backwards-indent"},
        {COMMENT, "comment"},

        {OPEN_SQUARE_BRACKET, "["},
        {CLOSE_SQUARE_BRACKET, "]"},
        {OPEN_ROUND_BRACKET, "("},
        {CLOSE_ROUND_BRACKET, ")"},
        {DOT, "."},
        {COMMA, ","},
        {COLON, ":"},
        {ARROW, "->"},

        {EXCLAMATION_MARK, "!"},
        {AMPERSAND, "&"},
        {VERTICAL_LINE, "|"},
        {PLUS, "+"},
        {MINUS, "-"},
        {STAR, "*"},
        {SLASH, "/"},
        {PERCENT, "%"},

        {DOUBLE_EQUALS, "=="},
        {GREATER, ">"},
        {LESS, "<"},
        {GREATER_EQUALS, ">="},
        {LESS_EQUALS, "=<"},

        {EQUALS, "="},
        {PLUS_EQUALS, "+="},
        {DASH_EQUALS, "-="},
        {STAR_EQUALS, "*="},
        {SLASH_EQUALS, "-="},
        {PERCENT_EQUALS, "%="},

        {PUB, "pub"},
        {FUN, "fun"},
        {CLASS, "class"},
        {USE, "use"},
        {IMPORT, "import"},
        {SETCENTER, "setcenter"},
        {VAR, "var"},
        {CONST, "const"},
        {RET, "ret"},

        {TYPE_LINE, "line"},
        {TYPE_RECT, "rect"},
        {TYPE_CIRCLE, "circle"},
        {TYPE_TEXT, "text"},
        {TYPE_BOOL, "bool"},
        {TYPE_INT, "int"},
        {TYPE_FLOAT, "float"},
        {TYPE_STRING, "string"},
        {TYPE_COORD, "coord"},
        {TYPE_RGB, "rgb"},
        {TYPE_LIST, "list"},

        {LITERAL_BOOL, "bool-literal"},
        {LITERAL_INT, "int-literal"},
        {LITERAL_FLOAT, "float-literal"},
        {LITERAL_STRING, "string-literal"},
        
        {IDENTIFIER, "identifier"}
    };

    const map<SymbolType, string> nonTerminals = {
        {PROGRAM, "PROGRAM"},
        {GLOBAL_STATEMENT_SEQUENCE, "GLOBAL_STATEMENT_SEQUENCE"},

        {GLOBAL_STATEMENT, "GLOBAL_STATEMENT"},
        {IMPORT_STATEMENT, "IMPORT_STATEMENT"},
        {USE_STATEMENT, "USE_STATEMENT"},
        {FUNCTION_DECLARATION, "FUNCTION_DECLARATION"},
        {CLASS_DECLARATION, "CLASS_DECLARATION"},

        {ASSIGNMENT, "ASSIGNMENT"},
        {LOCAL_STATEMENT, "LOCAL_STATEMENT"},
        {VARIABLE_DECLARATION, "VARIABLE_DECLARATION"},
        {ATTRIBUTE_DECLARATION, "ATTRIBUTE_DECLARATION"},
        {FUNCTION_CALL, "FUNCTION_CALL"},
        {PRIMITIVE_CALL, "PRIMITIVE_CALL"},
        {SETCENTER_CALL, "SETCENTER_CALL"},

        {FUNCTION_PREFIX, "FUNCTION_PREFIX"},
        {CLASS_PREFIX, "CLASS_PREFIX"},
        {RETURN_SUFFIX, "RETURN_SUFFIX"},
        {ARGUMENT_LIST, "ARGUMENT_LIST"},
        {PARAMETER_LIST, "PARAMETER_LIST"},
        {PARAMETER, "PARAMETER"},
        {RETURN_STATEMENT, "RETURN_STATEMENT"},

        {FUNCTION_BLOCK_SEQUENCE, "FUNCTION_BLOCK_SEQUENCE"},
        {ATTRIBUTE_BLOCK_SEQUENCE, "ATTRIBUTE_BLOCK_SEQUENCE"},
        {CLASS_BLOCK_SEQUENCE, "CLASS_BLOCK_SEQUENCE"},
        {FUNCTION_BLOCK, "FUNCTION_BLOCK"},
        {CLASS_BLOCK, "CLASS_BLOCK"},

        {DATATYPE, "DATATYPE"},
        {PRIMITIVE_DATATYPE, "PRIMITIVE_DATATYPE"},

        {TERM_BOOL, "TERM_BOOL"},
        {TERM_NOT, "TERM_NOT"},
        {TERM_AND, "TERM_AND"},
        {TERM_OR, "TERM_OR"},
        {TERM_LESS, "TERM_LESS"},
        {TERM_LESS_EQUALS, "TERM_LESS_EQUALS"},
        {TERM_GREATER, "TERM_GREATER"},
        {TERM_GREATER_EQUALS, "TERM_GREATER_EQUALS"},

        {NAMESPACED_IDENTIFIER, "NAMESPACED_IDENTIFIER"},
        {NAMESPACED_VALUE, "NAMESPACED_VALUE"},
        {LITERAL_LIST_SEQUENCE, "LITERAL_LIST_SEQUENCE"},
        {LITERAL_LIST, "LITERAL_LIST"},
        {LITERAL_COORD, "LITERAL_COORD"},
        {LITERAL_RGB, "LITERAL_RGB"},
        {LITERAL, "LITERAL"},
        {VALUE, "VALUE"}
    };

    inline auto ToString(SymbolType symbolType) -> string {
        if (terminals.contains(symbolType)) {
            return terminals.at(symbolType);
        } else {
            return nonTerminals.at(symbolType);
        }
    }
}