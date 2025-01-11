#include "Brain.hpp"

#include <iostream>

Brain::Brain() { std::cout << "Brain default constructor called\n"; }

Brain::Brain(const Brain& other) : size_(other.size_) {
    std::cout << "Brain copy constructor called\n";
    for (size_t i = 0; i < size_; ++i) ideas_[i] = other.ideas_[i];
}
Brain& Brain::operator=(const Brain& other) {
    std::cout << "Brain copy assignment operator called\n";
    if (this != &other) {
        size_ = other.size_;
        for (size_t i = 0; i < size_; ++i) ideas_[i] = other.ideas_[i];
    }
    return *this;
}
Brain::~Brain() { std::cout << "Brain destructor called\n"; }

size_t Brain::size() const { return size_; };

Brain& Brain::append(const std::string& idea) {
    if (size_ <= capacity_)
        ideas_[size_++] = idea;
    return *this;
}

const std::string& Brain::idea(const size_t index) const {
    return ideas_[index < size_ ? index : size_];
}

std::ostream& operator<<(std::ostream& os, const Brain& brain) {
    for (size_t i = 0; i < brain.size(); ++i) {
        os << brain.idea(i) << ' ';
    }
    return os;
}