#pragma once

#include <iostream>

class Fixed {
public:
    // Con- and destructors, assignements
    explicit Fixed();

    explicit Fixed(const int);
    explicit Fixed(const float);

    Fixed(const Fixed&);

    ~Fixed();

    Fixed& operator=(const Fixed&);
    //

    // Overloads
    // In- and decrement
    Fixed& operator++(void);
    Fixed& operator--(void);

    Fixed operator++(int);
    Fixed operator--(int);

    // Arithmetic
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;

    // Comparisons
    bool operator==(const Fixed& other) const;

    bool operator>(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;

    //

    // Static members
    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);

    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
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
