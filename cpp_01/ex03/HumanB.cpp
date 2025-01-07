#include "HumanB.hpp"

#include <iostream>

HumanB::HumanB(const std::string& name) : name_(name), weapon_(nullptr) {}

void HumanB::setWeapon(Weapon& weapon) { weapon_ = &weapon; }

void HumanB::attack() const {
    if (weapon) {
        std::cout << name_ << " attacks with their " << weapon_->getType()
                  << std::endl;
    } else {
        std::cout << name_ << " has no weapon!" << std::endl;
    }
}
