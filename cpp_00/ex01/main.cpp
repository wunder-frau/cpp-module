#include "PhoneBook.hpp"

int main() {
    PhoneBook phonebook;
    std::string command;

    while (true) {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        if (!phonebook.Run(command)) {
            break;
        }
    }

    return 0;
}
