#include "WrongCat.hpp"

#include <iostream>
WrongCat::WrongCat() : WrongAnimal("WrongCat") {
    type_ = "WrongCat";
    std::cout << "WrongCat default constructor called\n";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    std::cout << "WrongCat copy constructor called\n";
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    if (this != &other) {
        WrongAnimal::operator=(other);
        std::cout << "WrongCat copy assignment operator called\n";
    }
    return *this;
}

WrongCat::~WrongCat() { std::cout << "WrongCat destructor called\n"; }

void WrongCat::makeSound() const { std::cout << "Wrong Meow\n"; }