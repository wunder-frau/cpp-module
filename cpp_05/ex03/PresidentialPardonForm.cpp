#include "PresidentialPardonForm.hpp"

#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("PresidentialPardonForm", 25, 5, std::move(target)) {}

void PresidentialPardonForm::doExecution() const {
    std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox.\n";
}
