#include <iostream>

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
    std::cout << "\n================= FragTrap Tests: Basic Functionality "
                 "=================\n";
    FragTrap frag("Fraggy");

    frag.attack("Enemy1");
    frag.takeDamage(30);
    frag.beRepaired(20);
    frag.highFivesGuys();

    std::cout << "\n================= FragTrap Tests: Edge Cases "
                 "==========================\n";
    frag.takeDamage(
        100);  // Excessive damage to ensure it handles death properly
    frag.attack("Enemy2");  // Should not attack as it is dead
    frag.beRepaired(50);    // Attempt to repair after death

    std::cout << "\n================= ScavTrap Tests: Basic Functionality "
                 "=================\n";
    ScavTrap scav("Scavvy");

    scav.attack("Enemy3");
    scav.takeDamage(25);
    scav.beRepaired(15);
    scav.guardGate();

    std::cout << "\n================= ScavTrap Tests: Edge Cases "
                 "==========================\n";
    scav.takeDamage(
        200);  // Excessive damage to ensure it handles death properly
    scav.attack("Enemy4");  // Should not attack as it is dead
    scav.beRepaired(50);    // Attempt to repair after death

    std::cout << "\n================= Copy and Assignment Tests "
                 "===========================\n";
    FragTrap fragCopy = frag;  // Test copy constructor
    FragTrap fragAssigned("Temporary");
    fragAssigned = frag;  // Test assignment operator

    ScavTrap scavCopy = scav;  // Test copy constructor
    ScavTrap scavAssigned("Temporary");
    scavAssigned = scav;  // Test assignment operator

    // Test copy and assigned objects for functionality
    std::cout
        << "\n--- Testing functionality of copied and assigned objects ---\n";
    fragCopy.attack("Enemy5");
    scavAssigned.guardGate();

    std::cout << "\n================= FragTrap Tests: Boundary Cases "
                 "===================\n";
    FragTrap boundaryFrag("BoundaryFrag");
    for (int i = 0; i < 99; ++i) {
        boundaryFrag.attack("Enemy");
    }
    boundaryFrag.attack("Last Enemy");    // Should work
    boundaryFrag.attack("Excess Enemy");  // Should fail (energy depleted)
    boundaryFrag.beRepaired(500);         // Test repair overflow

    std::cout << "\n================= Integration Tests "
                 "================================\n";
    FragTrap fraggy("Fraggy");
    ScavTrap scavvy("Scavvy");
    fraggy.attack("Scavvy");
    scavvy.guardGate();

    std::cout << "\n================= Destructor Behavior "
                 "==============================\n";
    {
        FragTrap tempFrag("TempFrag");
        tempFrag.attack("Enemy");
    }  // Destructor should be called here
    {
        ScavTrap tempScav("TempScav");
        tempScav.attack("Enemy");
    }  // Destructor should be called here

    std::cout << "\n================= End of Tests "
                 "=====================================\n";

    return 0;
}
