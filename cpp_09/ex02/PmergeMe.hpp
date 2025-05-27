// PmergeMe.hpp
#pragma once

#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <deque>
#include <exception>
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#define COLOR_INFO "\033[1;34m"    // Blue
#define COLOR_ERROR "\033[1;31m"   // Red
#define COLOR_BEFORE "\033[1;35m"  // Magenta
#define COLOR_AFTER "\033[1;32m"   // Green
#define COLOR_RESET "\033[0m"

// Global debug flag (can be toggled in main.cpp)
inline bool DEBUG_MODE = false;

class InputError : public std::exception {
public:
    const char* what() const noexcept override {
        std::cerr << COLOR_ERROR << "[ERROR] " << COLOR_RESET;
        return "Invalid input detected.";
    }
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
    bool hasLeftover = false;
    int leftoverElement = 0;
    mutable std::ofstream debugFile;

public:
    MergeInsertSorter() {
        if (DEBUG_MODE)
            debugFile.open("debug.log");
    }
    virtual ~MergeInsertSorter() {
        if (debugFile.is_open())
            debugFile.close();
    }

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
    typename Container::iterator findInsertPosition(Container& sorted,
                                                    int value);
    void logStep(const std::string& message,
                 const std::string& tag = "[STEP]") const;
    void runCoreSorting();
};

extern template class MergeInsertSorter<std::vector<int>,
                                        std::vector<std::pair<int, int>>>;
extern template class MergeInsertSorter<std::deque<int>,
                                        std::deque<std::pair<int, int>>>;

#include <iomanip>  // For debug output formatting

template <typename Container, typename PairContainer>
void MergeInsertSorter<Container, PairContainer>::logStep(
    const std::string& message, const std::string& tag) const {
    if (DEBUG_MODE) {
        std::string color = COLOR_INFO;
        if (tag == "[DEBUG]")
            color = "\033[1;36m";  // Cyan
        else if (tag == "[STEP]")
            color = "\033[1;33m";  // Yellow
        else if (tag == "[ERROR]")
            color = COLOR_ERROR;

        std::cout << color << tag << COLOR_RESET << " " << message << std::endl;

        if (debugFile.is_open()) {
            debugFile << tag << " " << message << std::endl;
        }
    }
}

template <typename Container, typename PairContainer>
void MergeInsertSorter<Container, PairContainer>::loadInput(int argc,
                                                            char** argv) {
    logStep("loadInput(argc = " + std::to_string(argc) + ")", "[DEBUG]");
    if (argc < 2)
        throw InputError();

    for (int i = 1; i < argc; ++i) {
        std::string arg(argv[i]);
        std::replace(arg.begin(), arg.end(), ',', ' ');
        std::stringstream ss(arg);
        std::string token;

        while (ss >> token) {
            for (char c : token) {
                if (!std::isdigit(c))
                    throw InputError();
            }
            int val = std::atoi(token.c_str());
            if (val < 0)
                throw InputError();
            inputValues.push_back(val);
        }
    }

    logStep("Input loaded: " + std::to_string(inputValues.size()) + " elements",
            "[STEP]");
}

template <typename Container, typename PairContainer>
void MergeInsertSorter<Container, PairContainer>::handleLeftover(int value) {
    leftoverElement = value;
    hasLeftover = true;
    logStep("Leftover element detected: " + std::to_string(leftoverElement));
}

template <typename Container, typename PairContainer>
void MergeInsertSorter<Container, PairContainer>::addPair(int a, int b) {
    if (a < b)
        std::swap(a, b);
    pairs.push_back(std::make_pair(a, b));
    logStep("Pair formed: (" + std::to_string(a) + ", " + std::to_string(b) +
            ")");
}

template <typename Container, typename PairContainer>
void MergeInsertSorter<Container, PairContainer>::makePairs() {
    logStep("makePairs() called", "[DEBUG]");
    auto it = inputValues.begin();
    hasLeftover = false;
    pairs.clear();
    while (it != inputValues.end()) {
        int first = *it++;
        if (it == inputValues.end()) {
            handleLeftover(first);
            break;
        }
        int second = *it++;
        addPair(first, second);
    }
}

template <typename Container, typename PairContainer>
void MergeInsertSorter<Container, PairContainer>::sortPrimaryKeys() {
    logStep("sortPrimaryKeys() called", "[DEBUG]");
    recursiveMergeSort(pairs.begin(), pairs.end());
    for (const auto& [first, second] : pairs) {
        sortedResult.push_back(first);
        pendingElements.push_back(second);
    }

    std::string sorted, pending;
    for (auto val : sortedResult) sorted += std::to_string(val) + " ";
    for (auto val : pendingElements) pending += std::to_string(val) + " ";
    logStep("Sorted primary keys: " + sorted);
    logStep("Pending elements: " + pending);
}

template <typename Container, typename PairContainer>
void MergeInsertSorter<Container, PairContainer>::recursiveMergeSort(
    typename PairContainer::iterator begin,
    typename PairContainer::iterator end) {
    logStep("recursiveMergeSort(begin, end) called with distance = " +
                std::to_string(std::distance(begin, end)),
            "[DEBUG]");
    if (std::distance(begin, end) <= 1)
        return;
    auto mid = begin + (end - begin) / 2;
    recursiveMergeSort(begin, mid);
    recursiveMergeSort(mid, end);
    mergePairs(begin, mid, end);
}

template <typename Container, typename PairContainer>
void MergeInsertSorter<Container, PairContainer>::mergePairs(
    typename PairContainer::iterator begin,
    typename PairContainer::iterator mid,
    typename PairContainer::iterator end) {
    logStep("mergePairs(begin, mid, end) called", "[DEBUG]");
    PairContainer temp;
    auto left = begin;
    auto right = mid;

    while (left != mid && right != end) {
        if (left->first <= right->first)
            temp.push_back(*left++);
        else
            temp.push_back(*right++);
    }
    temp.insert(temp.end(), left, mid);
    temp.insert(temp.end(), right, end);
    std::copy(temp.begin(), temp.end(), begin);
}

template <typename Container, typename PairContainer>
typename Container::iterator
MergeInsertSorter<Container, PairContainer>::findInsertPosition(
    Container& sorted, int value) {
    logStep("findInsertPosition(value = " + std::to_string(value) + ")",
            "[DEBUG]");
    return std::lower_bound(sorted.begin(), sorted.end(), value);
}

template <typename Container, typename PairContainer>
Container
MergeInsertSorter<Container, PairContainer>::generateJacobsthalSequence(
    size_t count) {
    logStep("generateJacobsthalSequence(count = " + std::to_string(count) + ")",
            "[DEBUG]");
    Container sequence;
    if (count == 0)
        return sequence;

    sequence.push_back(1);
    for (size_t i = 2;; ++i) {
        size_t j = (1 << i) - ((i % 2 == 0) ? 1 : -1);
        j /= 3;
        if (j >= count)
            break;
        sequence.push_back(j);
    }

    Container fullOrder;
    for (auto v : sequence) fullOrder.push_back(v - 1);

    for (size_t i = 0; i < count; ++i)
        if (std::find(fullOrder.begin(), fullOrder.end(), i) == fullOrder.end())
            fullOrder.push_back(i);

    return fullOrder;
}

template <typename Container, typename PairContainer>
void MergeInsertSorter<Container, PairContainer>::insertSecondaryKeys() {
    logStep("insertSecondaryKeys() called", "[DEBUG]");
    insertionOrder = generateJacobsthalSequence(pendingElements.size());
    std::set<size_t> inserted;

    for (size_t i : insertionOrder) {
        if (i >= pendingElements.size() || inserted.count(i))
            continue;
        inserted.insert(i);

        int val = pendingElements[i];
        sortedResult.insert(findInsertPosition(sortedResult, val), val);
        logStep("Inserted " + std::to_string(val) + " into sorted sequence");
    }

    if (hasLeftover) {
        sortedResult.insert(findInsertPosition(sortedResult, leftoverElement),
                            leftoverElement);
        logStep("Inserted leftover element: " +
                std::to_string(leftoverElement));
    }
}
template <typename Container, typename PairContainer>
void MergeInsertSorter<Container, PairContainer>::sort() {
    logStep("sort() called", "[DEBUG]");

    if (inputValues.empty())
        throw InputError();

    if (inputValues.size() == 1) {
        sortedResult.push_back(inputValues[0]);
        duration = 0;
        return;
    }

    auto start = std::chrono::high_resolution_clock::now();
    runCoreSorting();
    auto end = std::chrono::high_resolution_clock::now();

    duration = std::chrono::duration<double, std::micro>(end - start).count();
    logStep("Total sort time: " + std::to_string(duration) + " us");
}

template <typename Container, typename PairContainer>
void MergeInsertSorter<Container, PairContainer>::runCoreSorting() {
    makePairs();
    sortPrimaryKeys();
    insertSecondaryKeys();
}

template <typename Container, typename PairContainer>
void MergeInsertSorter<Container, PairContainer>::showBefore() const {
    std::cout << COLOR_BEFORE << "Before:" << COLOR_RESET << " ";
    for (int val : inputValues) std::cout << val << " ";
    std::cout << std::endl;
}

template <typename Container, typename PairContainer>
void MergeInsertSorter<Container, PairContainer>::showAfter() const {
    std::cout << COLOR_AFTER << "After:" << COLOR_RESET << " ";
    for (int val : sortedResult) std::cout << val << " ";
    std::cout << std::endl;
}

template <typename Container, typename PairContainer>
void MergeInsertSorter<Container, PairContainer>::showDuration(
    const std::string& containerName) const {
    std::cout << "Time to process a range of " << inputValues.size()
              << " elements with " << containerName << " : " << duration
              << " us" << std::endl;
}
