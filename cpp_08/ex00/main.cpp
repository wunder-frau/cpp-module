#include <array>
#include <deque>
#include <forward_list>
#include <iostream>
#include <list>
#include <vector>

#include "easyfind.hpp"

void testVector() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::cout << "[vector] ";
    std::vector<int>::iterator it = easyfind(vec, 3);
    std::cout << "Found: " << *it << '\n';
}

void testList() {
    std::list<int> lst = {10, 20, 30, 40};
    std::cout << "[list] ";
    std::list<int>::iterator it = easyfind(lst, 20);
    std::cout << "Found: " << *it << '\n';
}

void testDeque() {
    std::deque<int> deq = {100, 200, 300};
    std::cout << "[deque] ";
    std::deque<int>::iterator it = easyfind(deq, 300);
    std::cout << "Found: " << *it << '\n';
}

void testArray() {
    std::array<int, 5> arr = {7, 8, 9, 10, 11};
    std::cout << "[array] ";
    std::array<int, 5>::iterator it = easyfind(arr, 10);
    std::cout << "Found: " << *it << '\n';
}

void testForwardList() {
    std::forward_list<int> flist = {42, 84, 126};
    std::cout << "[forward_list] ";
    std::forward_list<int>::iterator it = easyfind(flist, 84);
    std::cout << "Found: " << *it << '\n';
}

void testNotFound() {
    std::vector<int> vec = {1, 2, 3};
    std::cout << "[not found] ";
    try {
        easyfind(vec, 999);
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << '\n';
    }
}

int main() {
    std::cout << "🧪 Starting easyfind tests...\n";

    try {
        testVector();
        testList();
        testDeque();
        testArray();
        testForwardList();
        testNotFound();
    } catch (const std::exception& e) {
        std::cerr << "🚨 Unexpected error: " << e.what() << '\n';
    }

    std::cout << "✅ All tests complete.\n";
    return 0;
}
