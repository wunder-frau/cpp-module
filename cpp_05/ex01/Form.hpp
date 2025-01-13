#pragma once

#include <exception>
#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
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

    Form() = delete;
    Form(const std::string& name, int signGrade, int executeGrade);
    Form(const Form& other) = default;
    Form& operator=(const Form& other) = delete;

    ~Form() = default;
    std::string getName() const;
    bool isSigned() const;
    int getSignGrade() const;
    int getExecuteGrade() const;

    void beSigned(const Bureaucrat& b);

private:
    const std::string name_;
    bool isSigned_;
    const int signGrade_;
    const int executeGrade_;
    void validateGrade(int grade) const;
};

std::ostream& operator<<(std::ostream& os, const Form& form);