#pragma once
#include <string>

#include "Weapon.hpp"

class HumanA {
private:
    std::string name;
    Weapon &weapon;  // Weapon must always be passed in

public:
    HumanA(const std::string &name,
           Weapon &weapon);  // Constructor that requires a weapon
    void attack() const;
};