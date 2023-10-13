#include "../include/BooleanEvaluation.hpp"
#include "../include/Stack.hpp"
#include "../include/BinaryTree.hpp"
#include "../include/Node.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

std::string BooleanEvaluation::variableAssignment(std::string& expression, const std::string& valuation) {
        unsigned int valuationIndex = 0; // Track the index in the valuation string

        // Check if the valuation string contains only allowed characters
        for (char ch : valuation) {
            if (!(ch == '0' || ch == '1' || ch == 'a' || ch == 'e')) {
                throw std::invalid_argument("Invalid character in valuation. Allowed characters are '0', '1', 'a', 'e'.");
            }
        }

        for (unsigned i = 0; i < expression.size(); i++) {
            char ch = expression[i];
            if (isdigit(ch)) {
                // Convert the digit to an index and check if it's a valid index
                int index = ch - '0';
                if (index < 0 || index >= static_cast<int>(valuation.size())) {
                    throw std::invalid_argument("Invalid index in expression. Ensure indices are within the valuation size.");
                }

                // Replace the digit with the corresponding value from the valuation string
                expression[i] = valuation[index];
            } else if (!(ch == '|' || ch == '&' || ch == '~' || ch == '(' || ch == ')' || ch == ' ')) {
                throw std::invalid_argument("Invalid character in expression. Only digits, '|', '&', '~', '(', ')', and spaces are allowed.");
            }
        }

        return expression;
    }


bool BooleanEvaluation::evaluateExpression(std::string& expression, std::string valuation){
    std::string resultExpression = variableAssignment(expression, valuation);
    return (evaluateExpression(resultExpression));
}

bool BooleanEvaluation::evaluateExpression(const std::string& expression){
    Stack<char> operators;
    Stack<bool> values;

    for (unsigned int i = 0; i < expression.size(); ++i) {
        char ch = expression[i];

        if (ch == ' ') {
            continue; // Skip spaces
        } else if (ch == '(' || ch == '&' || ch == '|' || ch == '~') {
            operators.push(ch);
        } else if (ch == ')') {
            // Evaluate sub-expression
            while (!operators.isEmpty() && operators.top() != '(') {
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
            operators.pop();
        } else if (isdigit(ch)) {
            std::string valueStr;
            while (i < expression.size() && isdigit(expression[i])) {
                valueStr += expression[i];
                ++i;
            }
            --i;

            bool value = (valueStr == "1");
            values.push(value);
        } else {
            std::string valueStr;
            while (i < expression.size() && isdigit(expression[i])) {
                valueStr += expression[i];
                ++i;
            }
            --i;

            bool value = (valueStr == "1");
            values.push(value);
        }
    }

    // Evaluate remaining operators
    while (!operators.isEmpty()) {
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

    bool finalValue = values.top();
    return finalValue;
}


void BooleanEvaluation::satisfiabilityProblem(std::string& expression, std::string& valuation){
    std::string resultExpression = variableAssignment(expression, valuation);
    
    BinaryTree tree (resultExpression);
    std::string result = tree.treeEvaluation(0);
    std::cout << result << std::endl;
    // tree.~BinaryTree();
}





