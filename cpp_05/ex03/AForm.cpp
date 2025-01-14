#include "AForm.hpp"

void AForm::validateGrade(int grade) const {
    if (grade < static_cast<int>(Grade::HIGHEST)) {
        throw GradeTooHighException("Grade is too high!");
    } else if (grade > static_cast<int>(Grade::LOWEST)) {
        throw GradeTooLowException("Grade is too low!");
    }
}

AForm::AForm(const std::string& name, int signGrade, int executeGrade,
             std::string target)
    : name_(name),
      isSigned_(false),
      signGrade_(signGrade),
      executeGrade_(executeGrade),
      target_(target) {
    validateGrade(signGrade_);
    validateGrade(executeGrade_);
}

std::string AForm::getName() const { return name_; }
bool AForm::isSigned() const { return isSigned_; }
int AForm::getSignGrade() const { return signGrade_; }
int AForm::getExecuteGrade() const { return executeGrade_; }
std::string AForm::getTarget() const { return target_; }
// void AForm::beSigned(const Bureaucrat& bureaucrat) {
//     if (bureaucrat.getGrade() > signGrade_) {
//         throw AForm::GradeTooHighException(
//             "Bureaucrat's grade is too low to sign the form.");
//     }
//     if (isSigned_) {
//         throw std::logic_error("Form is already signed.");
//     }
//     isSigned_ = true;
// }

bool AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > signGrade_) {
        throw AForm::GradeTooHighException(
            "Bureaucrat's grade is too low to sign the form.");
    }
    if (isSigned_) {
        return false;
    }
    isSigned_ = true;
    return true;
}

void AForm::execute(const Bureaucrat& executor) const {
    if (!isSigned_) {
        throw AForm::FormNotSignedException("Form is not signed.");
    }
    if (executor.getGrade() > executeGrade_) {
        throw AForm::GradeTooLowException("Grade is too low!");
    }
    doExecution();
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "Form Name: " << form.getName()
       << ", sign status: " << (form.isSigned() ? "true" : "false")
       << ", sign grade: " << form.getSignGrade()
       << ", execute grade: " << form.getExecuteGrade()
       << ", target: " << form.getTarget();
    return os;
}