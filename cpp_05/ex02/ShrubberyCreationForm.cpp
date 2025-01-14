#include "ShrubberyCreationForm.hpp"

#include <fstream>

std::string& getTrees();
const std::string& ShrubberyCreationForm::getTrees() {
    static const std::string trees =
        "+---------------------------------------------------------+\n"
        "|           *~*~  *~*~  *~*~                              |\n"
        "|       *~*~  *~*~  *~*~  *~*~                            |\n"
        "|   *~*~  *~*~  *~*~  *~*~  *~*~                          |\n"
        "|*~*~  *~*~  *~*~  *~*~  *~*~  *~*~                       |\n"
        "|   *~*~  *~*~  *~*~  *~*~  *~*~                          |\n"
        "|       *~*~  *~*~  *~*~  *~*~          *~*~  *~*~        |\n"
        "|           *~*~  *~*~  *~*~          *~*~  *~*~  *~*~    |\n"
        "|                 |||              *~*~  *~*~  *~*~       |\n"
        "|                 |||                   *~*~  *~*~        |\n"
        "|                 |||                    |||              |\n"
        "|                 |||                    |||              |\n"
        "|           , -=-~  .-^- _         , -=-~  .-^- _         |\n"
        "+---------------------------------------------------------+\n";
    return trees;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", 145, 137, target + "_shrubbery") {}

void ShrubberyCreationForm::doExecution() const {
    std::ofstream outFile(getTarget());
    if (!outFile.is_open()) {
        throw std::runtime_error("Failed to open file: " + getTarget());
    }

    outFile << getTrees();
};
