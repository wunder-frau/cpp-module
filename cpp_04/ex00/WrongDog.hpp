#pragma once
#include <string>

#include "WrongAnimal.hpp"
class WrongDog : public WrongAnimal {
public:
    WrongDog();
    WrongDog(const WrongDog& other);
    WrongDog& operator=(const WrongDog& other);

    ~WrongDog();

    void makeSound() const;
};
