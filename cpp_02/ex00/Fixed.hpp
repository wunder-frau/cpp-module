#pragma once

#include <iostream>

class Fixed {
public:
    // Con- and destructors, assignements
    explicit Fixed();

    explicit Fixed(const Fixed&);

    Fixed& operator=(const Fixed&);

    ~Fixed();
    //

    // Members
    // Element access
    int getRawBits(void) const;

    // Modifiers
    void setRawBits(const int raw);
    //

private:
    static const int fract_bits_ = 8;
    int value_ = {};
};
