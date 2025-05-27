#include "BitcoinExchange.hpp"

int main(int ac, char** av) {
    BitcoinExchange btc;
    btc.processArgsAndFiles(ac, av);
    return 0;
}