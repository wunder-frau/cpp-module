#pragma once
#include <string>

struct Data {
    int integer;
    std::string text;

    Data(int i, const std::string& t) : integer(i), text(t) {}
};