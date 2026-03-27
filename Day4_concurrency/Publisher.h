#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <thread>
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

            // Removed priority sorting in favour of multi threading

            std::atomic<int> delivery_count = 0; // Using atomic to ensure no more than one thread writes to the counter at each given time
            std::vector<std::jthread> workers; // worker threads

            // 3. Send message to remaining subscribers
            for (auto& weak_sub : m_subscribers){
                if (auto shared_sub = weak_sub.lock()){
                    // Launch a background thread
                    workers.emplace_back([shared_sub, message, &delivery_count](){
                        shared_sub->receive(message);
                        delivery_count++;
                    });
                }
            }
            workers.clear(); // This actively destroys the jthreads and waits for them to finish. 
            // std::jthread would automatically wait for all workers to finish here, 
            // but to use delivery_counter we need to ensure all workers are done first. 
            // Alternatively place workers is separate scope -> {}.
            
            std::cout << "Delivered to " << delivery_count << " users\n"; 
            
        }
};