#include <iostream>
#include <string>

#include "PhoneBook.hpp"
int main(int argc, char **argv) {
    if (argc > 1) {
        std::cout << "This program doesn't require arguments. Remove this: "
                  << argv[1] << ". Run: ./phonebook" << std::endl;
        return 0;
    }
    PhoneBook phonebook;
    phonebook.run();
    return 0;
}