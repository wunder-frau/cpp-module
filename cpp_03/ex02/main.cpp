#include <iostream>

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
    // Test 1: Basic Functionality of FragTrap
    std::cout << "--- FragTrap Tests ---" << std::endl;
    FragTrap frag("Fraggy");

    frag.attack("Enemy1");
    frag.takeDamage(30);
    frag.beRepaired(20);
    frag.highFivesGuys();

    // Test 2: FragTrap Edge Cases
    frag.takeDamage(
        100);  // Excessive damage to ensure it handles death properly
    frag.attack("Enemy2");  // Should not attack as it is dead
    frag.beRepaired(50);    // Attempt to repair after death

    // Test 3: Basic Functionality of ScavTrap
    std::cout << "--- ScavTrap Tests ---" << std::endl;
    ScavTrap scav("Scavvy");

    scav.attack("Enemy3");
    scav.takeDamage(25);
    scav.beRepaired(15);
    scav.guardGate();

    // Test 4: ScavTrap Edge Cases
    scav.takeDamage(
        200);  // Excessive damage to ensure it handles death properly
    scav.attack("Enemy4");  // Should not attack as it is dead
    scav.beRepaired(50);    // Attempt to repair after death

    // Test 5: Copy and Assignment Operators
    std::cout << "--- Copy and Assignment Tests ---" << std::endl;
    FragTrap fragCopy = frag;  // Test copy constructor
    FragTrap fragAssigned("Temporary");
    fragAssigned = frag;  // Test assignment operator

    ScavTrap scavCopy = scav;  // Test copy constructor
    ScavTrap scavAssigned("Temporary");
    scavAssigned = scav;  // Test assignment operator

    // Test copy and assigned objects for functionality
    fragCopy.attack("Enemy5");
    scavAssigned.guardGate();

    std::cout << "--- End of Tests ---" << std::endl;

    return 0;
}
