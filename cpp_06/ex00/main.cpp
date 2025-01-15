#include "ScalarConverter.hpp"
// Test cases
//         "42",           // Integer
//         "-42",          // Negative integer
//         "4.2",          // Double
//         "4.2f",         // Float
//         "nan",          // Pseudo-literal (double)
//         "nanf",         // Pseudo-literal (float)
//         "+inf",         // Positive infinity (double)
//         "-inf",         // Negative infinity (double)
//         "+inff",        // Positive infinity (float)
//         "-inff",        // Negative infinity (float)
//         "a",            // Single character
//         "\x01",         // Non-displayable character
//         "2147483647",   // Max int
//         "-2147483648",  // Min int
//         "2147483648",   // Out-of-range int
//         "invalid"       // Invalid input
int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: ./ScalarConverter <literal>" << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}