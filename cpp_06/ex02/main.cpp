#include <cstdlib>
#include <ctime>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate() {
    std::srand(std::time(nullptr));
    int value = std::rand() % 3;
    switch (value) {
        case 0:
            return new A;
        case 1:
            return new B;
        case 2:
            return new C;
        default:
            return nullptr;
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A\n";
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B\n";
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C\n";
    } else {
        std::cout << "Unknown type\n";
    }
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A\n";
    } catch (std::bad_cast&) {
    }
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B\n";
    } catch (std::bad_cast&) {
    }
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C\n";
    } catch (std::bad_cast&) {
    }
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
