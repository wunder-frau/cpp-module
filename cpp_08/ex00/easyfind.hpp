#pragma once

#include <iterator>

template <typename Container>
typename Container::iterator easyfind(Container& container, int value);

#include "easyfind.tpp"
