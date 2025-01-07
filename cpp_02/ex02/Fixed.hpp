#pragma once

#include <iostream>

class Fixed {
public:
    // Con- and destructors, assignements {{{
    explicit Fixed();

    explicit Fixed(const int);
    explicit Fixed(const float);

    Fixed(const Fixed&);

    ~Fixed();

    Fixed& operator=(const Fixed&);
    //

    // Overloads {{{
    // In- and decrement
    inline Fixed& operator++(void) {
        ++value_;
        return *this;
    }
    inline Fixed& operator--(void) {
        --value_;
        return *this;
    }

    inline Fixed operator++(int) {
        const Fixed tmp = *this;
        operator++();
        return tmp;
    }
    inline Fixed operator--(int) {
        const Fixed tmp = *this;
        operator--();
        return tmp;
    }

    // Arithmetic
    inline Fixed operator+(const Fixed& other) const {
        return Fixed(toFloat() + other.toFloat());
    }
    inline Fixed operator-(const Fixed& other) const {
        return Fixed(toFloat() - other.toFloat());
    }
    inline Fixed operator*(const Fixed& other) const {
        return Fixed(toFloat() * other.toFloat());
    }
    inline Fixed operator/(const Fixed& other) const {
        return Fixed(toFloat() / other.toFloat());
    }

    // Comparisons
    inline auto operator==(const Fixed& other) const {
        return value_ == other.value_;
    }

    inline auto operator<=>(const Fixed& other) const {
        return value_ <=> other.value_;
    }

    //

    // Static members {{{
    inline static Fixed& min(Fixed& a, Fixed& b) { return a < b ? a : b; }
    inline static const Fixed& min(const Fixed& a, const Fixed& b) {
        return a < b ? a : b;
    }

    inline static Fixed& max(Fixed& a, Fixed& b) { return a > b ? a : b; }
    inline static const Fixed& max(const Fixed& a, const Fixed& b) {
        return a > b ? a : b;
    }
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
