#pragma once
#include <string>

class Weapon {
public:
    Weapon(const std::string& type);

    const std::string& getType() const;

    void setType(const std::string& newType);

private:
    std::string type_;
};