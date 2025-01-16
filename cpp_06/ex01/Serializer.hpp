#pragma once

#include <cstdint>

#include "Data.hpp"

class Serializer {
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);

private:
    Serializer() = default;
    Serializer(const Serializer& other) = default;
    Serializer& operator=(const Serializer& other) = default;
    ~Serializer() = default;
};