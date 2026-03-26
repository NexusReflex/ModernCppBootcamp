# Just define the executable for this specific day
add_executable(SafeFile 
    main.cpp
    SafeFile.h)

# Define a macro 'DATA_DIR' pointing to the Day 1 source folder
target_compile_definitions(SafeFile PRIVATE 
    DATA_PATH="${CMAKE_CURRENT_SOURCE_DIR}/data"
)

add_executable( DebugTest debug_test.cpp)

