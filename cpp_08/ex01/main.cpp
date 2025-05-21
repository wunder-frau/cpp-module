#include <climits>
#include <cstdlib>
#include <iostream>
#include <vector>

#include "Span.hpp"

int main() {
    {
        std::cout << "🔹 Basic Test:\n";
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest: " << sp.shortestSpan() << '\n';
        std::cout << "Longest: " << sp.longestSpan() << '\n';
    }

    {
        std::cout << "\n🔹 Range Add Test with 10,000 values:\n";
        Span sp(10000);
        std::vector<int> nums(10000);
        for (int i = 0; i < 10000; ++i) nums[i] = rand();

        sp.addNumber(nums.begin(), nums.end());
        std::cout << "Shortest: " << sp.shortestSpan() << '\n';
        std::cout << "Longest: " << sp.longestSpan() << '\n';
    }

    {
        std::cout << "\n🔹 Negative Numbers and Duplicates:\n";
        Span sp(6);
        sp.addNumber(-10);
        sp.addNumber(-20);
        sp.addNumber(-10);
        sp.addNumber(0);
        sp.addNumber(20);
        sp.addNumber(10);

        std::cout << "Shortest: " << sp.shortestSpan() << '\n';
        std::cout << "Longest: " << sp.longestSpan() << '\n';
    }

    {
        std::cout << "\n🔹 Few Elements (Should Throw):\n";
        try {
            Span sp(1);
            sp.addNumber(42);
            std::cout << "Shortest: " << sp.shortestSpan() << '\n';
        } catch (const std::exception& e) {
            std::cout << "Exception: " << e.what() << '\n';
        }
    }

    {
        std::cout << "\n🔹 Overflow Range Insert:\n";
        try {
            Span sp(5);
            std::vector<int> tooMany = {1, 2, 3, 4, 5, 6};
            sp.addNumber(tooMany.begin(), tooMany.end());
        } catch (const std::exception& e) {
            std::cout << "Exception: " << e.what() << '\n';
        }
    }

    {
        std::cout << "\n🔹 Min/Max Int Edge Case:\n";
        Span sp(3);
        sp.addNumber(INT_MIN);
        sp.addNumber(0);
        sp.addNumber(INT_MAX);
        std::cout << "Shortest: " << sp.shortestSpan() << '\n';
        std::cout << "Longest: " << sp.longestSpan() << '\n';
    }

    {
        std::cout << "\n🔹 Performance Test: 100,000 elements\n";
        Span sp(100000);
        std::vector<int> bigData;
        bigData.reserve(100000);
        for (int i = 0; i < 100000; ++i) bigData.push_back(rand());

        sp.addNumber(bigData.begin(), bigData.end());
        std::cout << "Shortest: " << sp.shortestSpan() << '\n';
        std::cout << "Longest: " << sp.longestSpan() << '\n';
    }

    return 0;
}
