#include "WrongAnimal.hpp"

#include <iostream>
WrongAnimal::WrongAnimal() : type_("WrongAnimal") {
    std::cout << "WrongAnimal default constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type_(other.type_) {
    std::cout << "WrongAnimal copy constructor called\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    if (this != &other) {
        type_ = other.type_;
        std::cout << "WrongAnimal copy assignment operator called\n";
    }
    return *this;
}

WrongAnimal::~WrongAnimal() { std::cout << "WrongAnimal destructor called\n"; }

const std::string& WrongAnimal::getType() const { return type_; }

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal makes a Wrong generic sound\n";
}

WrongAnimal::WrongAnimal(std::string type) : type_(type) {
    std::cout << "WrongAnimal assignment constructor called\n";
}