#pragma once

#include <string>

class Animal {
public:
    Animal();
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    virtual ~Animal();
    const std::string& getType() const;
    virtual void makeSound() const;

protected:
    explicit Animal(const std::string& type);
    std::string type_;
};