
#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"
int main() {
    try {
        Bureaucrat alice("Alice", 50);
        Form taxForm("Tax Form", 45, 30);

        std::cout << alice << std::endl;
        std::cout << taxForm << std::endl;

        alice.signForm(taxForm);  // Should throw std::runtime_error

        std::cout << taxForm << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat bob("Bob", 20);
        Form contract("Employment Contract", 30, 20);

        std::cout << bob << std::endl;
        std::cout << contract << std::endl;

        bob.signForm(contract);  // Should succeed

        std::cout << contract << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}