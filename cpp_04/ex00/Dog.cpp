#include "Dog.hpp"

#include <iostream>
Dog::Dog() : Animal("Dog") { std::cout << "Dog default constructor called\n"; }

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog copy constructor called\n";
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
        std::cout << "Dog copy assignment operator called\n";
    }
    return *this;
}

Dog::~Dog() { std::cout << "Dog destructor called\n"; }

void Dog::makeSound() const { std::cout << "Woof, woof\n"; }