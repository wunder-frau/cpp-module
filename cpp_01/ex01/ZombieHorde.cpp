#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    if (N <= 0) {
        return nullptr;  // Return nullptr if the number of zombies is invalid
    }

    // Allocate a block of memory for N Zombies
    Zombie* horde = new Zombie[N];

    // Initialize each Zombie in the horde
    for (int i = 0; i < N; ++i) {
        horde[i] = Zombie(name);  // Use constructor to set the name
    }

    return horde;  // Return the pointer to the first Zombie
}
