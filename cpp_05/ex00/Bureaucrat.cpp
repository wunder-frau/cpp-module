#include "Bureaucrat.hpp"

void Bureaucrat::validateGrade() const {
    if (grade_ < static_cast<int>(Grade::HIGHEST)) {
        throw GradeTooHighException("Grade is too high!");
    } else if (grade_ > static_cast<int>(Grade::LOWEST)) {
        throw GradeTooLowException("Grade is too low!");
    }
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : name_(name), grade_(grade) {
    validateGrade();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) & {
    if (this != &other) {
        grade_ = other.grade_;
    }
    return *this;
};

std::string Bureaucrat::getName() const noexcept { return name_; }

int Bureaucrat::getGrade() const noexcept { return grade_; }

void Bureaucrat::incrementGrade() {
    if (grade_ <= static_cast<int>(Grade::HIGHEST)) {
        throw GradeTooHighException("Grade is too high!");
    }
    --grade_;
}

void Bureaucrat::decrementGrade() {
    if (grade_ >= static_cast<int>(Grade::LOWEST)) {
        throw GradeTooLowException("Grade is too low!");
    }
    ++grade_;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    return os << bureaucrat.getName() << ", bureaucrat grade "
              << bureaucrat.getGrade();
};
