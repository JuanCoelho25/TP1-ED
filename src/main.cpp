#include <iostream>
#include <string>
#include <stdlib.h>
#include <errno.h>

using namespace std;

void parse_args(int argc, char* argv[])
// Descricao: Faz o tratamento dos argumentos passados no main()
{
    //COLOCAR EM UM ARQUIVO SEPARADO PARA MSSGASSERT!
    if(argc != 4){
        cerr << " ./Executable_name " << "<Problem type> " << "<Representation formula> " << "<Valuation>" << endl;
    }

    string problem_Type (argv[1]);
    string repr_Formula (argv[2]);
    string valuation    (argv[3]);

    cout << problem_Type << " " << repr_Formula << " " << valuation << endl;

    if(problem_Type == "-a"){
        cout << "avaliacao de expressoes" << endl;
    }
    else if(problem_Type == "-s"){
        cout << "satisfabilidade" << endl;
    }
}

int main(int argc, char* argv[]){
    
    parse_args(argc, argv);

    return 0;
}