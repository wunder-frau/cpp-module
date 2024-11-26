#pragma once

#include <string>

class SedForLosers {
public:
    SedForLosers(const std::string &filename, const std::string &s1,
                 const std::string &s2);
    ~SedForLosers();

    bool process();

private:
    std::string _filename;
    std::string _s1;
    std::string _s2;

    std::string readFile();
    std::string replaceAll(const std::string &content);
    bool writeFile(const std::string &content);
};
