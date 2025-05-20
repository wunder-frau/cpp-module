#include <iostream>
#include <string>

#include "Serializer.hpp"

/**
 * Parses and validates input arguments.
 * Throws std::exception on invalid input.
 */
Data parseInput(const std::string& intStr, const std::string& text) {
    size_t pos = 0;
    int integer;

    try {
        integer = std::stoi(intStr, &pos);
        if (pos != intStr.length()) {
            throw std::invalid_argument("Extra characters after integer.");
        }
    } catch (const std::out_of_range&) {
        throw std::out_of_range("Integer input is out of range.");
    } catch (const std::invalid_argument&) {
        throw std::invalid_argument("Invalid input: not a valid integer.");
    }

    if (integer < 0) {
        throw std::invalid_argument("Integer must be non-negative.");
    }

    return Data(integer, text);  // Text may be empty — allowed
}

/**
 * Runs a test on the provided Data object.
 */
void runTest(const Data& data) {
    Data* originalPointer = const_cast<Data*>(&data);  // Safe for this usage
    uintptr_t rawAddress = Serializer::serialize(originalPointer);
    Data* deserializedPointer = Serializer::deserialize(rawAddress);

    std::cout << "Running test with Data(" << data.integer << ", \""
              << data.text << "\")\n";

    if (deserializedPointer == originalPointer) {
        std::cout << "✅ Test passed: Pointers match!\n";
    } else {
        std::cout << "❌ Test failed: Pointers do not match.\n";
    }

    std::cout << "Original Data: " << originalPointer->integer << ", "
              << originalPointer->text << "\n";
    std::cout << "Deserialized Data: " << deserializedPointer->integer << ", "
              << deserializedPointer->text << "\n";
    std::cout << "-----------------------------\n";
}

void runNullPointerTest() {
    std::cout << "Running null pointer serialization test...\n";

    try {
        Data* nullPtr = nullptr;
        Serializer::serialize(nullPtr);  // should throw
        std::cout
            << "❌ Error: null pointer was serialized without exception!\n";
    } catch (const std::exception& e) {
        std::cout << "✅ Expected exception on null serialize: " << e.what()
                  << "\n";
    }

    std::cout << "Running null raw deserialization test...\n";

    try {
        uintptr_t nullRaw = 0;
        Serializer::deserialize(nullRaw);  // should throw
        std::cout << "❌ Error: null raw address was deserialized without "
                     "exception!\n";
    } catch (const std::exception& e) {
        std::cout << "✅ Expected exception on null deserialize: " << e.what()
                  << "\n";
    }

    std::cout << "-----------------------------\n";
}

/**
 * Runs a predefined set of automated test cases.
 */
void runAutomatedTests() {
    std::cout
        << "ℹ️  No arguments provided. Running automated test suite...\n\n";

    Data test1(42, "hello");
    Data test2(0, "zero");
    Data test3(123456, "large number");
    Data test4(1, "A");

    runTest(test1);
    runTest(test2);
    runTest(test3);
    runTest(test4);

    runNullPointerTest();

    // Optional: heap-allocated test
    Data* heapData = new Data(999, "heap");
    std::cout << "Running heap allocation test...\n";

    uintptr_t raw = Serializer::serialize(heapData);
    Data* restored = Serializer::deserialize(raw);

    if (restored == heapData) {
        std::cout << "✅ Heap test passed: Pointers match!\n";
    } else {
        std::cout << "❌ Heap test failed: Pointers do not match.\n";
    }

    std::cout << "Heap Data: " << restored->integer << ", " << restored->text
              << "\n";
    std::cout << "-----------------------------\n";

    delete heapData;
}

int main(int argc, char* argv[]) {
    try {
        if (argc == 1) {
            runAutomatedTests();
        } else if (argc == 3) {
            Data userInput = parseInput(argv[1], argv[2]);
            runTest(userInput);
        } else {
            std::cerr
                << "❗ Invalid arguments.\n"
                   "Usage: ./Serializer <non-negative integer> <string>\n";
            return 1;
        }
    } catch (const std::exception& e) {
        std::cerr << "❌ Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
