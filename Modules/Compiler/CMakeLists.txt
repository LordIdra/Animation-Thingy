set(main_file
    Main.cpp
)

set(source_files
    errors/Errors.cpp

    files/ReadFile.cpp

    scanner/DFA/DFA.cpp
    scanner/DFA/DFAState.cpp
    scanner/NFA/NFA.cpp
    scanner/NFA/NFAState.cpp
    scanner/Scanner.cpp

    parser/sets/First.cpp
    parser/sets/Follow.cpp
    parser/sets/Sets.cpp
    parser/Parser.cpp
    parser/State.cpp
    parser/Tables.cpp
)

set(test_files
    TestReadFile.cpp
    TestScanner.cpp
    TestParser.cpp
)

add_subdirectory(src)
add_subdirectory(tests)
