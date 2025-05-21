#pragma once

#include <concepts>  // For std::totally_ordered

// Swap: requires copyable and assignable types only
template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// Min: returns the second if equal
template <std::totally_ordered T>
T const& min(T const& a, T const& b) {
    return (a < b) ? a : b;
}

// Max: returns the second if equal
template <std::totally_ordered T>
T const& max(T const& a, T const& b) {
    return (a > b) ? a : b;
}
