#include <iostream>

#include "ClapTrap.hpp"

int main(void) {
    ClapTrap vagina("vagina");
    ClapTrap cock("cock");

    vagina.attack("cock");
    vagina.takeDamage(2);
    vagina.beRepaired(5);

    return 0;
}