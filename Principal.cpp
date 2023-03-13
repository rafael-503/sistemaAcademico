#include "Principal.h"
#include <ctime>

Principal::Principal() : 
Einsten(),
Newton()
{
    Einsten.inicializa(14, 3, 1879, "Albert Einstein");
    Newton.inicializa(4, 1, 1643, "Isaac Newton");

    time_t now = time(nullptr);
    tm *local = localtime(&now);
    diaAtual = local->tm_mday;
    mesAtual = local->tm_mon + 1;
    anoAtual = local->tm_year + 1900;

    executar();
}

Principal::~Principal(){}

void Principal::executar(){
    Einsten.calc_idade_imprime(diaAtual, mesAtual, anoAtual);
    Newton.calc_idade_imprime(diaAtual, mesAtual, anoAtual);
}