#pragma once
#include <string>

#include "ClapTrap.hpp"

class FragTrap final : public ClapTrap {
public:
    // Con- and destructors, assignements
    explicit FragTrap() = delete;

    explicit FragTrap(const std::string&);

    FragTrap(const FragTrap&);

    ~FragTrap();

    FragTrap& operator=(const FragTrap&);
    //

    // Members
    void highFivesGuys() const;
    //
};
