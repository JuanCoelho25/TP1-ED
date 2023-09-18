#include "BooleanEvaluation.hpp"
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

bool BooleanEvaluation::evaluateExpression(const std::string& expression, const std::unordered_map<int, bool>& variableMap){
        std::stack<char> operators;
        std::stack<bool> values;

        for (char ch : expression) {
            if (ch == ' ') {
                continue; // Skip spaces
            } else if (ch == '(' || ch == '&' || ch == '|' || ch == '~') {
                operators.push(ch);
            } else if (ch == ')') {
                // Handle closing parenthesis
                while (!operators.empty() && operators.top() != '(') {
                    char op = operators.top();
                    operators.pop();

                    if (op == '~') {
                        bool operand = values.top();
                        values.pop();
                        values.push(!operand); // Apply NOT operation
                    } else {
                        bool operand2 = values.top();
                        values.pop();
                        bool operand1 = values.top();
                        values.pop();

                        if (op == '&') {
                            values.push(operand1 && operand2);
                        } else if (op == '|') {
                            values.push(operand1 || operand2);
                        }
                    }
                }
                operators.pop(); // Pop the '('
            } else {
                // Handle variables
                int variable = ch - '0';
                values.push(variableMap.at(variable));
            }
        }

        // Handle remaining operators
        while (!operators.empty()) {
            char op = operators.top();
            operators.pop();

            if (op == '~') {
                bool operand = values.top();
                values.pop();
                values.push(!operand);
            } else {
                bool operand2 = values.top();
                values.pop();
                bool operand1 = values.top();
                values.pop();

                if (op == '&') {
                    values.push(operand1 && operand2);
                } else if (op == '|') {
                    values.push(operand1 || operand2);
                }
            }
        }

    return values.top();
}