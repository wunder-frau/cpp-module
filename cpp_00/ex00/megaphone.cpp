#include <iostream>
#include <string>

int main(int argc, char **argv) {
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;

        return 0;
    }
    int i = 1;
    for (; i < argc; i++) {
        // for (int j = 0; argv[i][j] != '\0'; j++) {
        for (char &c : std::string(argv[i])) {
            // (void)c;
            std::cout << static_cast<char>(std::toupper(c));
        }
    }
    if (i < argc - 1) {
        std::cout << " ";
    }

    std::cout << std::endl;

    return 0;
}
