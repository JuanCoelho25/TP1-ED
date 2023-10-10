#include "BooleanEvaluation.hpp"
#include "Stack.hpp"
#include <iostream>
#include <string>

std::string BooleanEvaluation::variableAssignment(std::string& expression, const std::string& valuation){
    unsigned int valuationIndex = 0; // Track the index in the valuation string

        //Assignment of the string P value
        for (unsigned i = 0; i < expression.size(); i++) {
            char ch = expression[i];

            if (ch != '|' && ch != '&' && ch != '~' && ch != '(' && ch != ')' && ch != ' ') {
                // Check if the valuationIndex is within the bounds of the valuation string
                if (valuationIndex < valuation.size()) {
                    expression[i] = valuation[valuationIndex++]; // Assign the value from valuation and increment the index
                }
            }
        std::cout << expression[i];
        }
     std::cout << "\n";
    return expression;
}

bool BooleanEvaluation::evaluateExpression(const std::string& expression, std::string valuation){
    Stack<char> operators;
    Stack<bool> values;
    int size = valuation.size();

        // Populate the array with variable-value pairs
        bool* variableArray = new bool [size];
        for (unsigned int i = 0; i < valuation.size(); ++i) {
            variableArray[i] = (valuation[i] == '1');
        }

    for (char ch : expression) {
        if (ch == ' ') {
            continue; // Skip the spaces
        } else if (ch == '(' || ch == '&' || ch == '|' || ch == '~') {
            operators.push(ch);
        } else if (ch == ')') {
            while (!operators.isEmpty() && operators.top() != '(') {
                char op = operators.top();
                operators.pop();

                if (op == '~') {
                    bool operand = values.top();
                    values.pop();
                    values.push(!operand); // Applies not
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
            operators.pop(); // Removes '('
        } else {
            int variable = ch - '0';
            values.push(variableArray[variable]);
        }
    }

    // Remaining operators
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
    operators.~Stack();
    values.~Stack();
    return finalValue;
    delete variableArray;
}

bool BooleanEvaluation::satisfiabilityProblem(std::string& expression, const std::string& valuation){
    std::string resultExpression = variableAssignment(expression, valuation);
    
}