# 1. Tell CMake where the headers are for this entire directory
# This allows both executables to find their respective headers
include_directories(include)

# 2. Create the first executable (Student Grades)
add_executable(GradeProcessor src/StudentMain.cpp)

# 3. Create the second executable (String Sanitizer)
add_executable(StringSanitizer src/SanitizerMain.cpp)

# Note: We don't need target_include_directories here if we use 
# include_directories(include) at the top, but for Day 5 to find these, 
# it's better to stay consistent:
target_include_directories(GradeProcessor PUBLIC include)
target_include_directories(StringSanitizer PUBLIC include)