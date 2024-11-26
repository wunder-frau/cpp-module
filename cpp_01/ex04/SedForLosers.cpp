#include "SedForLosers.hpp"

#include <fstream>
#include <iostream>

SedForLosers::SedForLosers(const std::string &filename, const std::string &s1,
                           const std::string &s2)
    : _filename(filename), _s1(s1), _s2(s2) {}

SedForLosers::~SedForLosers() {}

bool SedForLosers::process() {
    std::string content = readFile();
    if (content.empty()) {
        std::cerr << "Error: File is empty or could not be read." << std::endl;
        return false;
    }
    std::string replacedContent = replaceAll(content);
    return writeFile(replacedContent);
}

std::string SedForLosers::readFile() {
    std::ifstream infile(_filename);
    if (!infile.is_open()) {
        std::cerr << "Error: Cannot open file " << _filename << std::endl;
        return "";
    }

    std::string content, line;
    while (std::getline(infile, line)) {
        content += line + "\n";
    }
    infile.close();
    return content;
}

bool SedForLosers::writeFile(const std::string &content) {
    std::ofstream outfile(_filename + ".replace");
    if (!outfile.is_open()) {
        std::cerr << "Error: Cannot create output file." << std::endl;
        return false;
    }
    outfile << content;
    outfile.close();
    return true;
}

std::string SedForLosers::replaceAll(const std::string &content) {
    std::string result;
    size_t pos = 0, prev = 0;
    while ((pos = content.find(_s1, prev)) != std::string::npos) {
        result.append(content, prev, pos - prev);
        result.append(_s2);
        prev = pos + _s1.length();
    }
    result.append(content, prev, std::string::npos);
    return result;
}
