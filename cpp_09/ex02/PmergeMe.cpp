// PmergeMe.cpp
#include "PmergeMe.hpp"

template class MergeInsertSorter<std::vector<int>,
                                 std::vector<std::pair<int, int>>>;
template class MergeInsertSorter<std::deque<int>,
                                 std::deque<std::pair<int, int>>>;
