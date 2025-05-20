#include <cstdlib>
#include <ctime>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate() {
    static bool seeded = false;
    if (!seeded) {
        std::srand(static_cast<unsigned>(std::time(nullptr)));
        seeded = true;
    }

    int value = std::rand() % 3;
    switch (value) {
        case 0:
            return new A;
        case 1:
            return new B;
        case 2:
            return new C;
        default:
            return nullptr;  // Should not happen
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A\n";
        return;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B\n";
        return;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C\n";
        return;
    } else {
        std::cout << "Unknown type\n";
    }
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A\n";
        return;
    } catch (std::bad_cast&) {
    }

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B\n";
        return;
    } catch (std::bad_cast&) {
    }

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C\n";
        return;
    } catch (std::bad_cast&) {
    }

    std::cout << "Unknown type\n";
}

int main() {
    Base* base_ptr;
    try {
        base_ptr = generate();
    } catch (std::bad_alloc& e) {
        std::cerr << "Allocation error: " << e.what() << '\n';
        return 1;
    }
    identify(base_ptr);
    identify(*base_ptr);
    delete base_ptr;
    return 0;
}
