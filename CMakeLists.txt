cmake_minimum_required(VERSION 3.15)
project(ModernCppBootcamp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Warning Strategy
if(MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

# 2. Safety Strategy (ASan)
if(NOT MSVC)
    add_compile_options(-fsanitize=address -fno-omit-frame-pointer)
    add_link_options(-fsanitize=address)
endif()

# 3. Include subdirectories for each day
add_subdirectory(Day1_RAII)
add_subdirectory(Day2_algorithms) 
add_subdirectory(Day3_shared_pointers)
add_subdirectory(Day4_concurrency)