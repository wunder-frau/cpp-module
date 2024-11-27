#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl {
public:
    Harl();
    ~Harl();

    void complain(const std::string &level);

private:
    void debug();
    void info();
    void warning();
    void error();

    void (Harl::*complaints[4])();
};

#endif