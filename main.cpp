#include "Pessoa.h"
#include <iostream>

int main(){
    struct Pessoa Newton, Einstein;
    Newton.dia = 4;
    Newton.mes = 1;
    Newton.ano = 1643;

    Einstein.dia = 14;
    Einstein.mes = 3;
    Einstein.ano = 1879;

    Newton.idade = calc_idade(Newton, 2023);
    Einstein.idade = calc_idade(Einstein, 2023);

    std::cout << "Newton tem " << Newton.idade << " anos" << std::endl;
    std::cout << "Einstein tem " << Einstein.idade << " anos" << std::endl;
    
}