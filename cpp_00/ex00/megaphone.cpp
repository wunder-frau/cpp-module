#include <iostream>
#include <string>

void ToUpper(std::string &text) {
    for (char &c : text) {
        c = std::toupper(c);
    }
}

int main(int argc, char **argv) {
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }

    for (int i = 1; i < argc; i++) {
        std::string word = argv[i];
        ToUpper(word);
        std::cout << word;
        if (i < argc - 1) {
            std::cout << " ";
        }
    }

    std::cout << std::endl;

    return 0;
}
