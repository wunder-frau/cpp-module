#pragma once

#include <iostream>
#include <string>

class Harl {
public:
    Harl();
    ~Harl();

    void complain(const std::string& level);

private:
    void (Harl::*complaints_[4])();  // array of member function pointers

    void debug();
    void info();
    void warning();
    void error();
};