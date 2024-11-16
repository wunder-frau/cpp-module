#include "Zombie.hpp"

void randomChump(std::string name) {
    Zombie tempZombie = Zombie(name);
    tempZombie.announce();
}
