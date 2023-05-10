set(source_files
    "Main.cpp"

    "Addition.cpp"
)

add_executable(ALIB ${source_files})
target_include_directories(ALIB PRIVATE .)