#include <iostream>
#include <chrono>   // For clocks and durations
#include <format>   // For easy string formatting (C++20)
#include "SafeFile.h"
namespace fs = std::filesystem;


int main(){

    fs::path data_dir = DATA_PATH;
    fs::path file("test.txt");
    fs::path full_path = data_dir / file;

    auto now = std::chrono::system_clock::now();
    std::string timestamp = std::format("{:%Y-%m-%d_%H-%M-%S}", now); 

    if (!fs::exists(data_dir)) {
        fs::create_directory(data_dir);
    }

    try {
        SafeFile log(full_path);
        log.write_formatted("The current time is: %s \n", timestamp.c_str());
        log.write("It's a great time for a challenge!");
    } catch (const std::exception& e){
        std::cerr << "Error: " << e.what() << "\n";
    }
    return 0;
}