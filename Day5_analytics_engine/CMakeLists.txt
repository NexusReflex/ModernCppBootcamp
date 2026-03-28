# Day5_analytics_engine/CMakeLists.txt

add_executable(Day5_analytics_engine
    src/main.cpp 
    src/AnalyticsEngine.cpp
    src/AlertBot.cpp
)

# 1. Add all necessary include paths
target_include_directories(Day5_analytics_engine PRIVATE 
    include 
    ${CMAKE_SOURCE_DIR}/Day2_algorithms/include 
    ${CMAKE_SOURCE_DIR}/Day4_concurrency/include
)

# 2. Only link the built-in Threads library
find_package(Threads REQUIRED)
target_link_libraries(Day5_analytics_engine PRIVATE Threads::Threads)