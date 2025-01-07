#include "SedForLosers.hpp"

#include <fstream>
#include <iostream>

SedForLosers::SedForLosers(const std::string& filename, const std::string& s1,
                           const std::string& s2)
    : filename_(filename), s1_(s1), s2_(s2) {}

SedForLosers::~SedForLosers() {}

bool SedForLosers::process() const {
    std::string content = readFile();
    if (content.empty()) {
        std::cerr << "Error: File is empty or could not be read." << std::endl;
        return false;
    }
    std::string replacedContent = replaceAll(content);
    return writeFile(replacedContent);
}

std::string SedForLosers::readFile() const {
    std::ifstream infile(filename_);
    if (!infile.is_open()) {
        std::cerr << "Error: Cannot open file " << filename_ << std::endl;
        return "";
    }

    std::string content, line;
    while (std::getline(infile, line)) {
        content += line + "\n";
    }
    infile.close();
    return content;
}

bool SedForLosers::writeFile(const std::string& content) const {
    std::ofstream outfile(filename_ + ".replace");
    if (!outfile.is_open()) {
        std::cerr << "Error: Cannot create output file." << std::endl;
        return false;
    }
    outfile << content;
    outfile.close();
    return true;
}

std::string SedForLosers::replaceAll(const std::string& content) const {
    std::string result;
    size_t pos = 0, prev = 0;
    while ((pos = content.find(s1_, prev)) != std::string::npos) {
        result.append(content, prev, pos - prev);
        result.append(s2_);
        prev = pos + s1_.length();
    }
    result.append(content, prev, std::string::npos);
    return result;
}
