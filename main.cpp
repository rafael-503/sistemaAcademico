#include "Pessoa.h"
#include <iostream>

int main(){
    Pessoa Einstein(14, 3, 1879, "Einstein");
    Pessoa Newton(4, 1, 1643, "Newton");

    Newton.calc_idade(7, 3, 2023);
    Einstein.calc_idade(7, 3, 2023);

    //std::cout << "Newton tem " << Newton.getIdade() << " anos" << std::endl;
    //std::cout << "Einstein tem " << Einstein.getIdade() << " anos" << std::endl;
    
    return 0;
}