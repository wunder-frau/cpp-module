#include <iostream>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
    ScavTrap vagina("vagina");
    ClapTrap cock("cock");

    vagina.attack("cock");
    vagina.takeDamage(2);
    vagina.beRepaired(5);

    vagina.guardGate();

    return 0;
}
