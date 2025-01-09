#pragma once

#include <string>

#include "Animal.hpp"

class Dog : public Animal {
public:
    Dog();
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);

    ~Dog() override;
    void makeSound() const override;
};