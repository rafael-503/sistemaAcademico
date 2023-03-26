#pragma once
#include "ElUniversidade.h"
#include "Universidade.h"

class ListaUniversidades{
private:
    int cont_univ;
    int numero_univ;
    char nome[100];
    ElUniversidade* pElUniversidadePrim;
    ElUniversidade* pElUniversidadeAtual;

public:
    ListaUniversidades(int nu=1000, const char* n="");
    ~ListaUniversidades();
    void incluiUniversidade(Universidade* pu);
    void listaUniversidades();
    void listaUniversidadesInv();
    Universidade* localizar(const char* n);
};