#include "Fixed.hpp"

int main(void) {
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    // Default tests
    std::cout << "Initial values:" << std::endl;
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << "Max of a and b:" << std::endl;
    std::cout << Fixed::max(a, b) << '\n' << std::endl;

    // Addition test
    std::cout << "Addition: Fixed(5.05f) + Fixed(2)" << std::endl;
    std::cout << (Fixed(5.05f) + Fixed(2)) << std::endl;

    // Subtraction test
    std::cout << "Subtraction: Fixed(5.05f) - Fixed(2)" << std::endl;
    std::cout << (Fixed(5.05f) - Fixed(2)) << std::endl;

    // Division test
    std::cout << "Division: Fixed(5.05f) / Fixed(2)" << std::endl;
    std::cout << (Fixed(5.05f) / Fixed(2)) << std::endl;

    // Min function test
    std::cout << "Min of Fixed(3.03f) and Fixed(7):" << std::endl;
    std::cout << Fixed::min(Fixed(3.03f), Fixed(7)) << std::endl;

    // Max function test
    std::cout << "Max of Fixed(3.03f) and Fixed(7):" << std::endl;
    std::cout << Fixed::max(Fixed(3.03f), Fixed(7)) << std::endl;

    // More comparisons
    std::cout << "Comparisons:" << std::endl;
    std::cout << (Fixed(1) > Fixed(0)) << ": 1\n"
              << (Fixed(1) >= Fixed(0)) << ": 1\n"
              << (Fixed(0) > Fixed(0)) << ": 0\n"
              << (Fixed(0) >= Fixed(0)) << ": 1\n"
              << (Fixed(0) <= Fixed(1)) << ": 1\n"
              << (Fixed(0) < Fixed(0)) << ": 0\n";

    return 0;
}