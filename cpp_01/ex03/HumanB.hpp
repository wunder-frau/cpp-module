#pragma once
#include <string>

#include "Weapon.hpp"

class HumanB {
private:
    std::string name;
    Weapon *weapon;  // Weapon is optional (could be nullptr)

public:
    HumanB(const std::string &name);
    void setWeapon(Weapon &weapon);  // Set weapon later
    void attack() const;
};