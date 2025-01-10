#pragma once

#include <string>

class Brain {
public:
    Brain();
    Brain(const Brain& other);
    Brain& operator=(const Brain& other);
    ~Brain();

private:
    static const size_t capacity_ = 100;
    std::string ideas_[capacity_];
};