#pragma once
#include <string>

#include "Weapon.hpp"

class HumanB {
public:
    HumanB(const std::string &name);
    void setWeapon(Weapon &weapon);  // Set weapon later
    void attack() const;

private:
    std::string name_;
    Weapon *weapon_;  // Weapon is optional (could be nullptr)
};