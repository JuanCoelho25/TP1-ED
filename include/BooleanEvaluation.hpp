#ifndef BOOLEANEVALUATION_HPP
#define BOOLEANEVALUATION_HPP

#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

class BooleanEvaluation{

    public:

    // Evaluates the boolean expression
    bool evaluateExpression(const std::string& expression, const std::unordered_map<int, bool>& variableMap);

    // Determines whether there exists an assignment of truth values 
    bool satisfiabilityProblem();


};

#endif
