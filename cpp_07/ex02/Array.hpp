#pragma once

#include <cstddef>
#include <stdexcept>

template <typename T>
class Array {
private:
    T* _data;
    size_t _size;

public:
    Array();
    Array(unsigned int n);  // size constructor
    Array(const Array& other);
    Array& operator=(const Array& other);
    ~Array();

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    size_t size() const;

    // Bonus: iterators
    T* begin();
    T* end();
    const T* begin() const;
    const T* end() const;
};

#include "Array.tpp"
