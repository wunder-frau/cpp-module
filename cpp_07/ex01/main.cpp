#include <iostream>
#include <string>

#include "iter.hpp"

// Custom class for testing
class Awesome {
public:
    Awesome(int n) : _n(n) {}
    int get() const { return _n; }

private:
    int _n;
};

std::ostream& operator<<(std::ostream& os, const Awesome& a) {
    os << a.get();
    return os;
}

int main() {
    std::cout << "===== Iter Template Tests =====\n" << std::endl;

    // Test 1: Integer array
    int intArray[] = {1, 2, 3, 4};
    std::cout << "Int array: ";
    ::iter(intArray, 4, print<int>);
    std::cout << "\n" << std::endl;

    // Test 2: String array
    std::string strArray[] = {"apple", "banana", "cherry"};
    std::cout << "String array: ";
    ::iter(strArray, 3, print<std::string>);
    std::cout << "\n" << std::endl;

    // Test 3: Float array
    float floatArray[] = {1.1f, 2.2f, 3.3f};
    std::cout << "Float array: ";
    ::iter(floatArray, 3, print<float>);
    std::cout << "\n" << std::endl;

    // Test 4: Double array
    double doubleArray[] = {0.123, 0.456, 0.789};
    std::cout << "Double array: ";
    ::iter(doubleArray, 3, print<double>);
    std::cout << "\n" << std::endl;

    // Test 5: Const array
    const char* constArray[] = {"const1", "const2"};
    std::cout << "Const char* array: ";
    ::iter(constArray, 2, print<const char*>);
    std::cout << "\n" << std::endl;

    // Test 6: Empty array
    int emptyArray[] = {};
    std::cout << "Empty array (should show nothing): ";
    ::iter(emptyArray, 0, print<int>);
    std::cout << "\n" << std::endl;

    // Test 7: Custom class array
    Awesome awesomeArray[] = {Awesome(10), Awesome(20), Awesome(30)};
    std::cout << "Custom class array: ";
    ::iter(awesomeArray, 3, print<Awesome>);
    std::cout << "\n" << std::endl;

    // Test 8: Mutate test (double the values)
    int numbers[] = {1, 2, 3};
    std::cout << "Before mutation (int): ";
    ::iter(numbers, 3, print<int>);
    std::cout << "\n";

    ::iter(numbers, 3, mutate<int>);  // mutate in-place

    std::cout << "After mutation (int): ";
    ::iter(numbers, 3, print<int>);
    std::cout << "\n" << std::endl;

    // Test 9: Mutate strings
    std::string texts[] = {"a", "b", "c"};
    std::cout << "Before mutation (string): ";
    ::iter(texts, 3, print<std::string>);
    std::cout << "\n";

    ::iter(texts, 3, mutate<std::string>);  // concatenate strings

    std::cout << "After mutation (string): ";
    ::iter(texts, 3, print<std::string>);
    std::cout << "\n" << std::endl;

    return 0;
}
