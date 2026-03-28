# Just define the executable for this specific day
add_executable(SafeFile 
    src/main.cpp)

add_executable( DebugTest 
    src/debug_test.cpp)

# Define a macro 'DATA_DIR' pointing to the Day 1 source folder
target_compile_definitions(SafeFile PRIVATE 
    DATA_PATH="${CMAKE_CURRENT_SOURCE_DIR}/data"
)

target_include_directories(SafeFile PRIVATE include)