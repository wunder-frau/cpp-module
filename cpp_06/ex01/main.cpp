#include <iostream>
#include <string>

#include "Serializer.hpp"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <integer> <string>" << std::endl;
        return 1;
    }

    try {
        int integer = std::stoi(argv[1]);
        std::string text = argv[2];

        if (integer < 0) {
            throw std::invalid_argument("integer must be non-negative");
        }
        Data originalData(integer, text);

        Data* originalPointer = &originalData;
        uintptr_t rawAddress = Serializer::serialize(originalPointer);
        Data* deserializedPointer = Serializer::deserialize(rawAddress);
        if (deserializedPointer == originalPointer) {
            std::cout << "Test passed: Pointers match!" << std::endl;
            std::cout << "Original Data: " << originalPointer->integer << ", "
                      << originalPointer->text << std::endl;
            std::cout << "Deserialized Data: " << deserializedPointer->integer
                      << ", " << deserializedPointer->text << std::endl;
        } else {
            std::cout << "Test failed: Pointers do not match." << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
