#include "Fixed.hpp"

//: Con- and destructors, assignements
Fixed::Fixed() { std::cout << "Default constructor called" << std::endl; }

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    value_ = other.value_;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    value_ = other.value_;
    return *this;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }
//

//: Members
//: Element access
int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return value_;
}

//: Modifiers
void Fixed::setRawBits(const int raw) {
    std::cout << "setRawBits member function called" << std::endl;
    value_ = raw;
}
//
