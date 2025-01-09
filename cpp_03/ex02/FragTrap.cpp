#include "FragTrap.hpp"

#include <iostream>

// Con- and destructors, assignements
FragTrap::FragTrap(const std::string& name)
    : ClapTrap::ClapTrap(name, {100, 100, 30}, "FragTrap") {
    std::cout << "FragTrap assignment constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap::ClapTrap(other) {
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    ClapTrap::operator=(other);
    return *this;
}
//

// Public members
void FragTrap::highFivesGuys() const {
    std::cout << ClapTrap::getSecret() << ' ' << ClapTrap::getName()
              << ": \"High five guys!\"" << std::endl;
}
//