#include <iostream>

#include "ClapTrap.hpp"

int main(void) {
    {
        ClapTrap flu("Flu");
        ClapTrap lung("Lung");

        flu.attack("Lung");
        lung.takeDamage(3);
        lung.beRepaired(4);
    }
    std::cout << '\n';

    {
        ClapTrap flu("Flu");
        ClapTrap liver("Liver");

        flu.attack("Liver");
        liver.takeDamage(1);
        liver.beRepaired(4);

        for (int i = 1; i < 10; ++i) {
            std::cout << i << ": ";
            flu.attack("Liver");
            std::cout << i << ": ";
            liver.takeDamage(1);
        }

        flu.attack("Liver");  // Final attack when energy might be depleted
    }
    std::cout << '\n';

    {
        ClapTrap cancer("Cancer");
        ClapTrap kidney("Kidney");

        cancer.attack("Kidney");
        kidney.takeDamage(9);
        cancer.attack("Kidney");
        kidney.takeDamage(9);
        cancer.attack("Kidney");
        kidney.takeDamage(9);
    }
    std::cout << '\n';

    return 0;
}