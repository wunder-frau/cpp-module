#include <iostream>

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
    FragTrap vagina("vagina");
    ScavTrap cock("cock");

    vagina.attack("cock");
    vagina.takeDamage(2);
    vagina.beRepaired(5);

    vagina.highFivesGuys();
    cock.guardGate();

    return 0;
}
