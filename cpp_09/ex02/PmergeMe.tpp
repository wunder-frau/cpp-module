#pragma once

#include <iomanip>

// Constructor

template <typename C, typename P>
MergeInsertSorter<C, P>::MergeInsertSorter()
    : duration(0), hasLeftover(false), leftoverElement(0) {
    if (DEBUG_MODE) {
        debugFile.open("debug.log");
        if (!debugFile.is_open()) {
            std::cerr << "[ERROR] Could not open debug.log" << std::endl;
        }
    }
}

// Copy constructor
template <typename C, typename P>
MergeInsertSorter<C, P>::MergeInsertSorter(const MergeInsertSorter& other)
    : inputValues(other.inputValues),
      sortedResult(other.sortedResult),
      pendingElements(other.pendingElements),
      insertionOrder(other.insertionOrder),
      pairs(other.pairs),
      duration(other.duration),
      hasLeftover(other.hasLeftover),
      leftoverElement(other.leftoverElement) {
    if (DEBUG_MODE) {
        debugFile.open("debug.log");
    }
}

// Assignment operator
template <typename C, typename P>
MergeInsertSorter<C, P>& MergeInsertSorter<C, P>::operator=(const MergeInsertSorter& other) {
    if (this != &other) {
        inputValues = other.inputValues;
        sortedResult = other.sortedResult;
        pendingElements = other.pendingElements;
        insertionOrder = other.insertionOrder;
        pairs = other.pairs;
        duration = other.duration;
        hasLeftover = other.hasLeftover;
        leftoverElement = other.leftoverElement;

        if (debugFile.is_open()) debugFile.close();
        if (DEBUG_MODE) debugFile.open("debug.log");
    }
    return *this;
}

// Destructor
template <typename C, typename P>
MergeInsertSorter<C, P>::~MergeInsertSorter() {
    if (debugFile.is_open()) debugFile.close();
}

template <typename C, typename P>
void MergeInsertSorter<C, P>::logStep(const std::string& msg, const std::string& tag) const {
    if (!DEBUG_MODE) return;

    std::string color = COLOR_INFO;
    if (tag == "[DEBUG]") color = "\033[1;36m";
    else if (tag == "[STEP]") color = "\033[1;33m";
    else if (tag == "[ERROR]") color = COLOR_ERROR;

    std::cout << color << tag << COLOR_RESET << " " << msg << std::endl;
    if (debugFile.is_open()) debugFile << tag << " " << msg << std::endl;
}

template <typename C, typename P>
void MergeInsertSorter<C, P>::loadInput(int argc, char** argv) {
    logStep("loadInput(argc = " + std::to_string(argc) + ")", "[DEBUG]");
    if (argc < 2) throw InputError();

    for (int i = 1; i < argc; ++i) {
        std::string arg(argv[i]);
        std::replace(arg.begin(), arg.end(), ',', ' ');
        std::stringstream ss(arg);
        std::string token;

        while (ss >> token) {
            for (char c : token)
                if (!std::isdigit(c)) throw InputError();
            int val = std::atoi(token.c_str());
            if (val < 0) throw InputError();
            inputValues.push_back(val);
        }
    }

    logStep("Input loaded: " + std::to_string(inputValues.size()) + " elements", "[STEP]");
}

template <typename C, typename P>
void MergeInsertSorter<C, P>::handleLeftover(int value) {
    leftoverElement = value;
    hasLeftover = true;
    logStep("Leftover element detected: " + std::to_string(leftoverElement));
}

template <typename C, typename P>
void MergeInsertSorter<C, P>::addPair(int a, int b) {
    if (a < b) std::swap(a, b);
    pairs.push_back(std::make_pair(a, b));
    logStep("Pair formed: (" + std::to_string(a) + ", " + std::to_string(b) + ")");
}

template <typename C, typename P>
void MergeInsertSorter<C, P>::makePairs() {
    logStep("makePairs() called", "[DEBUG]");
    auto it = inputValues.begin();
    pairs.clear();
    while (it != inputValues.end()) {
        int a = *it++;
        if (it == inputValues.end()) {
            handleLeftover(a);
            break;
        }
        int b = *it++;
        addPair(a, b);
    }
}

template <typename C, typename P>
void MergeInsertSorter<C, P>::sortPrimaryKeys() {
    logStep("sortPrimaryKeys() called", "[DEBUG]");
    recursiveMergeSort(pairs.begin(), pairs.end());
    for (const auto& [a, b] : pairs) {
        sortedResult.push_back(a);
        pendingElements.push_back(b);
    }

    std::string sorted, pending;
    for (auto v : sortedResult) sorted += std::to_string(v) + " ";
    for (auto v : pendingElements) pending += std::to_string(v) + " ";
    logStep("Sorted primary keys: " + sorted);
    logStep("Pending elements: " + pending);
}

template <typename C, typename P>
void MergeInsertSorter<C, P>::recursiveMergeSort(typename P::iterator b, typename P::iterator e) {
    if (std::distance(b, e) <= 1) return;
    auto m = b + (e - b) / 2;
    recursiveMergeSort(b, m);
    recursiveMergeSort(m, e);
    mergePairs(b, m, e);
}

template <typename C, typename P>
void MergeInsertSorter<C, P>::mergePairs(typename P::iterator b, typename P::iterator m, typename P::iterator e) {
    P tmp;
    auto l = b, r = m;
    while (l != m && r != e) {
        if (l->first <= r->first) tmp.push_back(*l++);
        else tmp.push_back(*r++);
    }
    tmp.insert(tmp.end(), l, m);
    tmp.insert(tmp.end(), r, e);
    std::copy(tmp.begin(), tmp.end(), b);
}

template <typename C, typename P>
typename C::iterator MergeInsertSorter<C, P>::findInsertPosition(C& sorted, int val) {
    return std::lower_bound(sorted.begin(), sorted.end(), val);
}

template <typename C, typename P>
C MergeInsertSorter<C, P>::generateJacobsthalSequence(size_t count) {
    logStep("generateJacobsthalSequence(count = " + std::to_string(count) + ")", "[DEBUG]");
    C seq;
    if (count == 0) return seq;
    seq.push_back(1);
    for (size_t i = 2;; ++i) {
        size_t j = (1 << i) - ((i % 2 == 0) ? 1 : -1);
        j /= 3;
        if (j >= count) break;
        seq.push_back(j);
    }
    C full;
    for (auto v : seq) full.push_back(v - 1);
    for (size_t i = 0; i < count; ++i)
        if (std::find(full.begin(), full.end(), i) == full.end())
            full.push_back(i);
    return full;
}

template <typename C, typename P>
void MergeInsertSorter<C, P>::insertSecondaryKeys() {
    logStep("insertSecondaryKeys() called", "[DEBUG]");
    insertionOrder = generateJacobsthalSequence(pendingElements.size());
    std::set<size_t> inserted;
    for (size_t i : insertionOrder) {
        if (i >= pendingElements.size() || inserted.count(i)) continue;
        inserted.insert(i);
        int val = pendingElements[i];
        sortedResult.insert(findInsertPosition(sortedResult, val), val);
        logStep("Inserted " + std::to_string(val) + " into sorted sequence");
    }
    if (hasLeftover) {
        sortedResult.insert(findInsertPosition(sortedResult, leftoverElement), leftoverElement);
        logStep("Inserted leftover element: " + std::to_string(leftoverElement));
    }
}

template <typename C, typename P>
void MergeInsertSorter<C, P>::sort() {
    logStep("sort() called", "[DEBUG]");
    if (inputValues.empty()) throw InputError();
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

template <typename C, typename P>
void MergeInsertSorter<C, P>::runCoreSorting() {
    makePairs();
    sortPrimaryKeys();
    insertSecondaryKeys();
}

template <typename C, typename P>
void MergeInsertSorter<C, P>::showBefore() const {
    std::cout << COLOR_BEFORE << "Before:" << COLOR_RESET << " ";
    for (int v : inputValues) std::cout << v << " ";
    std::cout << std::endl;
}

template <typename C, typename P>
void MergeInsertSorter<C, P>::showAfter() const {
    std::cout << COLOR_AFTER << "After:" << COLOR_RESET << " ";
    for (int v : sortedResult) std::cout << v << " ";
    std::cout << std::endl;
}

template <typename C, typename P>
void MergeInsertSorter<C, P>::showDuration(const std::string& name) const {
    std::cout << "Time to process " << inputValues.size()
              << " elements with " << name << " : " << duration << " us" << std::endl;
}