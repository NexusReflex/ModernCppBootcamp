# 1. Tell CMake where the headers are for this directory
include_directories(include)

# 2. Create the executable
add_executable(MessageDispatcher src/main.cpp)

# Note: We don't need target_include_directories here if we use 
# include_directories(include) at the top, but for Day 5 to find these, 
# it's better to stay consistent:
target_include_directories(MessageDispatcher PUBLIC include)