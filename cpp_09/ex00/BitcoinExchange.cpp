#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : priceData(other.priceData) {}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        priceData = other.priceData;
    }
    return *this;
}

void BitcoinExchange::processArgsAndFiles(int ac, char** av) {
    if (ac != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        exit(1);
    }
    if (!loadDatabase("data.csv")) {
        std::cerr << "Error: could not open data.csv." << std::endl;
        exit(1);
    }
    processInputFile(av[1]);
}

bool BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) return false;

    std::string line;
    getline(file, line); // Skip header

    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string date, priceStr;

        // Ensure proper CSV format: date,exchange_rate
        if (!getline(ss, date, ',') || !getline(ss, priceStr)) {
            std::cerr << "Warning: Skipping malformed line in CSV: " << line << std::endl;
            continue;
        }

        trim(date);
        trim(priceStr);

        if (!isValidDate(date)) {
            std::cerr << "Warning: Skipping invalid date: " << date << std::endl;
            continue;
        }

        std::stringstream priceStream(priceStr);
        double price;
        priceStream >> price;
        if (priceStream.fail()) {
            std::cerr << "Warning: Skipping invalid price: " << priceStr << std::endl;
            continue;
        }

        priceData[date] = price;
    }

    file.close();
    return !priceData.empty();
}

void BitcoinExchange::processInputFile(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    getline(file, line); // skip header
    while (getline(file, line)) {
        if (!isValidFormat(line)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::stringstream ss(line);
        std::string date, valueStr;
        getline(ss, date, '|');
        getline(ss, valueStr);

        trim(date);
        trim(valueStr);

        double value;
        if (!isValidDate(date)) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        if (!isValidValue(valueStr, value)) {
            continue;
        }

        try {
            double rate = findClosestPrice(date);
            std::cout << std::fixed << std::setprecision(2);
            std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
        } catch (...) {
            std::cerr << "Error: No earlier data available." << std::endl;
        }
    }
    file.close();
}

bool BitcoinExchange::isValidFormat(const std::string& line) {
    return line.find('|') != std::string::npos;
}

void BitcoinExchange::trim(std::string& str) {
    size_t start = str.find_first_not_of(" \t");
    size_t end = str.find_last_not_of(" \t");
    str = (start == std::string::npos) ? "" : str.substr(start, end - start + 1);
}

bool BitcoinExchange::isValidDate(const std::string& date) {
    if (date.size() != 10 || date[4] != '-' || date[7] != '-') return false;
    int y, m, d;
    char dash1, dash2;
    std::stringstream ss(date);
    ss >> y >> dash1 >> m >> dash2 >> d;
    if (ss.fail() || dash1 != '-' || dash2 != '-') return false;
    if (m < 1 || m > 12 || d < 1 || d > 31) return false;
    if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) return false;
    if (m == 2) {
        if (isLeapYear(y) && d > 29) return false;
        if (!isLeapYear(y) && d > 28) return false;
    }
    return true;
}

bool BitcoinExchange::isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchange::isValidValue(const std::string& valueStr, double& outValue) {
    std::stringstream ss(valueStr);
    ss >> outValue;
    if (ss.fail()) {
        std::cerr << "Error: invalid value => " << valueStr << std::endl;
        return false;
    }
    if (outValue < 0) {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    if (outValue > 1000) {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}

double BitcoinExchange::findClosestPrice(const std::string& date) {
    std::map<std::string, double>::iterator it = priceData.lower_bound(date);
    if (it == priceData.end() || it->first != date) {
        if (it == priceData.begin()) throw std::runtime_error("No earlier data");
        --it;
    }
    return it->second;
}