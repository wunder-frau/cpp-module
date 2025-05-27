// PmergeMe.hpp
#pragma once

#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <deque>
#include <exception>
#include <iostream>
#include <set>
#include <string>
#include <vector>

class InputError : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Invalid input detected.";
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

public:
    MergeInsertSorter() = default;
    virtual ~MergeInsertSorter() = default;

    void loadInput(int argc, char** argv);
    void sort();
    void showBefore() const;
    void showAfter() const;
    void showDuration(const std::string& containerName) const;

protected:
    void makePairs();
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
};

extern template class MergeInsertSorter<std::vector<int>,
                                        std::vector<std::pair<int, int>>>;
extern template class MergeInsertSorter<std::deque<int>,
                                        std::deque<std::pair<int, int>>>;

// Implementation below

#include <iomanip>  // For debug output formatting

template <typename Container, typename PairContainer>
void MergeInsertSorter<Container, PairContainer>::loadInput(int argc,
                                                            char** argv) {
    if (argc < 2)
        throw InputError();

    for (int i = 1; i < argc; ++i) {
        std::string s(argv[i]);
        for (char c : s)
            if (!std::isdigit(c))
                throw InputError();

        int val = std::atoi(argv[i]);
        if (val < 0)
            throw InputError();

        inputValues.push_back(val);
    }
}

template <typename Container, typename PairContainer>
void MergeInsertSorter<Container, PairContainer>::makePairs() {
    auto it = inputValues.begin();
    hasLeftover = false;
    pairs.clear();
    while (it != inputValues.end()) {
        int first = *it++;
        if (it == inputValues.end()) {
            leftoverElement = first;
            hasLeftover = true;
            std::cerr << "[DEBUG] Leftover element detected: "
                      << leftoverElement << std::endl;
            break;
        }
        int second = *it++;

        if (first < second)
            std::swap(first, second);

        std::cerr << "[DEBUG] Pair formed: (" << first << ", " << second << ")"
                  << std::endl;
        pairs.push_back(std::make_pair(first, second));
    }
}

template <typename Container, typename PairContainer>
void MergeInsertSorter<Container, PairContainer>::sortPrimaryKeys() {
    recursiveMergeSort(pairs.begin(), pairs.end());
    for (const auto& [first, second] : pairs) {
        sortedResult.push_back(first);
        pendingElements.push_back(second);
    }

    std::cerr << "[DEBUG] Sorted primary keys: ";
    for (auto val : sortedResult) std::cerr << val << " ";
    std::cerr << "\n[DEBUG] Pending elements: ";
    for (auto val : pendingElements) std::cerr << val << " ";
    std::cerr << std::endl;
}

template <typename Container, typename PairContainer>
void MergeInsertSorter<Container, PairContainer>::recursiveMergeSort(
    typename PairContainer::iterator begin,
    typename PairContainer::iterator end) {
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
    return std::lower_bound(sorted.begin(), sorted.end(), value);
}

template <typename Container, typename PairContainer>
Container
MergeInsertSorter<Container, PairContainer>::generateJacobsthalSequence(
    size_t count) {
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
    insertionOrder = generateJacobsthalSequence(pendingElements.size());
    std::set<size_t> inserted;

    for (size_t i : insertionOrder) {
        if (i >= pendingElements.size() || inserted.count(i))
            continue;
        inserted.insert(i);

        int val = pendingElements[i];
        sortedResult.insert(findInsertPosition(sortedResult, val), val);
        std::cerr << "[DEBUG] Inserted " << val << " into sorted sequence\n";
    }

    if (hasLeftover) {
        sortedResult.insert(findInsertPosition(sortedResult, leftoverElement),
                            leftoverElement);
        std::cerr << "[DEBUG] Inserted leftover element: " << leftoverElement
                  << std::endl;
    }
}

template <typename Container, typename PairContainer>
void MergeInsertSorter<Container, PairContainer>::sort() {
    auto start = std::chrono::high_resolution_clock::now();
    if (inputValues.empty())
        throw InputError();
    if (inputValues.size() == 1) {
        sortedResult.push_back(inputValues[0]);
    } else {
        makePairs();
        sortPrimaryKeys();
        insertSecondaryKeys();
    }
    auto end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration<double, std::micro>(end - start).count();
    std::cerr << "[DEBUG] Total sort time: " << duration << " us" << std::endl;
}

template <typename Container, typename PairContainer>
void MergeInsertSorter<Container, PairContainer>::showBefore() const {
    std::cout << "Before: ";
    for (int val : inputValues) std::cout << val << " ";
    std::cout << std::endl;
}

template <typename Container, typename PairContainer>
void MergeInsertSorter<Container, PairContainer>::showAfter() const {
    std::cout << "After: ";
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