// main.cpp
#include <iostream>

#include "PmergeMe.hpp"

using VectorSorter =
    MergeInsertSorter<std::vector<int>, std::vector<std::pair<int, int>>>;
using DequeSorter =
    MergeInsertSorter<std::deque<int>, std::deque<std::pair<int, int>>>;

int main(int argc, char** argv) {
    try {
        VectorSorter vectorSort;
        vectorSort.loadInput(argc, argv);
        vectorSort.showBefore();
        vectorSort.sort();
        vectorSort.showAfter();
        vectorSort.showDuration("std::vector");

        std::cout << std::endl;

        DequeSorter dequeSort;
        dequeSort.loadInput(argc, argv);
        dequeSort.sort();
        dequeSort.showDuration("std::deque");

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
