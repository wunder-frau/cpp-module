#pragma once
#include <iostream>
#include <string>

class Zombie {
public:
    Zombie();
    Zombie(const std::string& zombieName);
    ~Zombie();

    void announce() const;

private:
    std::string name_ = "";
};
