#include "PmergeMe.hpp"

const char* InputError::what() const noexcept {
    std::cerr << COLOR_ERROR << "[ERROR] " << COLOR_RESET;
    return "Invalid input detected.";
}

// Explicit template instantiations
template class MergeInsertSorter<std::vector<int>,
                                 std::vector<std::pair<int, int>>>;
template class MergeInsertSorter<std::deque<int>,
                                 std::deque<std::pair<int, int>>>;
