#include <iostream>
#include <string>
#include <stdlib.h>
#include <errno.h>

using namespace std;

void parse_args(int argc, char* argv[], string problem_Type)
// Descricao: Faz o tratamento dos argumentos passados no main()
{
    //COLOCAR EM UM ARQUIVO SEPARADO PARA MSSGASSERT!
    if(argc != 4){
        cerr << " ./Executable_name " << "<Problem type> " << "<Representation formula> " << "<Valuation>" << endl;
    }
    if(problem_Type == "-a"){
        cout << "Problema escolhido: Avaliacao de expressoes" << endl;
        //chamar uma função para receber as strings valuation e repr_formula
    }
    else if(problem_Type == "-s"){
        cout << "Problema escolhido: Satisfabilidade" << endl;
    }
}

    

int main(int argc, char* argv[]){

    string problem_Type (argv[1]);

    //String that represents the formula
    string repr_Formula (argv[2]);

    //String that represents the variable values in the forumla
    string valuation    (argv[3]);

    parse_args(argc, argv, problem_Type);

    cout << problem_Type << " " << repr_Formula << " " << valuation << endl;

    return 0;
}