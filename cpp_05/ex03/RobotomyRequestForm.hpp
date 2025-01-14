#pragma once

#include "AForm.hpp"

class RobotomyRequestForm final : public AForm {
public:
    RobotomyRequestForm() = delete;
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(const RobotomyRequestForm& other) = default;
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other) = delete;
    ~RobotomyRequestForm() override = default;

protected:
    void doExecution() const override;
};