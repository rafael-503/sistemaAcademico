#include "Pessoa.h"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main(){
    Pessoa Einstein(14, 3, 1879, "Einstein");
    Pessoa Newton(4, 1, 1643, "Newton");

    int dia, mes, ano;
    cout << "Informe dia, mes e ano atual: " << endl;
    cin >> dia >> mes >> ano;

    Newton.calc_idade_imprime(dia, mes, ano);
    Einstein.calc_idade_imprime(dia, mes, ano);

    cout << "Fim do programa" << endl;

    return 0;
}