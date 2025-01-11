#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

void testAnimalBasics() {
    std::cout << "\n=== Testing Animal Basics ===\n";
    // const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    // meta->makeSound();
    // delete meta;
    delete j;
    delete i;
    std::cout << '\n';
}

void testDogBehavior() {
    std::cout << "\n=== Testing Dog Behavior ===\n";
    Dog d1;
    d1.makeSound();

    Dog d2 = d1;  // Copy constructor
    d2.makeSound();

    Dog d3;
    d3 = d1;  // Copy assignment operator
    d3.makeSound();
}

void testCatBehavior() {
    std::cout << "\n=== Testing Cat Behavior ===\n";
    Cat c1;
    c1.makeSound();

    Cat c2 = c1;  // Copy constructor
    c2.makeSound();

    Cat c3;
    c3 = c1;  // Copy assignment operator
    c3.makeSound();
}

void testAnimalArray() {
    std::cout << "\n=== Testing Animal Array ===\n";
    const size_t size = 10;
    Animal* beasts[size];

    // Populate array with Dogs and Cats
    for (size_t i = 0; i < size / 2; ++i) {
        beasts[i] = new Dog();
    }
    for (size_t i = size / 2; i < size; ++i) {
        beasts[i] = new Cat();
    }

    // Verify behavior
    for (size_t i = 0; i < size; ++i) {
        beasts[i]->makeSound();
    }

    // Clean up
    for (size_t i = 0; i < size; ++i) {
        delete beasts[i];
    }
}

void testBrainBehavior() {
    std::cout << "\n=== Testing Brain Behavior ===\n";
    Brain b;
    b.append("zero").append("first").append("second");

    std::cout << "Brain contents: " << b << std::endl;

    Brain b2 = b;  // Copy constructor
    std::cout << "Copied Brain contents: " << b2 << std::endl;

    Brain b3;
    b3.append("newIdea");
    b3 = b;  // Copy assignment operator
    std::cout << "Assigned Brain contents: " << b3 << std::endl;
}

int main() {
    // testAnimalBasics();
    testDogBehavior();
    testCatBehavior();
    testAnimalArray();
    testBrainBehavior();
    return 0;
}
