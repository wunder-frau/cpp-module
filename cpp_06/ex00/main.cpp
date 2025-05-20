#include "ScalarConverter.hpp"
// Test cases

// int main() {
//     std::string tests[] = {
//         "a",     "Z",          "!",           "0",
//         "42",    "-42",        "+123",        "4.2f",
//         "-4.2f", "+0.0f",      ".5f",         "+.1f",
//         "1.f",   "4.2",        "-4.2",        "0.0",
//         ".2",    "1.",         "+.3",         "nan",
//         "+inf",  "-inf",       "nanf",        "+inff",
//         "-inff", "",           "abc",         "42abc",
//         "4.2ff", "--42",       "4.2.2",       "999999999999999999999",
//         "31",    "32",         "126",         "127",
//         "128",   "2147483647", "-2147483648", "\x01",
//     };

//     for (const auto& t : tests) {
//         std::cout << "Test: \"" << t << "\"" << std::endl;
//         ScalarConverter::convert(t);
//         std::cout << "---------------------" << std::endl;
//     }
// }

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: ./ScalarConverter <literal>" << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}