#include <iostream>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void testClapTrap() {
    std::cout << "\n--- Testing ClapTrap ---\n";

    // Default test
    ClapTrap defaultTrap("DefaultTrap");
    defaultTrap.attack("Enemy");
    defaultTrap.takeDamage(5);
    defaultTrap.beRepaired(3);
    defaultTrap.takeDamage(20);  // To check death handling

    // Test copy constructor
    ClapTrap copyTrap = defaultTrap;
    copyTrap.attack("AnotherEnemy");

    // Test assignment operator
    ClapTrap assignedTrap("AssignedTrap");
    assignedTrap = defaultTrap;
    assignedTrap.beRepaired(5);
}

void testScavTrap() {
    std::cout << "\n--- Testing ScavTrap ---\n";

    // ScavTrap behavior
    ScavTrap scav("Scavenger");
    scav.attack("Bandit");
    scav.takeDamage(10);
    scav.beRepaired(8);
    scav.guardGate();

    // Test ScavTrap taking fatal damage
    scav.takeDamage(150);
    scav.beRepaired(10);  // Verify that dead ScavTrap cannot be repaired

    // Test copy constructor
    ScavTrap scavCopy(scav);
    scavCopy.guardGate();

    // Test assignment operator
    ScavTrap scavAssigned("AnotherScav");
    scavAssigned = scav;
    scavAssigned.attack("EnemyBase");
}

int main() {
    testClapTrap();
    testScavTrap();

    return 0;
}