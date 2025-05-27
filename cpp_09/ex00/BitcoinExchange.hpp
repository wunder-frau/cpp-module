#pragma once

#include <map>
#include <string>

class BitcoinExchange {
public:
    BitcoinExchange(const std::string& dbFilename);
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);

    void processInputFile(const std::string& inputFilename) const;

private:
    std::map<std::string, float> _exchangeRates;

    bool isValidDate(const std::string& date) const;
    bool isValidValue(const std::string& value) const;
    float getClosestRate(const std::string& date) const;
    void loadDatabase(const std::string& filename);
};
