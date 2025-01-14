#pragma once

#include <exception>
#include <iostream>
#include <string>

#include "AForm.hpp"

class AForm;

class Bureaucrat {
    enum class Grade { HIGHEST = 1, LOWEST = 150 };

public:
    class GradeTooHighException : public std::out_of_range {
    public:
        using std::out_of_range::out_of_range;
    };

    class GradeTooLowException : public std::out_of_range {
    public:
        using std::out_of_range::out_of_range;
    };

public:
    Bureaucrat() = delete;
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other) = default;
    Bureaucrat& operator=(const Bureaucrat& other) &;
    ~Bureaucrat() = default;

    [[nodiscard]] std::string getName() const noexcept;
    [[nodiscard]] int getGrade() const noexcept;
    void incrementGrade();
    void decrementGrade();
    void signForm(AForm& f);
    void executeForm(const AForm& form) const;

private:
    const std::string name_;
    int grade_;
    void validateGrade() const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);