#pragma once

#include <deque>
#include <exception>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <chrono>
#include <iostream>
#include <sstream>
#include <algorithm>

#define COLOR_INFO "\033[1;34m"
#define COLOR_ERROR "\033[1;31m"
#define COLOR_BEFORE "\033[1;35m"
#define COLOR_AFTER "\033[1;32m"
#define COLOR_RESET "\033[0m"

inline bool DEBUG_MODE = false;

class InputError : public std::exception {
public:
    const char* what() const noexcept override;
};

template <typename Container, typename PairContainer>
class MergeInsertSorter {
protected:
    Container inputValues;
    Container sortedResult;
    Container pendingElements;
    Container insertionOrder;
    PairContainer pairs;
    double duration;
    bool hasLeftover;
    int leftoverElement;
    mutable std::ofstream debugFile;

public:
    MergeInsertSorter();
    MergeInsertSorter(const MergeInsertSorter& other);
    MergeInsertSorter& operator=(const MergeInsertSorter& other);
    virtual ~MergeInsertSorter();

    void loadInput(int argc, char** argv);
    void sort();
    void showBefore() const;
    void showAfter() const;
    void showDuration(const std::string& containerName) const;

protected:
    void makePairs();
    void handleLeftover(int value);
    void addPair(int a, int b);
    void sortPrimaryKeys();
    void insertSecondaryKeys();
    void recursiveMergeSort(typename PairContainer::iterator begin,
                            typename PairContainer::iterator end);
    void mergePairs(typename PairContainer::iterator begin,
                    typename PairContainer::iterator mid,
                    typename PairContainer::iterator end);
    Container generateJacobsthalSequence(size_t count);
    typename Container::iterator findInsertPosition(Container& sorted, int value);
    void logStep(const std::string& message, const std::string& tag = "[STEP]") const;
    void runCoreSorting();
};

// Explicit instantiations
extern template class MergeInsertSorter<std::vector<int>,
                                        std::vector<std::pair<int, int>>>;
extern template class MergeInsertSorter<std::deque<int>,
                                        std::deque<std::pair<int, int>>>;

#include "PmergeMe.tpp"  // Only template function bodies
