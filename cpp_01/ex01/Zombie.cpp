#include "Zombie.hpp"

Zombie::Zombie() : name_("DefaultZombie") {}

Zombie::Zombie(const std::string& zombieName) : name_(zombieName) {}

Zombie::~Zombie() {
    std::cout << "Zombie " << name_ << " has been destroyed!" << std::endl;
}

void Zombie::announce() const {
    std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
