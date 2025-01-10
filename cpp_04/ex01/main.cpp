#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
    /*
    In your main function, create and fill an array of Animal objects.
    Half of it will be Dog objects and the other half will be Cat objects.
    At the end of your program execution, loop over this array and delete every
    Animal. You must delete directly dogs and cats as Animals. The appropriate
    destructors must be called in the expected order.
    */

    // const size_t size = 10;
    Animal* beasts[10];
    for (size_t i = 0; i < 5; ++i) beasts[i] = new Dog();
    for (size_t i = 5; i < 10; ++i) beasts[i] = new Cat();

    for (size_t i = 0; i < 10; ++i) delete beasts[i];

    return 0;
}
