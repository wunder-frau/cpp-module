#pragma once

#include <iostream>
#include <string>

inline constexpr int GRADE_HIGHEST = 1;
inline constexpr int GRADE_LOWEST = 150;

class Bureaucrat {
public:
    Bureaucrat() = delete;
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other) = default;
    Bureaucrat& operator=(const Bureaucrat& other) &;
    ~Bureaucrat() = default;

    class GradeTooHighException : public std::exception {
    public:
        const char* what() const noexcept override {
            return "Grade is too high!";
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const noexcept override {
            return "Grade is too low!";
        }
    };

    [[nodiscard]] std::string getName() const noexcept;
    [[nodiscard]] int getGrade() const noexcept;
    void incrementGrade();
    void decrementGrade();

private:
    const std::string name_;
    int grade_;
    void validateGrade() const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);