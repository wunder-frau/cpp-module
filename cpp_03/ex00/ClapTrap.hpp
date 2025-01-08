#pragma once

#include <string>

class ClapTrap {
    using uint_t = unsigned int;

    struct Points {
        uint_t hit, energy, damage;
    };

public:
    // Con- and destructors, assignements
    explicit ClapTrap();

    explicit ClapTrap(const std::string&);

    ClapTrap(const ClapTrap&);

    ~ClapTrap();

    ClapTrap& operator=(const ClapTrap&);
    //

    // Members
    // Modifiers
    void attack(const std::string&);

    void takeDamage(uint_t);

    void beRepaired(uint_t);
    //

private:
    std::string name_ = {};
    Points points_ = {10, 10, 0};

    // Members
    // Element access
    bool isDead() const;
    //
};
