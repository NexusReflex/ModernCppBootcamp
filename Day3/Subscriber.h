#pragma once
#include <iostream>
#include <string>

class Subscriber{
    public:
        explicit Subscriber(std::string name, int priority) : m_name(std::move(name)), m_priority(priority) {};
        virtual ~Subscriber() { std::cout << m_name << " is being destroyed!\n"; }

        void receive(const std::string& message) const {
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