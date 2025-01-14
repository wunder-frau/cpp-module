#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("RobotomyRequestForm", 72, 45, target) {}

void RobotomyRequestForm::doExecution() const {
    static bool isSuccess = false;
    std::cout << " DRILLING NOISES \n";
    if (isSuccess) {
        std::cout << getTarget() << " has been robotomized successfully.\n";
    } else {
        std::cout << getTarget() << " has failed to robotomize.\n";
    }
    isSuccess = !isSuccess;
};
