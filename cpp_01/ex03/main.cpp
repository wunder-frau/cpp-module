#include <iostream>

#include "HumanA.hpp"
#include "Weapon.hpp"

int main() {
    Weapon club("crude spiked club");
    std::cout << "Weapon type: " << club.getType() << std::endl;
    club.setType("some other type of club");
    std::cout << "Weapon type after change: " << club.getType() << std::endl;

    // Testing HumanA
    HumanA bob("Bob", club);
    std::cout << "Testing HumanA with initial weapon type:" << std::endl;
    bob.attack();
    club.setType("some other type of club");
    std::cout << "Testing HumanA after changing weapon type:" << std::endl;
    bob.attack();
    return 0;
}
