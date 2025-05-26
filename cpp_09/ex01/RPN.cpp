#include "RPN.hpp"

#include <cctype>

RPN::RPN() {}

RPN::RPNException::RPNException(const std::string& msg)
    : _msg("Error: " + msg) {}
const char* RPN::RPNException::what() const throw() { return _msg.c_str(); }

bool RPN::isOperator(const std::string& token) const {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

int RPN::applyOp(const std::string& op, int a, int b) const {
    if (op == "+")
        return a + b;
    if (op == "-")
        return a - b;
    if (op == "*")
        return a * b;
    if (op == "/") {
        if (b == 0)
            throw RPNException("division by zero");
        return a / b;
    }
    throw RPNException("unknown operator");
}

int RPN::compute(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (token.size() == 1 && std::isdigit(token[0])) {
            _stack.push(token[0] - '0');
        } else if (isOperator(token)) {
            if (_stack.size() < 2)
                throw RPNException("not enough operands");
            int b = _stack.top();
            _stack.pop();
            int a = _stack.top();
            _stack.pop();
            int result = applyOp(token, a, b);
            _stack.push(result);
        } else {
            throw RPNException("invalid token: '" + token + "'");
        }
    }

    if (_stack.size() != 1)
        throw RPNException("expression is malformed");

    return _stack.top();
}
