#include <iostream>
#include <string>

#include "PhoneBook.hpp"
int main() {
    PhoneBook phonebook;
    std::string command;

    while (true) {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, command)) {
            std::cout
                << "\nThis means EOF (Ctrl+D) or error occurred. Exiting..."
                << std::endl;
            return 0;
        }

        if (!phonebook.run(command)) {
            break;
        }
    }

    return 0;
}
