#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <limits>
#include <iomanip>

BitcoinExchange::BitcoinExchange(const std::string& dbFilename) {
    loadDatabase(dbFilename);
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
    : _exchangeRates(other._exchangeRates) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        _exchangeRates = other._exchangeRates;
    }
    return *this;
}

void BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open database file.");
    }

    std::getline(file, line); // skip header

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date, rateStr;
        if (std::getline(ss, date, ',') && std::getline(ss, rateStr)) {
            _exchangeRates[date] = std::strtof(rateStr.c_str(), NULL);
        }
    }
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    int y, m, d;
    if (sscanf(date.c_str(), "%d-%d-%d", &y, &m, &d) != 3)
        return false;
    if (y < 0 || m < 1 || m > 12 || d < 1 || d > 31)
        return false;
    return true;
}

bool BitcoinExchange::isValidValue(const std::string& value) const {
    try {
        float f = std::stof(value);
        if (f < 0)
            return false;
        if (f > 1000)
            return false;
    } catch (...) {
        return false;
    }
    return true;
}

float BitcoinExchange::getClosestRate(const std::string& date) const {
    std::map<std::string, float>::const_iterator it = _exchangeRates.lower_bound(date);
    if (it != _exchangeRates.end() && it->first == date)
        return it->second;
    if (it == _exchangeRates.begin())
        return 0.0f;
    --it;
    return it->second;
}

void BitcoinExchange::processInputFile(const std::string& inputFilename) const {
    std::ifstream file(inputFilename);
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); // skip header
    while (std::getline(file, line)) {
        size_t delim = line.find('|');
        if (delim == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, delim);
        std::string value = line.substr(delim + 1);
        date.erase(date.find_last_not_of(" \t") + 1);
        value.erase(0, value.find_first_not_of(" \t"));

        if (!isValidDate(date)) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        if (!isValidValue(value)) {
            try {
                float f = std::stof(value);
                if (f < 0)
                    std::cerr << "Error: not a positive number." << std::endl;
                else if (f > 1000)
                    std::cerr << "Error: too large a number." << std::endl;
                else
                    std::cerr << "Error: invalid value => " << value << std::endl;
            } catch (...) {
                std::cerr << "Error: invalid value => " << value << std::endl;
            }
            continue;
        }

        float val = std::stof(value);
        float rate = getClosestRate(date);
        float result = val * rate;

        std::cout << date << " => " << val << " = " << std::fixed << std::setprecision(2) << result << std::endl;
    }
}
