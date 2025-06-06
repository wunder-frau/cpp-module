#include <iostream>
#include <string>
#include "PmergeMe.hpp"

int main(int argc, char** argv) {
    if (argc > 1 && std::string(argv[1]) == "--debug") {
        DEBUG_MODE = true;
        --argc;
        ++argv;
    }

    try {
        MergeInsertSorter<std::vector<int>, std::vector<std::pair<int, int>>> vectorSorter;
        MergeInsertSorter<std::deque<int>, std::deque<std::pair<int, int>>> dequeSorter;

        vectorSorter.loadInput(argc, argv);
        dequeSorter.loadInput(argc, argv);

        vectorSorter.sort();
        dequeSorter.sort();

        vectorSorter.showBefore();
        vectorSorter.showAfter();
        vectorSorter.showDuration("std::vector");
        dequeSorter.showDuration("std::deque");

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
