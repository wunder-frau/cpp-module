#include "Weapon.hpp"

Weapon::Weapon(const std::string& type) : type_(type) {}

const std::string& Weapon::getType() const { return type_; }

void Weapon::setType(const std::string& newType) { type_ = newType; }
