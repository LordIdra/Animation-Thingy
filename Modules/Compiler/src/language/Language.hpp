#pragma once

#include "Symbols.hpp"

// TODO global variables, namespaces?
// TODO static functions/classes?
// TODO passing self into methods?
// TODO syntax for array initialization?
// TODO assignment?
// TODO terms / expressions?
// TODO branching?
// TODO loops?


namespace language {
    const vector<char> characters = {
        '-',
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
        '(', ')', '[',']','{', '}',
        '\"', '\'', ':', ';', '.', ',',
        ' ', '-', '_',
        '!', '&', '|', '+', '-',  '/', '*', '%',
        '=', '<', '>'
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
        {COMMA, ","},
        {COLON, ":"},
        {ARROW, "->"},

        {EXCLAMATION_MARK, "!"},
        {AMPERSAND, "&"},
        {VERTICAL_LINE, "\\|"},
        {PLUS, "\\+"},
        {MINUS, "-"},
        {STAR, "\\*"},
        {SLASH, "/"},
        {PERCENT, "%"},

        {DOUBLE_EQUALS, "=="},
        {GREATER, ">"},
        {LESS, "<"},
        {GREATER_EQUALS, "(>=)|(=>)"},
        {LESS_EQUALS, "(<=)|(=<)"},

        {EQUALS, "="},
        {PLUS_EQUALS, "\\+="},
        {DASH_EQUALS, "-="},
        {STAR_EQUALS, "\\*="},
        {SLASH_EQUALS, "/="},

        // Keywords
        {PUB, "pub"},
        {FUN, "fun"},
        {CLASS, "class"},
        {USE, "use"},
        {IMPORT, "import"},
        {SETCENTER, "setcenter"},
        {VAR, "var"},
        {CONST, "const"},
        {RET, "ret"},

        // Datatypes
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

        // Literals
        {LITERAL_BOOL, "(true)|(false)"},
        {LITERAL_INT, "-?[0-9]+"},
        {LITERAL_FLOAT, "-?([0-9]+)(\\.)([0-9]+)"},
        {LITERAL_STRING, "\"(^\")*\""},

        // Variables
        {IDENTIFIER, "([a-z]|[A-Z]|_)([a-z]|[A-Z]|[0-9]|_)*"},
    };

    const map<SymbolType, vector<ProductionRight>> nonTerminalProductions {
        {PROGRAM, {
            {GLOBAL_STATEMENT_SEQUENCE, END_OF_FILE}}},

        {GLOBAL_STATEMENT_SEQUENCE, {
            {GLOBAL_STATEMENT},
            {GLOBAL_STATEMENT_SEQUENCE, GLOBAL_STATEMENT}}},



        {GLOBAL_STATEMENT, {
            {IMPORT_STATEMENT},
            {USE_STATEMENT},
            {CLASS_DECLARATION},
            {FUNCTION_DECLARATION}}},

        {IMPORT_STATEMENT, {
            {IMPORT, NAMESPACED_IDENTIFIER, NEWLINE}}},

        {USE_STATEMENT, {
            {USE, NAMESPACED_IDENTIFIER, NEWLINE}}},

        {FUNCTION_DECLARATION, {
            {FUNCTION_PREFIX, OPEN_ROUND_BRACKET, CLOSE_ROUND_BRACKET, NEWLINE, FUNCTION_BLOCK},
            {FUNCTION_PREFIX, OPEN_ROUND_BRACKET, PARAMETER_LIST, CLOSE_ROUND_BRACKET, NEWLINE, FUNCTION_BLOCK},
            {FUNCTION_PREFIX, OPEN_ROUND_BRACKET, CLOSE_ROUND_BRACKET, RETURN_SUFFIX, NEWLINE, FUNCTION_BLOCK},
            {FUNCTION_PREFIX, OPEN_ROUND_BRACKET, PARAMETER_LIST, CLOSE_ROUND_BRACKET, RETURN_SUFFIX, NEWLINE, FUNCTION_BLOCK},}},

        {CLASS_DECLARATION, {
            {CLASS_PREFIX, NEWLINE, CLASS_BLOCK}}},

        

        {ASSIGNMENT, {
            {IDENTIFIER, EQUALS, VALUE},
            {IDENTIFIER, PLUS_EQUALS, VALUE},
            {IDENTIFIER, DASH_EQUALS, VALUE},
            {IDENTIFIER, STAR_EQUALS, VALUE},
            {IDENTIFIER, SLASH_EQUALS, VALUE},
            {IDENTIFIER, PERCENT_EQUALS, VALUE}}},

        {LOCAL_STATEMENT, {
            {SETCENTER_CALL, NEWLINE},
            {FUNCTION_CALL, NEWLINE},
            {PRIMITIVE_CALL, NEWLINE},
            {ASSIGNMENT, NEWLINE},
            {VARIABLE_DECLARATION, NEWLINE}}},

        {VARIABLE_DECLARATION, {
            {VAR, IDENTIFIER, EQUALS, VALUE},
            {CONST, IDENTIFIER, EQUALS, VALUE}}},
        
        {ATTRIBUTE_DECLARATION, {
            {VAR, IDENTIFIER, COLON, DATATYPE, NEWLINE},
            {CONST, IDENTIFIER, COLON, DATATYPE, NEWLINE},
            {PUB, VAR, IDENTIFIER, COLON, DATATYPE, NEWLINE},
            {PUB, CONST, IDENTIFIER, COLON, DATATYPE, NEWLINE}}},
        
        {FUNCTION_CALL, {
            {NAMESPACED_IDENTIFIER, OPEN_ROUND_BRACKET, CLOSE_ROUND_BRACKET},
            {NAMESPACED_IDENTIFIER, OPEN_ROUND_BRACKET, ARGUMENT_LIST, CLOSE_ROUND_BRACKET}}},
        
        {PRIMITIVE_CALL, {
            {PRIMITIVE_DATATYPE, OPEN_ROUND_BRACKET, CLOSE_ROUND_BRACKET},
            {PRIMITIVE_DATATYPE, OPEN_ROUND_BRACKET, ARGUMENT_LIST, CLOSE_ROUND_BRACKET}}},

        {SETCENTER_CALL, {
            {SETCENTER, OPEN_ROUND_BRACKET, VALUE, CLOSE_ROUND_BRACKET}}},



        {FUNCTION_PREFIX, {
            {FUN, IDENTIFIER},
            {PUB, FUN, IDENTIFIER}}},
        
        {CLASS_PREFIX, {
            {CLASS, IDENTIFIER},
            {PUB, CLASS, IDENTIFIER}}},

        {RETURN_SUFFIX, {
            {ARROW, DATATYPE},}},

        {ARGUMENT_LIST, {
            {VALUE},
            {ARGUMENT_LIST, COMMA, VALUE}}},

        {PARAMETER_LIST, {
            {PARAMETER},
            {PARAMETER_LIST, COMMA, PARAMETER}}},
        
        {PARAMETER, {
            {IDENTIFIER, COLON, DATATYPE}}},

        {RETURN_STATEMENT, {
            {RET, VALUE, NEWLINE}}},



        {FUNCTION_BLOCK_SEQUENCE, {
            {LOCAL_STATEMENT},
            {RETURN_STATEMENT},
            {FUNCTION_BLOCK_SEQUENCE, LOCAL_STATEMENT},
            {FUNCTION_BLOCK_SEQUENCE, RETURN_STATEMENT}}},

        {ATTRIBUTE_BLOCK_SEQUENCE, {
            {ATTRIBUTE_DECLARATION},
            {ATTRIBUTE_BLOCK_SEQUENCE, ATTRIBUTE_DECLARATION}}},

        {CLASS_BLOCK_SEQUENCE, {
            {ATTRIBUTE_BLOCK_SEQUENCE},
            {FUNCTION_DECLARATION},
            {CLASS_BLOCK_SEQUENCE, FUNCTION_DECLARATION}}},

        {FUNCTION_BLOCK, {
            {INDENT_PLUS, FUNCTION_BLOCK_SEQUENCE, INDENT_MINUS}}},

        {CLASS_BLOCK, {
            {INDENT_PLUS, CLASS_BLOCK_SEQUENCE, INDENT_MINUS}}},
        


        {DATATYPE, {
            {TYPE_BOOL},
            {TYPE_INT},
            {TYPE_FLOAT},
            {TYPE_STRING},
            {TYPE_COORD},
            {TYPE_RGB},
            {TYPE_LIST},
            {PRIMITIVE_DATATYPE},
            {NAMESPACED_IDENTIFIER}}},
        
        {PRIMITIVE_DATATYPE, {
            {TYPE_CIRCLE},
            {TYPE_LINE},
            {TYPE_RECT},
            {TYPE_TEXT}}},
        


        {TERM_BOOL, {
            {TERM_NOT}}},
        
        {TERM_NOT, {
            {TERM_AND},
            {EXCLAMATION_MARK, TERM_NOT}}},
        
        {TERM_AND, {
            {TERM_OR},
            {TERM_AND, AMPERSAND, TERM_AND}}},
        
        {TERM_OR, {
            {TERM_LESS},
            {TERM_OR, VERTICAL_LINE, TERM_OR}}},
        
        {TERM_LESS, {
            {VALUE},
            {TERM_LESS, LESS, TERM_LESS}}},
        
        //{TERM_LESS_EQUALS, {
        //    {TERM_GREATER},
        //    {TERM_LESS_EQUALS, LESS_EQUALS, TERM_LESS_EQUALS}}},
        
        // {TERM_GREATER, {
        //     {TERM_GREATER_EQUALS},
        //     {TERM_LESS_EQUALS, GREATER, TERM_LESS_EQUALS}}},
        
        // {TERM_GREATER_EQUALS, {
        //     {VALUE},
        //     {TERM_LESS_EQUALS, GREATER_EQUALS, TERM_LESS_EQUALS}}},



        {NAMESPACED_IDENTIFIER, {
            {IDENTIFIER},
            {NAMESPACED_IDENTIFIER, DOT, IDENTIFIER}}},
        
        {NAMESPACED_VALUE, {
            {NAMESPACED_IDENTIFIER},
            {FUNCTION_CALL},
            {PRIMITIVE_CALL},
            {NAMESPACED_VALUE, DOT, NAMESPACED_IDENTIFIER},
            {NAMESPACED_VALUE, DOT, FUNCTION_CALL},
            {NAMESPACED_VALUE, DOT, PRIMITIVE_CALL}}},
        
        {LITERAL_LIST_SEQUENCE, {
            {VALUE},
            {LITERAL_LIST_SEQUENCE, COMMA, VALUE}}},

        {LITERAL_LIST, {
            {OPEN_SQUARE_BRACKET, LITERAL_LIST_SEQUENCE, CLOSE_SQUARE_BRACKET},
            {OPEN_SQUARE_BRACKET, CLOSE_SQUARE_BRACKET}}},
        
        {LITERAL_COORD, {
            {OPEN_SQUARE_BRACKET, LITERAL_INT, LITERAL_INT, CLOSE_SQUARE_BRACKET}}},
        
        {LITERAL_RGB, {
            {OPEN_SQUARE_BRACKET, LITERAL_FLOAT, LITERAL_FLOAT, LITERAL_FLOAT, CLOSE_SQUARE_BRACKET}}},

        {LITERAL, {
            {LITERAL_BOOL},
            {LITERAL_FLOAT},
            {LITERAL_INT},
            {LITERAL_STRING},
            {LITERAL_LIST},
            {LITERAL_COORD},
            {LITERAL_RGB}}},

        {VALUE, {
            {LITERAL},
            {TERM_BOOL},
            {NAMESPACED_VALUE},
            {FUNCTION_CALL},
            {PRIMITIVE_CALL}}}
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