#include <iostream>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void testClapTrap() {
    std::cout << "\n--- Testing ClapTrap ---\n\n";

    std::cout << "\n--- Default ClapTrap Test ---\n";
    ClapTrap defaultTrap("DefaultTrap");
    defaultTrap.attack("Enemy");
    defaultTrap.takeDamage(5);
    defaultTrap.beRepaired(3);
    defaultTrap.takeDamage(20);  // To check death handling

    std::cout << "\n--- Testing Copy Constructor for ClapTrap ---\n";
    ClapTrap copyTrap(defaultTrap);
    copyTrap.attack("AnotherEnemy");

    std::cout << "\n--- Testing Assignment Operator for ClapTrap ---\n";
    ClapTrap assignedTrap("AssignedTrap");
    assignedTrap = defaultTrap;
    assignedTrap.beRepaired(5);

    std::cout << "\n--- End of ClapTrap Tests ---\n";
}

void testScavTrap() {
    std::cout << "\n--- Testing ScavTrap ---\n\n";

    std::cout << "\n--- Default ScavTrap Test ---\n";
    ScavTrap scav("Scavenger");
    scav.attack("Bandit");
    scav.takeDamage(10);
    scav.beRepaired(8);
    scav.guardGate();

    std::cout << "\n--- Testing ScavTrap Taking Fatal Damage ---\n";
    scav.takeDamage(150);
    scav.beRepaired(10);  // Verify that dead ScavTrap cannot be repaired

    std::cout << "\n--- Testing Copy Constructor for ScavTrap ---\n";
    ScavTrap scavCopy(scav);
    scavCopy.guardGate();

    std::cout << "\n--- Testing Assignment Operator for ScavTrap ---\n";
    ScavTrap scavAssigned("AnotherScav");
    scavAssigned = scav;
    scavAssigned.attack("EnemyBase");

    std::cout << "\n--- End of ScavTrap Tests ---\n";
}

int main() {
    testClapTrap();
    std::cout << "\n=============================================\n";
    testScavTrap();

    return 0;
}