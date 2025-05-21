#pragma once

#include <cstddef>  // for size_t
#include <iostream>

template <typename T, typename Func>
void iter(T* array, size_t length, Func func) {
    for (size_t i = 0; i < length; ++i) func(array[i]);
}

template <typename T>
void print(const T& item) {
    std::cout << item << " ";
}

template <typename T>
void mutate(T& item) {
    item = item + item;
}
