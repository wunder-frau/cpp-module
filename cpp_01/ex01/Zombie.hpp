#pragma once
#include <iostream>
#include <string>

class Zombie {
private:
    std::string name;  // The name of the zombie

public:
    Zombie(std::string zombieName = "");  // Constructor
    ~Zombie();                            // Destructor

    void announce() const;  // Print the zombie's announcement
};
