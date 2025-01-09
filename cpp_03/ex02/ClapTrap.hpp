#pragma once
#include <string>

class ClapTrap {
protected:
    using uint_t = unsigned int;

    struct Points {
        uint_t hit, energy, damage;
    };

public:
    //: Con- and destructors, assignements {{{
    explicit ClapTrap();

    explicit ClapTrap(const std::string&);

    ClapTrap(const ClapTrap&);

    ~ClapTrap();

    ClapTrap& operator=(const ClapTrap&);
    //: }}}

    //: Members {{{
    //: Element access
    inline const std::string& getName() const { return name_; }

    //: Modifiers
    void attack(const std::string&);

    void takeDamage(uint_t);

    void beRepaired(uint_t);
    //: }}}

protected:
    //: Con- and destructors, assignements {{{
    explicit ClapTrap(const std::string&, const Points&, const std::string&);
    //: }}}

    //: Members {{{
    inline const std::string& getSecret() const { return secret_; }
    //: }}}

private:
    std::string name_ = {};
    Points points_ = {10, 10, 0};
    std::string secret_ = "ClapTrap";

    //: Members {{{
    //: Element access
    bool isDead() const;
    //: }}}
};
