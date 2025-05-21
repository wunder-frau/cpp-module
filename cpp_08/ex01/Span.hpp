#pragma once

#include <algorithm>
#include <iterator>
#include <limits>
#include <stdexcept>
#include <vector>

class Span {
private:
    unsigned int _maxSize;
    std::vector<int> _data;

public:
    Span(unsigned int N);
    ~Span();

    Span(const Span& other);
    Span& operator=(const Span& other);

    void addNumber(int number);

    template <typename InputIt>
    void addNumber(InputIt begin, InputIt end) {
        if (std::distance(begin, end) + _data.size() > _maxSize)
            throw std::overflow_error("Exceeds Span capacity.");
        _data.insert(_data.end(), begin, end);
    }

    int shortestSpan() const;
    int longestSpan() const;
};
