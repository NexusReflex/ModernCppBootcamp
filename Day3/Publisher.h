#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include "Subscriber.h"

class Publisher{

    private:
        std::vector<std::weak_ptr<Subscriber>> m_subscribers;
    
    public:
        void subscribe(std::shared_ptr<Subscriber> subscriber){
            m_subscribers.push_back(subscriber); // Automatically converts shared_ptr to weak_ptr
        }

        void notify(std::string message){
            std::cout << "Publisher is sending message: " << message << "\n";

            // 1. Clean up "expired" subscribers (those that have been destroyed)
            std::erase_if(m_subscribers, [](const std::weak_ptr<Subscriber>& sub){
                return sub.expired();
            });

            // 2. Sort subscribers by priority
            std::sort(m_subscribers.begin(), m_subscribers.end(), [](const auto& a, const auto& b){
                auto sub_a = a.lock();
                auto sub_b = b.lock();
                
                return sub_a->getPriority() < sub_b->getPriority();
            });

            // 3. Send message to remaining subscribers
            for (auto& weak_sub : m_subscribers){
                if (auto shared_sub = weak_sub.lock()){
                    shared_sub->receive(message);
                }
            }

        }
};