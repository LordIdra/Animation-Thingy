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
        COLON,
        EQUALS,

        PUB,
        FUN,
        CLASS,
        USE,
        IMPORT,
        SETCENTER,
        VAR,
        CONST,

        PRIMITIVE_LINE,
        PRIMITIVE_RECT,
        PRIMITIVE_CIRCLE,
        PRIMITIVE_TEXT,

        STYLE_OUTLINE,
        STYLE_WIDTH,
        STYLE_OPACITY,
        STYLE_COLOR,
        STYLE_STYLE,
        STYLE_BOLD,

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
        
        IDENTIFIER,



        PROGRAM,
        TOP_LEVEL_STATEMENT,

        IMPORT_STATEMENT,
        USE_STATEMENT,
        FUNCTION_DECLARATION,
        CLASS_DECLARATION,
        VARIABLE_DECLARATION,
        FUNCTION_CALL,
        PRIMITIVE_CALL,

        ARGUMENT_LIST,
        PARAMETER_LIST,
        PARAMETER,

        FUNCTION_BLOCK,
        FUNCTION_BLOCK_SEQUENCE,
        CLASS_CONSTRUCTOR_BLOCK,
        CLASS_CONSTRUCTOR_BLOCK_SEQUENCE,
        CLASS_BLOCK,
        CLASS_BLOCK_SEQUENCE,
        
        DATATYPE,
        PRIMITIVE,

        NAMESPACED_IDENTIFIER,
        COORDINATE_LITERAL,
        RGB_LITERAL,
        LITERAL,
        VALUE,
    };

    typedef vector<SymbolType> ProductionRight;
    typedef pair<SymbolType, vector<ProductionRight>> ProductionList;
    typedef pair<SymbolType, ProductionRight> ProductionPair;

    const map<SymbolType, string> terminals = {
        {END_OF_FILE, "end_of_file"},
        {WHITESPACE, "whitespace"},
        {NEWLINE, "newline"},
        {INDENT_PLUS, "indent+"},
        {INDENT_MINUS, "indent-"},
        {COMMENT, "comment"},

        {OPEN_SQUARE_BRACKET, "open_square_bracket"},
        {CLOSE_SQUARE_BRACKET, "close_square_bracket"},
        {OPEN_ROUND_BRACKET, "open_round_bracket"},
        {CLOSE_ROUND_BRACKET, "close_round_bracket"},
        {DOT, "dot"},
        {COLON, "colon"},
        {EQUALS, "equals"},

        {PUB, "pub"},
        {FUN, "fun"},
        {CLASS, "class"},
        {USE, "use"},
        {IMPORT, "import"},
        {SETCENTER, "setcenter"},
        {VAR, "var"},
        {CONST, "const"},

        {PRIMITIVE_LINE, "primitive_line"},
        {PRIMITIVE_RECT, "primitive_rect"},
        {PRIMITIVE_CIRCLE, "primitive_circle"},
        {PRIMITIVE_TEXT, "primitive_text"},

        {STYLE_OUTLINE, "style_outline"},
        {STYLE_WIDTH, "style_width"},
        {STYLE_OPACITY, "style_opacity"},
        {STYLE_COLOR, "style_color"},
        {STYLE_STYLE, "style_style"},
        {STYLE_BOLD, "style_bold"},

        {TYPE_BOOL, "type_bool"},
        {TYPE_INT, "type_int"},
        {TYPE_FLOAT, "type_float"},
        {TYPE_STRING, "type_string"},
        {TYPE_COORD, "type_coord"},
        {TYPE_RGB, "type_rgb"},
        {TYPE_LIST, "type_list"},

        {LITERAL_BOOL, "literal_bool"},
        {LITERAL_INT, "literal_int"},
        {LITERAL_FLOAT, "literal_float"},
        {LITERAL_STRING, "literal_string"},
        
        {IDENTIFIER, "identifier"},
    };

    const map<SymbolType, string> nonTerminals = {
        {PROGRAM, "PROGRAM"},
        {TOP_LEVEL_STATEMENT, "TOP_LEVEL_STATEMENT"},

        {IMPORT_STATEMENT, "IMPORT_STATEMENT"},
        {USE_STATEMENT, "USE_STATEMENT"},
        {FUNCTION_DECLARATION, "FUNCTION_DECLARATION"},
        {CLASS_DECLARATION, "CLASS_DECLARATION"},
        {VARIABLE_DECLARATION, "VARIABLE_DECLARATION"},
        {FUNCTION_CALL, "FUNCTION_CALL"},
        {PRIMITIVE_CALL, "PRIMITIVE_CALL"},

        {ARGUMENT_LIST, "ARGUMENT_LIST"},
        {PARAMETER_LIST, "PARAMETER_LIST"},
        {PARAMETER, "PARAMETER"},

        {FUNCTION_BLOCK, "FUNCTION_BLOCK"},
        {FUNCTION_BLOCK_SEQUENCE, "FUNCTION_BLOCK_SEQUENCE"},
        {CLASS_CONSTRUCTOR_BLOCK, "CLASS_CONSTRUCTOR_BLOCK"},
        {CLASS_CONSTRUCTOR_BLOCK_SEQUENCE, "CLASS_CONSTRUCTOR_BLOCK_SEQUENCE"},
        {CLASS_BLOCK, "CLASS_BLOCK"},
        {CLASS_BLOCK_SEQUENCE, "CLASS_BLOCK_SEQUENCE"},

        {DATATYPE, "DATATYPE"},
        {PRIMITIVE, "PRIMITIVE"},

        {NAMESPACED_IDENTIFIER, "NAMESPACED_IDENTIFIER"},
        {COORDINATE_LITERAL, "COORDINATE_LITERAL"},
        {RGB_LITERAL, "RGB_LITERAL"},
        {LITERAL, "LITERAL"},
        {VALUE, "VALUE"},
    };

    inline auto ToString(SymbolType symbolType) -> string {
        if (terminals.contains(symbolType)) {
            return terminals.at(symbolType);
        } else {
            return nonTerminals.at(symbolType);
        }
    }
}