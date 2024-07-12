#pragma once
#include <iostream>
#include <stack>
#include <sstream>
#include <string>

int postfix_calculator(const std::string&);

int postfix_calculator(const std::string& expression) {
    std::stack<int> Stack;
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (token.size() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')) {
            if (Stack.size() < 2) {
                std::cerr << "Not enough operators for the operation." << token << "." << std::endl;
                return 0;
            }

            int right = Stack.top();
            Stack.pop();
            int left = Stack.top();
            Stack.pop();

            auto op = token[0];
            int result;

            switch (op) {
            case '+': result = left + right; break;
            case '-': result = left - right; break;
            case '*': result = left * right; break;
            case '/':
                if (right == 0) {
                    std::cerr << "It can't be divided by 0" << std::endl;
                    return 0;
                }
                result = left / right;
                break;
            default:
                throw std::exception();
                
            }
            Stack.push(result);
        }
        else if (std::isdigit(token[0])) {
            int value = std::stoi(token);
            Stack.push(value);
        }
        else {
            std::cerr << "Invalid input '" << token << "'." << std::endl;
            return 0;
        }
    }

    if (Stack.size() == 1) {
        return Stack.top();
    }
}