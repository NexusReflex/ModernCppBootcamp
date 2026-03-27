#pragma once
#include <iostream>
#include <string>
#include <mutex>
#include <thread>
#include <atomic>

class Subscriber{
    static inline std::mutex s_cout_mutex; // C++17 inline static member variable for thread-safe access to std::cout, shared across all instances of Subscriber
    public:
        explicit Subscriber(std::string name, int priority) : m_name(std::move(name)), m_priority(priority) {};
        virtual ~Subscriber() { std::cout << m_name << " is being destroyed!\n"; }

        void receive(const std::string& message) const {
            std::this_thread::sleep_for(std::chrono::milliseconds(100)); // simulate heavy task
            std::lock_guard<std::mutex> guard(s_cout_mutex);
            std::cout << "[" << m_name << "]" << " received: " << message << "\n";
        }

        int getPriority() const { 
            return m_priority;
        }

        void setPriority(int p) {
            if (p < 0) m_priority = 0;
            else m_priority = p;
        }

    private:
        std::string m_name;
        int m_priority;
};