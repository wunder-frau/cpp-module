#include <compare>  // Required for the spaceship operator <=>
#include <iostream>
#include <string>

#include "whatever.hpp"

// ✅ This class is totally ordered using the spaceship operator
class Point {
public:
    int x;
    Point(int val = 0) : x(val) {}

    // Provides all comparison operators automatically
    auto operator<=>(const Point&) const = default;
    bool operator==(const Point&) const = default;
};

// ❌ This class is *not* totally ordered: missing <=, >=
class Incomplete {
public:
    int x;
    Incomplete(int val) : x(val) {}

    // Only provides < and ==, which is not enough
    bool operator<(const Incomplete& other) const { return x < other.x; }
    bool operator==(const Incomplete& other) const { return x == other.x; }
};

// Helper for printing Point
std::ostream& operator<<(std::ostream& os, const Point& p) { return os << p.x; }

int main(void) {
    std::cout << "===== Basic int and string tests =====" << std::endl;

    int a = 2;
    int b = 3;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

    std::cout << "\n===== Edge cases =====" << std::endl;

    // ✅ Equal values - verify that min() and max() return the second argument
    int e = 42;
    int f = 42;
    const int& minRef = ::min(e, f);
    const int& maxRef = ::max(e, f);
    std::cout << "min( e, f ) = " << minRef << " (returned ";
    std::cout << ((&minRef == &f) ? "f ✔️" : "e ❌") << ")" << std::endl;
    std::cout << "max( e, f ) = " << maxRef << " (returned ";
    std::cout << ((&maxRef == &f) ? "f ✔️" : "e ❌") << ")" << std::endl;

    // ✅ Swapping same variable - verify it stays unchanged
    int x = 99;
    int before = x;
    ::swap(x, x);
    std::cout << "swap(x, x): x = " << x << " ("
              << ((x == before) ? "unchanged ✔️" : "changed ❌") << ")"
              << std::endl;

    // ✅ Const values - should work without modification
    const int g = 7;
    const int h = 13;
    std::cout << "min( g, h ) = " << ::min(g, h) << std::endl;
    std::cout << "max( g, h ) = " << ::max(g, h) << std::endl;

    // ✅ Custom totally ordered type (Point)
    Point p1(5);
    Point p2(10);
    ::swap(p1, p2);
    std::cout << "p1 = " << p1 << ", p2 = " << p2 << std::endl;
    std::cout << "min( p1, p2 ) = " << ::min(p1, p2) << std::endl;
    std::cout << "max( p1, p2 ) = " << ::max(p1, p2) << std::endl;

    // ❌ Failing case: Incomplete is *not* totally ordered
    //
    // ➤ If 'min' is defined with `std::totally_ordered<T>`:
    //     ✅ Compiler error: "'Incomplete' does not satisfy
    //     'std::totally_ordered'"
    //
    // ➤ If 'min' is unconstrained:
    //     ❌ Compiler error inside the function body (harder to debug)
    //
    // 💡 Recommendation: Use concepts for safer, clearer templates.

    // Incomplete i1(1);
    // Incomplete i2(2);
    // std::cout << "min( i1, i2 ) = " << ::min(i1, i2) << std::endl;

    return 0;
}
