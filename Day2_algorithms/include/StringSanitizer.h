#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <numeric>


/*
The "String Sanitizer & Statistics" Challenge

Your goal is to process a "log" of sensor readings that are currently stored as strings (perhaps they were read from a messy CSV file).
The log contains a mix of valid and invalid entries. Your task is to sanitize the log by removing invalid entries and then compute some statistics on the valid readings.
Make sure valid entries are numeric values (integers or floating-point numbers) and that they fall within a specified range (e.g., 10 to 100). Invalid entries include non-numeric strings, empty strings, and numbers outside the specified range. 
*/

namespace StringSanitizer{
    

    // Filter and convert
    auto filter_and_convert(const std::vector<std::string>& logs){
        std::vector<double> results;
        std::for_each(logs.begin(), logs.end(), [&results](const auto& entry){
            try
            {
                results.push_back(std::stod(entry));
            }
            catch(const std::invalid_argument& e){
                // do nothing -> skip this entry
            }
            catch(const std::out_of_range& e){
                // do nothing -> skip this entry
            }
        });
        return results;
    };

    // First the filtered and converted values between (0, 100], then erase values < 10
    void process_data(std::vector<double>& values){
        std::ranges::replace_if(values, [](auto& value){
            return value > 100.0;
        }, 100); // clip values above 100
        std::ranges::replace_if(values, [](auto& value){
            return value <= 0.0;
        }, 0); // clip values below 0
        std::erase_if(values, [](double value){
            return value < 10;
        }); // remove small values
    };

    inline auto average_data(const std::vector<double>& values){
        return std::accumulate(values.begin(), values.end(), 0.0) / values.size(); // The 0.0 is the starting value. If you put 0 (an integer), the compiler will truncate all your doubles into ints!
    };

}