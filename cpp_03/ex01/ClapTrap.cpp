#include "ClapTrap.hpp"

#include <iostream>

// Con- and destructors, assignements
ClapTrap::ClapTrap() {
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : name_(name) {
    std::cout << "ClapTrap assignment constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name, const Points& points,
                   const std::string& secret)
    : name_(name), points_(points), secret_(secret) {
    std::cout << "ClapTrap assignment constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : name_(other.name_), points_(other.points_), secret_(other.secret_) {
    std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "ClapTrap copy assignment operator called" << std::endl;
    name_ = other.name_;
    points_ = other.points_;
    secret_ = other.secret_;
    return *this;
}

// Members
// Element access
const std::string& ClapTrap::getName() const { return name_; }

// Public members
// Modifiers
void ClapTrap::attack(const std::string& target) {
    if (isDead())
        return;

    std::cout << secret_ << ' ' << name_ << " attacks " << target
              << ", causing " << points_.damage << " points of damage!"
              << std::endl;
    --points_.hit;
}

void ClapTrap::takeDamage(ClapTrap::uint_t amount) {
    if (isDead())
        return;

    amount = points_.hit > amount ? amount : points_.hit;
    std::cout << secret_ << ' ' << name_ << " takes " << amount
              << " points of damage!\n";
    points_.hit -= amount;
}

void ClapTrap::beRepaired(const ClapTrap::uint_t amount) {
    if (isDead())
        return;

    std::cout << secret_ << ' ' << name_ << " is being repaired for " << amount
              << " points of damage!\n";
    --points_.energy;
    points_.hit += amount;
}

// Members
const std::string& ClapTrap::getSecret() const { return secret_; }
//
// Private members
// Element access
bool ClapTrap::isDead() const {
    const bool is_dead = points_.hit == 0 || points_.energy == 0;
    if (is_dead)
        std::cout << secret_ << ' ' << name_ << " is dead!" << std::endl;
    return is_dead;
}
//
