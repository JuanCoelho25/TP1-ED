#include "BooleanEvaluation.hpp"
#include "Stack.hpp"
#include <iostream>
#include <string>

using namespace std;

void parse_args(int argc, char* argv[], string problem_Type)
// Descricao: Faz o tratamento dos argumentos passados no main()
{

    string expression   (argv[2]); //String that represents the formula
    string valuation    (argv[3]); //String that represents the variable values in the forumla

    int size = valuation.size();


    if(problem_Type == "-a"){
        cout << "Problema escolhido: Avaliacao de expressoes" << endl;

        // Populate the array with variable-value pairs
        bool* variableArray = new bool [size];
        for (unsigned int i = 0; i < valuation.size(); ++i) {
            variableArray[i + 1] = (valuation[i] == '1');
        }

        BooleanEvaluation avaliacao;
        cout << "Result: " << avaliacao.evaluateExpression(expression, variableArray) << endl;
        delete variableArray;
    }

    else if(problem_Type == "-s"){
        cout << "Problema escolhido: Satisfabilidade" << endl;

        for (char ch : expression) {
            int i = 0;
            if(ch == 0 || ch == 1 || ch == 'a' || ch == 'e'){
                expression[i] = ch;
            }
            i++;
        }

        BooleanEvaluation avaliacao;
        cout << "Result: " << avaliacao.satisfiabilityProblem(expression, valuation) << endl;
    }
    //**Tentar fazer um try catch para pegar a exceção quando a opção escolhida é diferente de -a ou -s**
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