#include <memory>
#include "Publisher.h"
#include "Subscriber.h"

int main(){

    Publisher newsAgency;

    auto sub1 = std::make_shared<Subscriber>("UserA", 3);
    newsAgency.subscribe(sub1);

    auto sub2 = std::make_shared<Subscriber>("UserB", 1);
    newsAgency.subscribe(sub2);

    {

        auto sub3 = std::make_shared<Subscriber>("UserC", 2);
        newsAgency.subscribe(sub3);
    
        newsAgency.notify("Hi there!");
    }

    newsAgency.notify("We are the survivors...");

    return 0;
}