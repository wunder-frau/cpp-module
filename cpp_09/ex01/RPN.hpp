#pragma once

#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>

class RPN {
public:
    RPN();
    int compute(const std::string& expression);

    class RPNException : public std::exception {
    public:
        RPNException(const std::string& msg);
        virtual const char* what() const throw();

    private:
        std::string _msg;
    };

private:
    std::stack<int> _stack;
    bool isOperator(const std::string& token) const;
    int applyOp(const std::string& op, int a, int b) const;
};
