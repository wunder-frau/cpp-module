#pragma once

#include <iostream>
#include <string>

#include "AForm.hpp"

class ShrubberyCreationForm final : public AForm {
public:
    ShrubberyCreationForm() = delete;
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm& other) = default;
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other) =
        delete;

    ~ShrubberyCreationForm() override = default;

protected:
    void doExecution() const override;

private:
    static const std::string& getTrees();
};
