#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

#include "Array.hpp"

#define MAX_VAL 750

class Point {
public:
    int x, y;
    Point(int a = 0, int b = 0) : x(a), y(b) {}
    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        return os << "(" << p.x << "," << p.y << ")";
    }
};

int main() {
    std::cout << "===== Subject Test =====" << std::endl;
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(static_cast<unsigned>(time(NULL)));

    for (int i = 0; i < MAX_VAL; i++) {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++) {
        if (mirror[i] != numbers[i]) {
            std::cerr << "❌ Didn't save the same value!" << std::endl;
            delete[] mirror;
            return 1;
        }
    }

    try {
        numbers[-2] = 0;
    } catch (const std::exception& e) {
        std::cerr << "Expected exception: " << e.what() << std::endl;
    }

    try {
        numbers[MAX_VAL] = 0;
    } catch (const std::exception& e) {
        std::cerr << "Expected exception: " << e.what() << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++) {
        numbers[i] = rand();
    }
    delete[] mirror;

    std::cout << "\n===== Complex Type: Point =====" << std::endl;
    Array<Point> points(3);
    points[0] = Point(1, 2);
    points[1] = Point(3, 4);
    points[2] = Point(5, 6);

    for (size_t i = 0; i < points.size(); ++i)
        std::cout << "points[" << i << "] = " << points[i] << std::endl;

    std::cout << "\n===== Nested Array: Array<Array<int>> =====" << std::endl;
    Array<Array<int>> nested(2);
    for (size_t i = 0; i < nested.size(); ++i) nested[i] = Array<int>(3);

    nested[0][0] = 10;
    nested[1][2] = 42;

    for (size_t i = 0; i < nested.size(); ++i) {
        for (size_t j = 0; j < nested[i].size(); ++j)
            std::cout << nested[i][j] << " ";
        std::cout << std::endl;
    }

    std::cout << "\n===== Const-Correctness =====" << std::endl;
    const Array<std::string> words(2);
    try {
        std::cout << "words.size() = " << words.size() << std::endl;
        std::cout << "words[0] = " << words[0] << std::endl;
        // words[0] = "change"; // ❌ Uncomment to verify compiler blocks
        // mutation
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n===== Iterator Support =====" << std::endl;
    Array<int> iterNumbers(4);
    for (size_t i = 0; i < iterNumbers.size(); ++i)
        iterNumbers[i] = (i + 1) * 10;

    std::cout << "Via iterators: ";
    for (auto it = iterNumbers.begin(); it != iterNumbers.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    return 0;
}
