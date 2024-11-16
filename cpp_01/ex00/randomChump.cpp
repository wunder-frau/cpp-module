#include "Zombie.hpp"

void randomChump(std::string name) {
    std::cout << "Entering randomChump..." << std::endl;
    Zombie tempZombie(name);
    tempZombie.announce();
    std::cout << "Exiting randomChump..." << std::endl;
}
