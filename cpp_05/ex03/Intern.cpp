#include "Intern.hpp"
AForm* Intern::makeForm(const std::string& name, const std::string& target) {
    enum FormType { Shrubbery, Robotomy, Presidential, Invalid };
    static const std::string levels[] = {
        "shrubbery creation", "robotomy request", "presidential pardon"};

    FormType formType = Invalid;
    for (int i = 0; i < 3; ++i) {
        if (levels[i] == name) {
            formType = static_cast<FormType>(i);
            break;
        }
    }

    AForm* out = nullptr;
    switch (formType) {
        case Shrubbery:
            out = new ShrubberyCreationForm(target);
            break;
        case Robotomy:
            out = new RobotomyRequestForm(target);
            break;
        case Presidential:
            out = new PresidentialPardonForm(target);
            break;
        default:
            throw FormDoesntExistException("The form \"" + name +
                                           "\" doesn't exist!");
    }

    std::cout << "The form: \"" << *out
              << "\" has been successfully created.\n";
    return out;
};
