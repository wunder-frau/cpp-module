#pragma once
#include <string>

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
public:
    Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);

    ~Cat() override;
    void makeSound() const override;

private:
    Brain* brain_;
};