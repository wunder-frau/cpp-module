#pragma once
#include <string>

class WrongAnimal {
public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& other);
    WrongAnimal& operator=(const WrongAnimal& other);
    ~WrongAnimal();

    const std::string& getType() const;
    void makeSound() const;

protected:
    explicit WrongAnimal(std::string type);
    std::string type_;
};
