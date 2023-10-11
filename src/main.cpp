#include "../include/BooleanEvaluation.hpp"
#include "../include/Stack.hpp"
#include "../include/BinaryTree.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

void parse_args(int argc, char* argv[], string problem_Type)
{
    if (argc != 4)
    {
        cerr << "Usage: ./Executable_name <Problem type> <Representation formula> <Valuation>" << endl;
        return;
    }

    string expression (argv[2]);  // String that represents the formula
    string valuation  (argv[3]);  // String that represents the variable values in the forumla

    try
    {
        if (problem_Type == "-a")
        {
            cout << "Problema escolhido: Avaliacao de expressoes" << endl;

            BooleanEvaluation avaliacao;
            cout << "Result: " << avaliacao.evaluateExpression(expression, valuation) << endl;
        }
        else if (problem_Type == "-s")
        {
            cout << "Problema escolhido: Satisfabilidade" << endl;

            BooleanEvaluation avaliacao;
            avaliacao.satisfiabilityProblem(expression, valuation);
        }
        else
        {
            throw invalid_argument("Invalid problem type. Use '-a' for expression evaluation or '-s' for satisfiability.");
        }
    }
    catch (const exception &e)
    {
        cerr << "Exception caught: " << e.what() << endl;
    }
}

int main(int argc, char *argv[])
{
    string problem_Type (argv[1]); // What is the problem the user wants

    parse_args(argc, argv, problem_Type);

    return 0;
}
