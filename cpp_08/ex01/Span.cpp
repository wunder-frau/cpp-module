#include "Span.hpp"

Span::Span(unsigned int N) : _maxSize(N) {}

Span::~Span() {}

Span::Span(const Span& other) = default;
Span& Span::operator=(const Span& other) = default;

void Span::addNumber(int number) {
    if (_data.size() >= _maxSize)
        throw std::overflow_error("Span is full.");
    _data.push_back(number);
}

int Span::shortestSpan() const {
    if (_data.size() < 2)
        throw std::logic_error("Not enough elements for span.");

    std::vector<int> sorted(_data);
    std::sort(sorted.begin(), sorted.end());

    int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sorted.size(); ++i) {
        int diff = sorted[i] - sorted[i - 1];
        if (diff < minSpan)
            minSpan = diff;
        if (minSpan == 0)
            break;
    }

    return minSpan;
}

int Span::longestSpan() const {
    if (_data.size() < 2)
        throw std::logic_error("Not enough elements for span.");

    auto [minIt, maxIt] = std::minmax_element(_data.begin(), _data.end());
    return *maxIt - *minIt;
}
