#include "Principal.h"
#include "Universidade.h"
#include <ctime>

Principal::Principal(): Einsten(), Newton(), Simao(){
    // leitura da data atual
    time_t now = time(nullptr);
    tm *local = localtime(&now);
    diaAtual = local->tm_mday;
    mesAtual = local->tm_mon + 1;
    anoAtual = local->tm_year + 1900;

    inicializa();
}

Principal::~Principal(){}

void Principal::inicializa(){
    inicializaUniversidades();
    inicializaDepartamentos();
    inicializaProfessores();
    inicializaDisciplinas();
    inicializaAlunos();
}

void Principal::inicializaUniversidades(){
    UTFPR.setNome("UTFPR");
    Princeton.setNome("Princeton University");
    Cambdrige.setNome("Cambdrige University");
}

void Principal::inicializaDepartamentos(){
    DAINF.setNome("DAINF");
    FisicaPrinceton.setNome("Fisica Princeton");
    MatematicaCambdrige.setNome("Matematica Cambdrige");
}

void Principal::inicializaProfessores(){
    // inicializacao dos professores
    Einsten.inicializa(14, 3, 1879, "Albert Einstein");
    Newton.inicializa(4, 1, 1643, "Isaac Newton");
    Simao.inicializa(3, 10, 1976, "Jean Simao");

    // associacao dos professores com as universidades
    Einsten.setUnivFiliado(&Princeton);
    Newton.setUnivFiliado(&Cambdrige);
    Simao.setUnivFiliado(&UTFPR);

    // associacao dos professores com os departamentos
    Einsten.setDptoFiliado(&FisicaPrinceton);
    Newton.setDptoFiliado(&MatematicaCambdrige);
    Simao.setDptoFiliado(&DAINF);
}

void Principal::inicializaDisciplinas(){
    Computacao1.setNome("Computacao 1");
    Computacao2.setNome("Computacao 2");
    Algoritmos.setNome("Algoritmos");
    TecProg.setNome("Tecnicas de Programacao");

    Computacao1.setDepartamento(&DAINF);
    Computacao2.setDepartamento(&DAINF);
    Algoritmos.setDepartamento(&DAINF);
    TecProg.setDepartamento(&DAINF);

    TecProg.incluiAluno(&AAA);
    TecProg.incluiAluno(&BBB);
    Algoritmos.incluiAluno(&CCC);
    Algoritmos.incluiAluno(&DDD);
    TecProg.excluiAluno(&BBB);
    TecProg.excluiAluno(&AAA);
}

void Principal::inicializaAlunos(){
    AAA.setNome("AA");
    AAA.setRA(1);
    BBB.setNome("BB");
    BBB.setRA(2);
    CCC.setNome("CC");
    CCC.setRA(3);
    DDD.setNome("DD");
    DDD.setRA(4);
}

void Principal::calcIdadeProf(){
    Einsten.calc_idade_imprime(diaAtual, mesAtual, anoAtual);
    Newton.calc_idade_imprime(diaAtual, mesAtual, anoAtual);
    Simao.calc_idade_imprime(diaAtual, mesAtual, anoAtual);
}

void Principal::univOndeProfsTrabalham(){
    Einsten.ondeTrabalho();
    Newton.ondeTrabalho();
    Simao.ondeTrabalho();
}

void Principal::dptoOndeProfsTrabalham(){
    Einsten.qualDepartamentoTrabalho();
    Newton.qualDepartamentoTrabalho();
    Simao.qualDepartamentoTrabalho();
}

void Principal::listaDiscDeptos(){
    DAINF.listaDisciplinas();
    FisicaPrinceton.listaDisciplinas();
    MatematicaCambdrige.listaDisciplinas();
}

void Principal::listaAlunosDisc(){
    TecProg.listaAlunos();
    //TecProg.listaAlunosInv(); lista inversa

    //Algoritmos.listaAlunos();
    //Algoritmos.listaAlunosInv(); lista inversa
}

void Principal::executar(){
    //calcIdadeProf();
    //univOndeProfsTrabalham();
    //dptoOndeProfsTrabalham();
    //listaDiscDeptos();
    listaAlunosDisc();
}