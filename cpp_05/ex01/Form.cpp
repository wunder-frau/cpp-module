#include "Form.hpp"

void Form::validateGrade(int grade) const {
    if (grade < static_cast<int>(Grade::HIGHEST)) {
        throw GradeTooHighException("Grade is too high!");
    } else if (grade > static_cast<int>(Grade::LOWEST)) {
        throw GradeTooLowException("Grade is too low!");
    }
}

Form::Form(const std::string& name, int signGrade, int executeGrade)
    : name_(name), signGrade_(signGrade), executeGrade_(executeGrade) {
    validateGrade(signGrade_);
    validateGrade(executeGrade_);
}

std::string Form::getName() const { return name_; }
bool Form::isSigned() const { return isSigned_; }
int Form::getSignGrade() const { return signGrade_; }
int Form::getExecuteGrade() const { return executeGrade_; }
void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > signGrade_) {
        throw std::runtime_error(
            "Bureaucrat's grade is too low to sign the form.");
    }
    if (isSigned_) {
        throw std::logic_error("Form is already signed.");
    }
    isSigned_ = true;
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form Name: " << form.getName()
       << ", Signed: " << (form.isSigned() ? "Yes" : "True")
       << ", Sign Grade: " << form.getSignGrade()
       << ", Execute Grade: " << form.getExecuteGrade();
    return os;
}