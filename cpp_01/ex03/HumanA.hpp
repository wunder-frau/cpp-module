#pragma once
#include <string>

#include "Weapon.hpp"

class HumanA {
public:
    HumanA(const std::string &name,
           Weapon &weapon);  // Constructor that requires a weapon
    void attack() const;

private:
    std::string name_;
    Weapon &weapon_;  // Weapon must always be passed in
};