#include "Pessoa.h"
#include <iostream>
using std::cout;
using std::endl;

int main(){
    Pessoa Einstein(14, 3, 1879, "Einstein");
    Pessoa Newton(4, 1, 1643, "Newton");

    //Newton.calc_idade(7, 3, 2023);
    //Einstein.calc_idade(7, 3, 2023);
    
    cout << "Fim do programa" << endl;

    return 0;
}