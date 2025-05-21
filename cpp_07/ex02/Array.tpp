#pragma once

// Default constructor
template <typename T>
Array<T>::Array() : _data(nullptr), _size(0) {}

// Size constructor
template <typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]()), _size(n) {}

template <typename T>
Array<T>::Array(const Array<T>& other)
    : _data(new T[other._size]), _size(other._size) {
    for (size_t i = 0; i < _size; ++i) _data[i] = other._data[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    if (this != &other) {
        delete[] _data;
        _size = other._size;
        _data = new T[_size];
        for (size_t i = 0; i < _size; ++i) _data[i] = other._data[i];
    }
    return *this;
}

template <typename T>
Array<T>::~Array() {
    delete[] _data;
}

// Subscript operator (mutable)
template <typename T>
T& Array<T>::operator[](size_t index) {
    if (index >= _size)
        throw std::out_of_range("Index out of bounds");
    return _data[index];
}

// Subscript operator (const)
template <typename T>
const T& Array<T>::operator[](size_t index) const {
    if (index >= _size)
        throw std::out_of_range("Index out of bounds");
    return _data[index];
}

// size()
template <typename T>
size_t Array<T>::size() const {
    return _size;
}

// Bonus: Iterators
template <typename T>
T* Array<T>::begin() {
    return _data;
}

template <typename T>
T* Array<T>::end() {
    return _data + _size;
}

template <typename T>
const T* Array<T>::begin() const {
    return _data;
}

template <typename T>
const T* Array<T>::end() const {
    return _data + _size;
}
