#pragma once

#include <iostream>
#include <string>

class Zombie {
public:
    Zombie(const std::string& zombieName);

    ~Zombie();

    void announce() const;

private:
    std::string name_;
};