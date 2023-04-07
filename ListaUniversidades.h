#pragma once
#include "Elemento.h"
#include "Lista.h"
#include "Universidade.h"

class ListaUniversidades{
private:
    int cont_univ;
    int numero_univ;
    char nome[100];
    Lista<Universidade> LTUniversidades;

public:
    ListaUniversidades(int nu=1000, const char* n="");
    virtual ~ListaUniversidades();
    void incluiUniversidade(Universidade* pu);
    void listaUniversidades();
    void listaUniversidadesInv();
    Universidade* localizar(const char* n);
};