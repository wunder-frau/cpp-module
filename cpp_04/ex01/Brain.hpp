#pragma once

#include <string>

class Brain {
public:
    Brain();
    Brain(const Brain& other);
    Brain& operator=(const Brain& other);
    ~Brain();

    size_t size() const;

    Brain& append(const std::string& idea);
    const std::string& at(const size_t index) const;

private:
    static const size_t capacity_ = 100;
    size_t size_ = 0;
    std::string ideas_[capacity_];
};

std::ostream& operator<<(std::ostream& os, const Brain& brain);