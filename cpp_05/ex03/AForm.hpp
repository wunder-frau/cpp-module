#pragma once

#include <exception>
#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
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

    class FormNotSignedException : public std::logic_error {
    public:
        using std::logic_error::logic_error;
    };

    AForm() = delete;
    AForm(const std::string& name, int signGrade, int executeGrade,
          std::string target_);
    AForm(const AForm& other) = default;
    AForm& operator=(const AForm& other) = delete;

    virtual ~AForm() = default;

    // Getters
    std::string getName() const;
    bool isSigned() const;
    int getSignGrade() const;
    int getExecuteGrade() const;
    std::string getTarget() const;

    // Methods
    bool beSigned(const Bureaucrat& b);
    void execute(const Bureaucrat& executor) const;

protected:
    virtual void doExecution() const = 0;

private:
    const std::string name_;
    bool isSigned_;
    const int signGrade_;
    const int executeGrade_;
    const std::string target_;
    void validateGrade(int grade) const;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);