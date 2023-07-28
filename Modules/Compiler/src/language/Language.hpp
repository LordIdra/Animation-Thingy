#pragma once

#include "Symbols.hpp"


namespace language {
    const vector<char> language = {
        '-',
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
        '(', ')', '[',']','{', '}',
        '\"', '\'', ':', ';', '.', ',',
        '+', ' ', '/', '*', '=', '_'
    };

    const map<SymbolType, string> terminalRegex {
        // Whitespace
        {WHITESPACE, " +"},
        {COMMENT, "//"},

        // Punctuation
        {OPEN_SQUARE_BRACKET, "\\["},
        {CLOSE_SQUARE_BRACKET, "\\]"},
        {OPEN_ROUND_BRACKET, "\\("},
        {CLOSE_ROUND_BRACKET, "\\)"},
        {DOT, "\\."},
        {COLON, ":"},
        {EQUALS, "="},

        // Keywords
        {PUB, "pub"},
        {FUN, "fun"},
        {CLASS, "class"},
        {USE, "use"},
        {IMPORT, "import"},
        {SETCENTER, "setcenter"},
        {VAR, "var"},
        {CONST, "const"},

        // Primitives
        {PRIMITIVE_LINE, "line"},
        {PRIMITIVE_RECT, "rect"},
        {PRIMITIVE_CIRCLE, "circle"},
        {PRIMITIVE_TEXT, "text"},

        // Datatypes
        {TYPE_BOOL, "bool"},
        {TYPE_INT, "int"},
        {TYPE_FLOAT, "float"},
        {TYPE_STRING, "string"},
        {TYPE_COORD, "coord"},
        {TYPE_RGB, "rgb"},
        {TYPE_LIST, "list"},

        // Literals
        {LITERAL_BOOL, "(true)|(false)"},
        {LITERAL_INT, "-?[0-9]+"},
        {LITERAL_FLOAT, "-?([0-9]+)(\\.)([0-9]+)"},
        {LITERAL_STRING, "\"(^\")*\""},

        // Variables
        {IDENTIFIER, "([a-z]|[A-Z])([a-z]|[A-Z]|[0-9])*"},
    };

    const map<SymbolType, vector<ProductionRight>> nonTerminalProductions {
        {PROGRAM, {
            {TOP_LEVEL_STATEMENT, END_OF_FILE}}},
        
        {TOP_LEVEL_STATEMENT, {
            {IMPORT_STATEMENT},
            {USE_STATEMENT},
            {CLASS_DECLARATION},
            {FUNCTION_DECLARATION},
            {TOP_LEVEL_STATEMENT, IMPORT_STATEMENT},
            {TOP_LEVEL_STATEMENT, USE_STATEMENT},
            {TOP_LEVEL_STATEMENT, CLASS_DECLARATION},
            {TOP_LEVEL_STATEMENT, FUNCTION_DECLARATION}}},

        {IMPORT_STATEMENT, {
            {IMPORT, NAMESPACED_IDENTIFIER, NEWLINE}}},

        {USE_STATEMENT, {
            {USE, NAMESPACED_IDENTIFIER, NEWLINE}}},

        {FUNCTION_DECLARATION, {
            {FUN, IDENTIFIER, NEWLINE, FUNCTION_BLOCK},
            {FUN, IDENTIFIER, PARAMETER_LIST, NEWLINE, FUNCTION_BLOCK},
            {PUB, FUN, IDENTIFIER, NEWLINE, FUNCTION_BLOCK},
            {PUB, FUN, IDENTIFIER, PARAMETER_LIST, NEWLINE, FUNCTION_BLOCK}}},

        {CLASS_DECLARATION, {
            {CLASS, IDENTIFIER, NEWLINE, CLASS_BLOCK},
            {CLASS, IDENTIFIER, PARAMETER_LIST, NEWLINE, CLASS_BLOCK},
            {PUB, CLASS, IDENTIFIER, NEWLINE, CLASS_BLOCK},
            {PUB, CLASS, IDENTIFIER, PARAMETER_LIST, NEWLINE, CLASS_BLOCK}}},

        {VARIABLE_DECLARATION, {
            {VAR, IDENTIFIER, EQUALS, VALUE},
            {CONST, IDENTIFIER, EQUALS, VALUE}}},
        
        {FUNCTION_CALL, {
            {NAMESPACED_IDENTIFIER},
            {NAMESPACED_IDENTIFIER, ARGUMENT_LIST}}},
        
        {PRIMITIVE_CALL, {
            {PRIMITIVE},
            {PRIMITIVE, ARGUMENT_LIST}}},


        
        {ARGUMENT_LIST, {
            {VALUE},
            {ARGUMENT_LIST, VALUE}}},

        {PARAMETER_LIST, {
            {PARAMETER},
            {PARAMETER_LIST, PARAMETER}}},
        
        {PARAMETER, {
            {OPEN_ROUND_BRACKET, IDENTIFIER, COLON, DATATYPE, CLOSE_ROUND_BRACKET}}},



        {FUNCTION_BLOCK, {
            {INDENT_PLUS, FUNCTION_BLOCK_SEQUENCE, INDENT_MINUS}}},

        {FUNCTION_BLOCK_SEQUENCE, {
            {FUNCTION_CALL, NEWLINE},
            {PRIMITIVE_CALL, NEWLINE},
            {VARIABLE_DECLARATION, NEWLINE},
            {FUNCTION_BLOCK_SEQUENCE, FUNCTION_CALL, NEWLINE},
            {FUNCTION_BLOCK_SEQUENCE, PRIMITIVE_CALL, NEWLINE},
            {FUNCTION_BLOCK_SEQUENCE, VARIABLE_DECLARATION, NEWLINE}}},
        
        {CLASS_CONSTRUCTOR_BLOCK, {
            {INDENT_PLUS, CLASS_CONSTRUCTOR_BLOCK_SEQUENCE, INDENT_MINUS}}},

        {CLASS_CONSTRUCTOR_BLOCK_SEQUENCE, {
            {FUNCTION_CALL},
            {PRIMITIVE_CALL},
            {VARIABLE_DECLARATION},
            {CLASS_CONSTRUCTOR_BLOCK_SEQUENCE, FUNCTION_CALL},
            {CLASS_CONSTRUCTOR_BLOCK_SEQUENCE, PRIMITIVE_CALL},
            {CLASS_CONSTRUCTOR_BLOCK_SEQUENCE, VARIABLE_DECLARATION}}},

        {CLASS_BLOCK, {
            {INDENT_PLUS, CLASS_BLOCK_SEQUENCE, INDENT_MINUS}}},
        
        {CLASS_BLOCK_SEQUENCE, {
            {CLASS_CONSTRUCTOR_BLOCK},
            {CLASS_BLOCK, FUNCTION_DECLARATION}}},
        


        {DATATYPE, {
            {TYPE_BOOL},
            {TYPE_INT},
            {TYPE_FLOAT},
            {TYPE_STRING},
            {TYPE_COORD},
            {TYPE_RGB},
            {TYPE_LIST}}},
        
        {PRIMITIVE, {
            {PRIMITIVE_CIRCLE},
            {PRIMITIVE_LINE},
            {PRIMITIVE_RECT},
            {PRIMITIVE_TEXT}}},



        {NAMESPACED_IDENTIFIER, {
            {IDENTIFIER},
            {NAMESPACED_IDENTIFIER, DOT, IDENTIFIER}}},

        {COORDINATE_LITERAL, {
            {OPEN_SQUARE_BRACKET, LITERAL_INT, LITERAL_INT, CLOSE_SQUARE_BRACKET}}},

        {RGB_LITERAL, {
            {OPEN_SQUARE_BRACKET, LITERAL_FLOAT, LITERAL_FLOAT, LITERAL_FLOAT, CLOSE_SQUARE_BRACKET}}},

        {LITERAL, {
            {LITERAL_BOOL},
            {LITERAL_FLOAT},
            {LITERAL_INT},
            {LITERAL_STRING},
            {COORDINATE_LITERAL},
            {RGB_LITERAL}}},

        {VALUE, {
            {LITERAL}}}
    };

    struct Symbol {
        SymbolType type;

        Symbol(const SymbolType type) {
            this->type = type;
        }
    };

    struct Terminal : Symbol {
        string text;

        Terminal(const SymbolType type, const string text) 
            : Symbol(type) {
            this->text = text;
        }

        auto operator==(const Terminal &other) const -> bool {
            return type == other.type && text == other.text;
        }
    };

    struct NonTerminal : Symbol {
        shared_ptr<NonTerminal> parent;
        vector<shared_ptr<Symbol>> children;

        NonTerminal(const SymbolType type, shared_ptr<NonTerminal> parent, vector<shared_ptr<Symbol>> children) 
            : Symbol(type) {
            this->parent = parent;
            this->children = children;
        }

        auto operator==(const NonTerminal &other) const -> bool {
            return type == other.type && children == other.children;
        }
    };
}