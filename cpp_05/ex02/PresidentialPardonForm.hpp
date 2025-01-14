#pragma once
#include "AForm.hpp"

class PresidentialPardonForm final : public AForm {  // Marked as final
public:
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm& other) = default;
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other) =
        delete;
    ~PresidentialPardonForm() override = default;

protected:
    void doExecution() const override;
};
