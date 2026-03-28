#include <stdio.h>
#include <iostream>
#include "StringSanitizer.h"

using namespace StringSanitizer;

int main(){
    std::vector<std::string> log = {
        "25.5", "42", "abc", "", "150", "75.0", "-10", "60.5", "Error", "90", "10.0", "100.0", "9.9", "101", "5.4", "0x45", "LEET"
    };

    
    auto cleaned_log = filter_and_convert(log);

    std::cout << "Cleaned log entries:" << std::endl;
    for (const auto& entry : cleaned_log){
        std::cout << entry << std::endl;
    }
    
    process_data(cleaned_log);
    std::cout << "\nProcessed data:" << std::endl;
    for (const auto& entry : cleaned_log){
        std::cout << entry << std::endl;
    }

    auto average = average_data(cleaned_log);

    std::cout << "\nAverage of the signal is: " << average << std::endl;
    
    return 0;
}