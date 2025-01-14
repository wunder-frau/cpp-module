#include <iostream>

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    {
        Intern intern;

        try {
            // Test 1: Create a ShrubberyCreationForm
            AForm* form1 = intern.makeForm("shrubbery creation", "garden");
            delete form1;  // Clean up memory
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

        try {
            // Test 2: Create a RobotomyRequestForm
            AForm* form2 = intern.makeForm("robotomy request", "robot");
            delete form2;  // Clean up memory
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

        try {
            // Test 3: Create a PresidentialPardonForm
            AForm* form3 = intern.makeForm("presidential pardon", "John Doe");
            delete form3;  // Clean up memory
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

        try {
            // Test 4: Attempt to create a non-existent form
            AForm* form4 = intern.makeForm("invalid form", "nobody");
            delete form4;  // This line won't execute
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
    // ======================================================
    // Test 1: Bureaucrat with insufficient grade attempts to sign
    // RobotomyRequestForm
    // ======================================================
    {
        std::cout << "===== Test 1: Insufficient Grade to Sign "
                     "RobotomyRequestForm =====\n";
        try {
            Bureaucrat bob("Bob", 150);
            RobotomyRequestForm form("Charlie");
            std::cout << form << "\n\n";
            bob.signForm(form);
            std::cout << "\n" << form << "\n\n";
        } catch (const std::exception& e) {
            std::cerr << "Exception in Test 1: " << e.what() << "\n";
        }
        std::cout << "========================================================="
                     "==========\n\n";
    }

    // ======================================================
    // Test 2: Bureaucrat attempts to execute an unsigned PresidentialPardonForm
    // ======================================================
    {
        std::cout << "===== Test 2: Executing an Unsigned "
                     "PresidentialPardonForm =====\n";
        try {
            Bureaucrat alice("Alice", 5);
            PresidentialPardonForm form("Dave");
            std::cout << form << "\n\n";
            alice.executeForm(form);
        } catch (const std::exception& e) {
            std::cerr << "Exception in Test 2: " << e.what() << "\n";
        }
        std::cout << "========================================================="
                     "==========\n\n";
    }

    // ======================================================
    // Test 3: Bureaucrat with insufficient grade attempts to execute
    // RobotomyRequestForm
    // ======================================================
    {
        std::cout << "===== Test 3: Insufficient Grade to Execute "
                     "RobotomyRequestForm =====\n";
        try {
            Bureaucrat charlie("Charlie", 50);
            RobotomyRequestForm form("Eve");
            Bureaucrat alice("Alice", 1);
            alice.signForm(form);
            std::cout << "\n" << form << "\n\n";
            charlie.executeForm(form);
        } catch (const std::exception& e) {
            std::cerr << "Exception in Test 3: " << e.what() << "\n";
        }
        std::cout << "========================================================="
                     "==========\n\n";
    }

    // ======================================================
    // Test 4: Bureaucrat with insufficient grade attempts to execute an
    // unsigned PresidentialPardonForm
    // ======================================================
    {
        std::cout << "===== Test 4: Insufficient Grade to Execute an Unsigned "
                     "PresidentialPardonForm =====\n";
        try {
            Bureaucrat dave("Dave", 10);
            PresidentialPardonForm form("Frank");
            std::cout << form << "\n\n";
            dave.executeForm(form);
        } catch (const std::exception& e) {
            std::cerr << "Exception in Test 4: " << e.what() << "\n";
        }
        std::cout << "========================================================="
                     "==========\n\n";
    }

    // ======================================================
    // Test 5: Bureaucrat with sufficient grade signs but insufficient grade
    // executes RobotomyRequestForm
    // ======================================================
    {
        std::cout << "===== Test 5: Sign with Sufficient Grade but Execute "
                     "with Insufficient Grade =====\n";
        try {
            Bureaucrat alice("Alice", 1);
            Bureaucrat eve("Eve", 50);
            RobotomyRequestForm form("Grace");
            std::cout << form << "\n\n";
            alice.signForm(form);
            std::cout << "\n" << form << "\n\n";
            eve.executeForm(form);
        } catch (const std::exception& e) {
            std::cerr << "Exception in Test 5: " << e.what() << "\n";
        }
        std::cout << "========================================================="
                     "==========\n\n";
    }

    {
        try {
            Bureaucrat alice("Alice", 1);
            ShrubberyCreationForm form("Home");
            std::cout << form << "\n\n";
            alice.signForm(form);
            std::cout << "\n" << form << "\n\n";
            form.execute(alice);

            std::cout << "\nShrubbery has been created successfully in "
                         "'Home_shrubbery'.\n";
        } catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << "\n";
        }
    }
    return 0;
}
