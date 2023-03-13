#include "Principal.h"

Principal::Principal(){
    Einsten.inicializa(14, 3, 1879, "Albert Einstein");
    Newton.inicializa(4, 1, 1643, "Isaac Newton");
    executar();
}

void Principal::executar(){
    Einsten.calc_idade_imprime(12, 3, 2023);
    Newton.calc_idade_imprime(12, 3, 2023);
}