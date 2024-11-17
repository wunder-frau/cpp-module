#include "Zombie.hpp"

// Declare the zombieHorde function here
Zombie* zombieHorde(int N, std::string name);

int main() {
    int N = 5;  // Number of zombies
    std::string name = "HordeZombie";

    // Create the zombie horde
    Zombie* horde = zombieHorde(N, name);

    if (!horde) {
        std::cerr << "Failed to create zombie horde!" << std::endl;
        return 1;
    }

    // Make each zombie announce itself
    for (int i = 0; i < N; ++i) {
        horde[i].announce();
    }

    // Destroy the zombie horde
    delete[] horde;

    return 0;
}
