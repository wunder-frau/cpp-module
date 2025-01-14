// #include <memory>

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat john("John", 2);
        PresidentialPardonForm form("Alice");

        std::cout << form << std::endl;
        john.signForm(form);
        std::cout << form << std::endl;
        john.executeForm(form);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
