#pragma once

#include "ClapTrap.hpp"

class ScavTrap final : public ClapTrap {
public:
    // Con- and destructors, assignements
    explicit ScavTrap() = delete;

    explicit ScavTrap(const std::string&);

    ScavTrap(const ScavTrap&);

    ~ScavTrap();

    ScavTrap& operator=(const ScavTrap&);
    //

    // Static members
    void guardGate() const;
    //
};
