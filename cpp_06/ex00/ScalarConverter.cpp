
#include "ScalarConverter.hpp"

bool ScalarConverter::isPseudoLiteral(const std::string& literal) {
    return (literal == "nan" || literal == "+inf" || literal == "-inf" ||
            literal == "nanf" || literal == "+inff" || literal == "-inff");
}

bool ScalarConverter::isInteger(const std::string& str) {
    std::regex intRegex("[-+]?[0-9]+");
    return std::regex_match(str, intRegex);
}

bool ScalarConverter::isFloat(const std::string& str) {
    std::regex floatRegex(R"([-+]?(?:[0-9]+\.[0-9]*|\.[0-9]+)f)");
    return std::regex_match(str, floatRegex);
}

bool ScalarConverter::isDouble(const std::string& str) {
    std::regex doubleRegex(R"([-+]?(?:[0-9]+\.[0-9]*|\.[0-9]+))");
    return std::regex_match(str, doubleRegex);
}

void ScalarConverter::printInt(double value) {
    if (value < std::numeric_limits<int>::min() ||
        value > std::numeric_limits<int>::max() || std::isnan(value)) {
        std::cout << "int: impossible" << std::endl;
    } else {
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    }
}

void ScalarConverter::printFloat(double value) {
    float f = static_cast<float>(value);
    if (std::isinf(f)) {
        std::cout << "float: impossible" << std::endl;
    } else if (static_cast<double>(f) != value &&
               std::fabs(value) > 1000000.0) {
        std::cout << "float: approx " << std::fixed << std::setprecision(1) << f
                  << "f" << std::endl;
    } else {
        std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f"
                  << std::endl;
    }
}

void ScalarConverter::printDouble(double value) {
    std::cout << "double: " << std::fixed << std::setprecision(1) << value
              << std::endl;
}

void ScalarConverter::printChar(double value) {
    if (value < 0 || value > 127 || std::isnan(value)) {
        std::cout << "char: impossible" << std::endl;
    } else if (!std::isprint(static_cast<int>(value))) {
        std::cout << "char: Non displayable" << std::endl;
    } else {
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    }
}

void ScalarConverter::printAllValues(double value) {
    printInt(value);
    printFloat(value);
    printDouble(value);
    printChar(value);
}

double ScalarConverter::convertValue(const std::string& literal) {
    if (isPseudoLiteral(literal)) {
        return std::stod(literal);
    }
    if (isInteger(literal)) {
        return std::stoi(literal);
    }
    if (isFloat(literal)) {
        return std::stof(literal);
    }
    if (isDouble(literal)) {
        return std::stod(literal);
    }
    if (literal.length() == 1 && !std::isdigit(literal[0])) {
        return static_cast<double>(literal[0]);
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
    if (!isPseudoLiteral(literal) && !isInteger(literal) && !isFloat(literal) &&
        !isDouble(literal) &&
        !(literal.length() == 1 && std::isprint(literal[0]))) {
        throw std::invalid_argument("Invalid literal format");
    }
}

void ScalarConverter::convert(const std::string& literal) {
    try {
        validateInput(literal);
        double value = convertValue(literal);
        printAllValues(value);
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: Input value out of range for type conversion."
                  << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}