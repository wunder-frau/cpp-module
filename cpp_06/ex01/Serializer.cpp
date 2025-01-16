#include "Serializer.hpp"

#include <iostream>
uintptr_t Serializer::serialize(Data* ptr) {
    if (!ptr) {
        throw std::invalid_argument("Cannot serialize a null pointer");
    }
    // std::cout << "Pointer before serialization: " << static_cast<void*>(ptr)
    //           << std::endl;
    uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
    // std::cout << "raw address after serialization (uintptr_t): " << raw
    //           << std::endl;

    return raw;
}

Data* Serializer::deserialize(uintptr_t raw) {
    if (raw == 0) {
        throw std::invalid_argument(
            "Cannot deserialize from a null raw address");
    }
    // std::cout << "Raw address before deserialization: " << raw << std::endl;
    Data* ptr = reinterpret_cast<Data*>(raw);
    // std::cout << "Pointer after deserialization: " << static_cast<void*>(ptr)
    //           << std::endl;

    return ptr;
}
