#pragma once
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <regex>
#include <string>

class ScalarConverter {
public:
    static double convertValue(const std::string& literal);
    static void printAllValues(double value);
    static void validateInput(const std::string& literal);
    static void convert(const std::string& literal);

private:
private:
    ScalarConverter() = delete;
    ScalarConverter(const ScalarConverter&) = delete;
    ScalarConverter& operator=(const ScalarConverter&) = delete;
    ~ScalarConverter() = delete;

    static bool isPseudoLiteral(const std::string& literal);
    static bool isInteger(const std::string& str);
    static bool isFloat(const std::string& str);
    static bool isDouble(const std::string& str);

    static void printChar(double value);
    static void printInt(double value);
    static void printFloat(double value);
    static void printDouble(double value);
};