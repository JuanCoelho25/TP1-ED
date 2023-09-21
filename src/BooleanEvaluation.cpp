#include "BooleanEvaluation.hpp"
#include "Stack.hpp"
#include <iostream>
#include <string>

bool BooleanEvaluation::evaluateExpression(const std::string& expression, const std::string& valuation){
    Stack<char> operators;
    Stack<bool> values;

    int size = valuation.size();
    bool* variableArray = new bool [size];

    // Populate the array with variable-value pairs
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

    return values.top();
}

bool BooleanEvaluation::satisfiabilityProblem(const std::string& expression, std::string& valuation){
    for (unsigned int i = 0; i < valuation.size(); ++i) {
        if (valuation[i] == 'e') {
            // Replace 'e' with '1' to represent true or any other character you prefer
            valuation[i] = '1'; // Replace with your desired character
            
            BooleanEvaluation firstExpression;
            //Aqui há um erro pois o primeiro caracter é 1 e não 0;
            bool result1 = firstExpression.evaluateExpression(expression, valuation);
            
            // You can choose to replace '1' with '0' or another character for the second case
            valuation[i] = '0'; // Replace with your desired character
            BooleanEvaluation secondExpression;
            bool result2 = secondExpression.evaluateExpression(expression, valuation);

            return (result1 || result2);
        }
    }
    


}