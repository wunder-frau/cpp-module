#pragma once
#include <string>

#include "ClapTrap.hpp"

class ScavTrap final : public ClapTrap {
public:
    //: Con- and destructors, assignements {{{
    explicit ScavTrap() = delete;

    explicit ScavTrap(const std::string&);

    ScavTrap(const ScavTrap&);

    ~ScavTrap();

    ScavTrap& operator=(const ScavTrap&);
    //: }}}

    //: Members {{{
    void guardGate() const;
    //: }}}
};
