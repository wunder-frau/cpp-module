#pragma once

#include <string>

class SedForLosers {
public:
    SedForLosers(const std::string& filename, const std::string& s1,
                 const std::string& s2);
    ~SedForLosers();

    bool process() const;

private:
    std::string filename_, s1_, s2_;

    std::string readFile() const;
    std::string replaceAll(const std::string& content) const;
    bool writeFile(const std::string& content) const;
};
