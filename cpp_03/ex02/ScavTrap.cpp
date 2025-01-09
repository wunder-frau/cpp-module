#include "ScavTrap.hpp"

#include <iostream>

// Con- and destructors, assignements
ScavTrap::ScavTrap(const std::string& name)
    : ClapTrap::ClapTrap(name, {100, 50, 20}, "ScavTrap") {
    std::cout << "ScavTrap assignment constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap::ClapTrap(other) {
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    ClapTrap::operator=(other);
    return *this;
}
//

// Public members
void ScavTrap::guardGate() const {
    std::cout << ClapTrap::getSecret() << ' ' << ClapTrap::getName()
              << " is now in Gate keeper mode." << std::endl;
}
//
