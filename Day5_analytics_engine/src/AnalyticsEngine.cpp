#include "AnalyticsEngine.h"
#include "StringSanitizer.h"
#include <iostream>

void AnalyticsEngine::process_and_notify(const std::vector<std::string>& raw_data){
            std::cout << "[Engine]: Starting data cleaning pipeline...\n"; 

            auto clean_data = StringSanitizer::filter_and_convert(raw_data); // remove non-double entries

            if (clean_data.empty()){
                std::cout << "[Engine]: Empty data received. Nothing to do here.";
                return;
            }
            auto average = StringSanitizer::average_data(clean_data);

            std::cout << "[Engine]: Data cleanup complete. Market average: " << average << std::endl;

            this->notify("New Market Average: " + std::to_string(average));
}
        