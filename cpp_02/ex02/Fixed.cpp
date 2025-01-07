#include "Fixed.hpp"

#include <cmath>

// Con- and destructors, assignements
Fixed::Fixed() {
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : value_(value << fract_bits_) {
    // std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
    : value_(static_cast<int>(std::roundf(value * (1 << fract_bits_)))) {
    // std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
    // std::cout << "Copy constructor called" << std::endl;
    value_ = other.value_;
}

Fixed& Fixed::operator=(const Fixed& other) {
    // std::cout << "Copy assignment operator called" << std::endl;
    value_ = other.value_;
    return *this;
}

Fixed::~Fixed() {
    // std::cout << "Destructor called" << std::endl;
}
//

// Members
// Element access
int Fixed::getRawBits(void) const {
    // std::cout << "getRawBits member function called" << std::endl;
    return value_;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(value_) / (1 << fract_bits_);
}

int Fixed::toInt(void) const { return value_ >> fract_bits_; }

// Modifiers
void Fixed::setRawBits(const int raw) {
    // std::cout << "setRawBits member function called" << std::endl;
    value_ = raw;
}
//

// Non-members
// Overloads
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}
//
