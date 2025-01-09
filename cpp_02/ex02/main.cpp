#include "Fixed.hpp"

int main(void) {
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max(a, b) << '\n' << std::endl;

    std::cout << (Fixed(5.05f) + Fixed(2)) << std::endl;
    std::cout << (Fixed(1) > Fixed(0)) << ": 1\n"
              << (Fixed(1) >= Fixed(0)) << ": 1\n"
              << (Fixed(0) > Fixed(0)) << ": 0\n"
              << (Fixed(0) >= Fixed(0)) << ": 1\n"
              << (Fixed(0) <= Fixed(1)) << ": 1\n"
              << (Fixed(0) < Fixed(0)) << ": 0\n";

    return 0;
}
