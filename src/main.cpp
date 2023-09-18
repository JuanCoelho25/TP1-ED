#include <iostream>
#include <string>
#include <stdlib.h>
#include <errno.h>
#include <unordered_map>
#include <BooleanEvaluation.hpp>

using namespace std;

void parse_args(int argc, char* argv[], string problem_Type)
// Descricao: Faz o tratamento dos argumentos passados no main()
{

    string expression   (argv[2]); //String that represents the formula
    string valuation    (argv[3]); //String that represents the variable values in the forumla

    if(problem_Type == "-a"){
        cout << "Problema escolhido: Avaliacao de expressoes" << endl;

        std::unordered_map<int, bool> variableMap;

        // Populate the map with variable-value pairs
        for (unsigned int i = 0; i < valuation.size(); ++i) {
            variableMap[i] = (valuation[i] == '1');
        }

        BooleanEvaluation avaliacao;
        cout << "Result: " << avaliacao.evaluateExpression(expression, variableMap) << endl;

    }
    else if(problem_Type == "-s"){
        cout << "Problema escolhido: Satisfabilidade" << endl;


    }
}

    

int main(int argc, char* argv[]){

     //COLOCAR EM UM ARQUIVO SEPARADO PARA MSSGASSERT!
    if(argc != 4){
        cerr << " ./Executable_name " << "<Problem type> " << "<Representation formula> " << "<Valuation>" << endl;
    }

    string problem_Type (argv[1]); // What is the problem the user wants

    parse_args(argc, argv, problem_Type);


    return 0;
}