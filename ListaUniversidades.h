#pragma once
#include "Elemento.h"
#include "Universidade.h"

class ListaUniversidades{
private:
    int cont_univ;
    int numero_univ;
    char nome[100];
    Elemento<Universidade>* pElUniversidadePrim;
    Elemento<Universidade>* pElUniversidadeAtual;

public:
    ListaUniversidades(int nu=1000, const char* n="");
    ~ListaUniversidades();
    void incluiUniversidade(Universidade* pu);
    void listaUniversidades();
    void listaUniversidadesInv();
    Universidade* localizar(const char* n);
};