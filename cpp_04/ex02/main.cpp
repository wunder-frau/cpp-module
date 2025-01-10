#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
    // const size_t size = 10;
    Animal* beasts[10];
    for (size_t i = 0; i < 5; ++i) beasts[i] = new Dog();
    for (size_t i = 5; i < 10; ++i) beasts[i] = new Cat();

    for (size_t i = 0; i < 10; ++i) delete beasts[i];

    Brain b;
    b.append("zero").append("first").append("second");
    std::cout << b << std::endl;

    return 0;
}
