#include "WrongDog.hpp"

#include <iostream>
WrongDog::WrongDog() : WrongAnimal("WrongDog") {
    std::cout << "WrongDog default constructor called\n";
}

WrongDog::WrongDog(const WrongDog& other) : WrongAnimal(other) {
    std::cout << "WrongDog copy constructor called\n";
}

WrongDog& WrongDog::operator=(const WrongDog& other) {
    if (this != &other) {
        WrongAnimal::operator=(other);
        std::cout << "WrongDog copy assignment operator called\n";
    }
    return *this;
}

WrongDog::~WrongDog() { std::cout << "WrongDog destructor called\n"; }

void WrongDog::makeSound() const { std::cout << "Wrong Woof\n"; }