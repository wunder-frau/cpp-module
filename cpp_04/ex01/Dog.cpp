#include "Dog.hpp"

#include <iostream>
Dog::Dog() : Animal("Dog") {
    std::cout << "Dog default constructor called\n";
    brain_ = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other), brain_(new Brain(*other.brain_)) {
    std::cout << "Dog copy constructor called\n";
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
        std::cout << "Dog copy assignment operator called\n";
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructor called\n";
    delete brain_;
}

void Dog::makeSound() const { std::cout << "Woof, woof\n"; }