#include <iostream>

#include "Weapon.hpp"

int main() {
    Weapon club("crude spiked club");
    std::cout << "Weapon type: " << club.getType() << std::endl;
    club.setType("some other type of club");
    std::cout << "Weapon type after change: " << club.getType() << std::endl;

    return 0;
}
