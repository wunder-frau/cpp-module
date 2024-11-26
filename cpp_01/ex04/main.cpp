#include <iostream>
#include <string>

#include "SedForLosers.hpp"

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "Usage: ./sed <filename> <string1> <string2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    SedForLosers sed(filename, s1, s2);

    if (sed.process()) {
        std::cout << "File processed successfully! Replaced text is in "
                  << filename << ".replace." << std::endl;
    } else {
        std::cerr << "Error processing file." << std::endl;
    }
    return 0;
}
