#include "Principal.h"
#include "Universidade.h"
#include <ctime>

Principal::Principal() : 
Einsten(),
Newton()
{
    Einsten.inicializa(14, 3, 1879, "Albert Einstein");
    Newton.inicializa(4, 1, 1643, "Isaac Newton");

    Princeton.setNome("Princeton University");
    FisicaPrinceton.setNome("Fisica");
    Princeton.setDepartamento(&FisicaPrinceton);
    Einsten.setUnivFiliado(&Princeton);
    Einsten.setDptoFiliado(&FisicaPrinceton);

    Cambdrige.setNome("Cambdrige University");
    MatematicaCambdrige.setNome("Matematica");
    Cambdrige.setDepartamento(&MatematicaCambdrige);
    Newton.setUnivFiliado(&Cambdrige);
    Newton.setDptoFiliado(&MatematicaCambdrige);

    UTFPR.setNome("UTFPR");
    DAINF.setNome("DAINF");
    UTFPR.setDepartamento(&DAINF);
    //DAINF.setUniversidade(&UTFPR);

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
    Einsten.ondeTrabalho();
    Einsten.qualDepartamentoTrabalho();

    Newton.calc_idade_imprime(diaAtual, mesAtual, anoAtual);
    Newton.ondeTrabalho();
    Newton.qualDepartamentoTrabalho();
    UTFPR.imprimeDepartamentos();
    Cambdrige.imprimeDepartamentos();
    Princeton.imprimeDepartamentos();
}