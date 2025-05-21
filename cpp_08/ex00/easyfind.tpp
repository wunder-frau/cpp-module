#pragma once

#include <algorithm>
#include <ranges>
#include <stdexcept>

template <typename Container>
typename Container::iterator easyfind(Container& container, int value) {
    typename Container::iterator it = std::ranges::find(container, value);
    if (it == container.end())
        throw std::runtime_error("Value not found in container.");
    return it;
}
