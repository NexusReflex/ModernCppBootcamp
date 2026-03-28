#pragma once

#include <vector>
#include <string>
#include "ThreadSafePublisher.h"

class AnalyticsEngine : public Publisher {

    public:
        void process_and_notify(const std::vector<std::string>& raw_data);
        
};