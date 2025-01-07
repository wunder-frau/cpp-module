#pragma once

#include <iostream>

class Fixed {
public:
    // Con- and destructors, assignements
    explicit Fixed();

    explicit Fixed(const int);
    explicit Fixed(const float);

    Fixed(const Fixed&);

    Fixed& operator=(const Fixed&);

    ~Fixed();
    //

    // Members
    // Element access
    int getRawBits(void) const;

    float toFloat(void) const;
    int toInt(void) const;

    // Modifiers
    void setRawBits(const int);
    //

private:
    static const uint8_t fract_bits_ = 8;
    int value_ = {};
};

// Non-members
// Overloads
std::ostream& operator<<(std::ostream&, const Fixed&);
//
