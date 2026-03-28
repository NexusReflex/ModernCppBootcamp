#include "AlertBot.h"
#include "AnalyticsEngine.h"
#include <iostream>


int main(){

    std::vector<std::string> raw_price_data = {"150.50", "ERROR", "200.00", "9999.99", "14.6", "2080", "0x45", "Error404", "89.5", "205.01"};

    AnalyticsEngine engine;

    auto bot1 = std::make_shared<AlertBot>("Bot_1", 0);
    engine.subscribe(bot1);

    auto bot2 = std::make_shared<AlertBot>("Bot_2", 0);
    engine.subscribe(bot2);
    {
        auto bot3 = std::make_shared<AlertBot>("Bot_3", 0);
        engine.subscribe(bot3);
        engine.process_and_notify(raw_price_data);
    }
    auto bot4 = std::make_shared<AlertBot>("Bot_4", 0);
    engine.subscribe(bot4);
    engine.process_and_notify(raw_price_data);
}