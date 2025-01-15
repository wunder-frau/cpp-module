
#include "ScalarConverter.hpp"

bool ScalarConverter::isPseudoLiteral(const std::string& literal) {
    return (literal == "nan" || literal == "+inf" || literal == "-inf" ||
            literal == "nanf" || literal == "+inff" || literal == "-inff");
}

double ScalarConverter::convertValue(const std::string& literal) {
    if (isPseudoLiteral(literal)) {
        return std::stod(literal);
    }

    throw std::invalid_argument(
        "Input must be a pseudo-literal, integer, float, double, or single "
        "character.");
}

void ScalarConverter::validateInput(const std::string& literal) {
    if (literal.empty()) {
        throw std::invalid_argument("Input cannot be empty");
    }
    for (char c : literal) {
        if (!std::isprint(static_cast<unsigned char>(c))) {
            throw std::invalid_argument(
                "Input contains non-printable characters");
        }
    }
    if (!isPseudoLiteral(literal)) {
        throw std::invalid_argument("Invalid literal format");
    }
}

void ScalarConverter::convert(const std::string& literal) {
    try {
        validateInput(literal);
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: Input value out of range for type conversion."
                  << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}