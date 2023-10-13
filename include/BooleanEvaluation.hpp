#ifndef BOOLEANEVALUATION_HPP
#define BOOLEANEVALUATION_HPP

#include <iostream>
#include <string>

/**
 * @brief Represents a class for evaluating boolean expressions and solving satisfiability problems.
 *
 * The BooleanEvaluation class provides functionality to assign truth values to variables,
 * evaluate boolean expressions with variable assignments, and determine the satisfiability
 * of boolean expressions. It encapsulates methods for these operations.
 */
class BooleanEvaluation {
public:

    /**
     * @brief Assigns truth values to variables based on a given valuation string.
     *
     * This function takes a boolean expression and a valuation string and assigns truth
     * values to variables in the expression based on the provided valuation.
     *
     * @param expression The boolean expression to be evaluated.
     * @param valuation The string representing variable truth values.
     * @return A string with variable assignments.
     */
    std::string variableAssignment(std::string& expression, const std::string& valuation);

    /**
     * @brief Evaluates a boolean expression with a given variable assignment.
     *
     * This function takes a boolean expression and a variable assignment and evaluates
     * the expression based on the provided truth values for variables.
     *
     * @param expression The boolean expression to be evaluated.
     * @param valuation The string representing variable truth values.
     * @return True if the expression evaluates to true, false otherwise.
     */
    bool evaluateExpression(std::string& expression, std::string valuation);

    /**
     * @brief Evaluates a boolean expression without explicit variable assignment.
     *
     * This function takes a boolean expression and evaluates it without requiring
     * a separate variable assignment string. It can be used when variable values
     * are implicitly known or handled elsewhere.
     *
     * @param expression The boolean expression to be evaluated.
     * @return True if the expression evaluates to true, false otherwise.
     */
    bool evaluateExpression(const std::string& expression);

    /**
     * @brief Determines whether there exists an assignment of truth values for satisfiability.
     *
     * This function takes a boolean expression and a valuation string and determines
     * whether there exists an assignment of truth values for which the expression evaluates to true.
     *
     * @param expression The boolean expression to check for satisfiability.
     * @param valuation The string representing variable truth values.
     */
    void satisfiabilityProblem(std::string& expression, std::string& valuation);
};

#endif
