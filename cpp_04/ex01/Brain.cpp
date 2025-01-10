#include "Brain.hpp"

Brain::Brain() {}
Brain::Brain(const Brain& other) {
    for (size_t i = 0; i < capacity_; ++i) ideas_[i] = other.ideas_[i];
}
Brain& Brain::operator=(const Brain& other) {
    if (this != &other)
        for (size_t i = 0; i < capacity_; ++i) ideas_[i] = other.ideas_[i];
    return *this;
}
Brain::~Brain() {}