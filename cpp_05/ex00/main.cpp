#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat alice("Alice", 2);
        std::cout << alice << std::endl;

        alice.incrementGrade();  // Promotes Alice to grade 1
        std::cout << "After promotion: " << alice << std::endl;

        alice.incrementGrade();  // Attempts to promote Alice beyond grade 1
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat bob("Bob", 149);
        std::cout << bob << std::endl;

        bob.decrementGrade();  // Demotes Bob to grade 150
        std::cout << "After demotion: " << bob << std::endl;

        bob.decrementGrade();  // Attempts to demote Bob beyond grade 150
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
