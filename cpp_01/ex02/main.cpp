#include <iostream>

int main() {
    std::string str = "HI THIS IS BRAIN";
    std::cout << "Step 1: String value = " << str << std::endl;
    std::string* stringPTR = &str;
    std::cout << "Step 2: Address of stringPTR = " << stringPTR << std::endl;
    std::string& stringREF = str;
    std::cout << "Step 3: Address of stringREF = " << &stringREF << std::endl;

    std::cout << "Step 4: Address of string (str) = " << &str << std::endl;
    std::cout << "Address held by stringPTR = " << stringPTR << std::endl;
    std::cout << "Address held by stringREF = " << &stringREF << std::endl;

    std::cout << "Step 5: Value of string = " << str << std::endl;
    std::cout << "Value pointed to by stringPTR = " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF = " << stringREF << std::endl;

    if (stringPTR == &str && &stringREF == &str) {
        std::cout
            << "Step 6: All checks passed: pointer and reference are correct."
            << std::endl;
    } else {
        std::cout << "Step 6: Check failed." << std::endl;
    }
    return 0;
}
