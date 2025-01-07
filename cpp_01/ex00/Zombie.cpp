#include "Zombie.hpp"

/* constructor uses a member initialization list to directly initialize the name
 * member variable with the value of zombieName. */
Zombie::Zombie(const std::string& zombieName) : name_(zombieName) {}

Zombie::~Zombie() {
    std::cout << "Zombie " << name_ << " has been destroyed!" << std::endl;
}

void Zombie::announce() const {
    std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
