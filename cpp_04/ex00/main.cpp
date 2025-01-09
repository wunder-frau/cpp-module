#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"

int main() {
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound();
        j->makeSound();
        meta->makeSound();
        delete meta;
        delete j;
        delete i;
        std::cout << '\n';
    }
    {
        // === Test 1: Default Constructor and Basic Functionality ===
        std::cout
            << "=== Test 1: Default Constructor and Basic Functionality ===\n";
        WrongAnimal wrongAnimal;
        std::cout << "Type: " << wrongAnimal.getType() << "\n";
        wrongAnimal.makeSound();

        // === Test 2: WrongCat Direct Instantiation ===
        std::cout << "\n=== Test 2: WrongCat Direct Instantiation ===\n";
        WrongCat wrongCat;
        std::cout << "Type: " << wrongCat.getType() << "\n";
        wrongCat.makeSound();

        // === Test 3: Polymorphism (WrongAnimal Pointer to WrongCat) ===
        std::cout << "\n=== Test 3: Polymorphism (WrongAnimal Pointer to "
                     "WrongCat) ===\n";
        WrongAnimal* polyWrongAnimal = new WrongCat();
        std::cout << "Type: " << polyWrongAnimal->getType() << "\n";
        polyWrongAnimal->makeSound();  // Calls WrongAnimal's makeSound due to
                                       // lack of virtual function
        delete polyWrongAnimal;

        // === Test 4: Copy Constructor for WrongAnimal ===
        std::cout << "\n=== Test 4: Copy Constructor for WrongAnimal ===\n";
        WrongAnimal anotherWrongAnimal(wrongAnimal);  // Copy constructor
        std::cout << "Type: " << anotherWrongAnimal.getType() << "\n";
        anotherWrongAnimal.makeSound();

        // === Test 5: Copy Constructor for WrongCat ===
        std::cout << "\n=== Test 5: Copy Constructor for WrongCat ===\n";
        WrongCat anotherWrongCat(wrongCat);  // Copy constructor
        std::cout << "Type: " << anotherWrongCat.getType() << "\n";
        anotherWrongCat.makeSound();

        // === Test 6: Assignment Operator for WrongAnimal ===
        std::cout << "\n=== Test 6: Assignment Operator for WrongAnimal ===\n";
        WrongAnimal assignedWrongAnimal;
        assignedWrongAnimal = wrongAnimal;  // Assignment operator
        std::cout << "Type: " << assignedWrongAnimal.getType() << "\n";
        assignedWrongAnimal.makeSound();

        // === Test 7: Assignment Operator for WrongCat ===
        std::cout << "\n=== Test 7: Assignment Operator for WrongCat ===\n";
        WrongCat assignedWrongCat;
        assignedWrongCat = wrongCat;  // Assignment operator
        std::cout << "Type: " << assignedWrongCat.getType() << "\n";
        assignedWrongCat.makeSound();

        // === Test 8: Array of WrongAnimal Pointers ===
        std::cout << "\n=== Test 8: Array of WrongAnimal Pointers ===\n";
        const size_t numAnimals = 2;
        WrongAnimal* wrongAnimals[numAnimals];
        wrongAnimals[0] = new WrongAnimal();
        wrongAnimals[1] = new WrongCat();

        for (size_t i = 0; i < numAnimals; ++i) {
            std::cout << "Type: " << wrongAnimals[i]->getType() << "\n";
            wrongAnimals[i]
                ->makeSound();  // All will call WrongAnimal::makeSound
        }

        for (size_t i = 0; i < numAnimals; ++i) {
            delete wrongAnimals[i];
        }
    }
    return 0;
}
