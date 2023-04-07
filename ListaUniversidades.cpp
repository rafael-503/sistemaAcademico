#include "ListaUniversidades.h"
#include <cstring>
#include <iostream>

ListaUniversidades::ListaUniversidades(int nu, const char* n){
    cont_univ = 0;
    numero_univ = nu;
    strcpy(nome, n);
}

ListaUniversidades::~ListaUniversidades(){
    LTUniversidades.limpar();
}

void ListaUniversidades::incluiUniversidade(Universidade* pu){
    if((cont_univ < numero_univ) && (pu != nullptr)){
        LTUniversidades.incluiInfo(pu, pu->getNome());
        cont_univ++;
    }
    else{
        if(pu == nullptr)
            std::cout << "Erro: Ponteiro universidade nulo" << std::endl;
        else
            std::cout << "Erro: Universidade nao incluida, lista lotada." << std::endl;
    }
}

void ListaUniversidades::listaUniversidades(){
    Elemento<Universidade>* pElAux = nullptr;
    Universidade* pUnAux = nullptr;
    pElAux = LTUniversidades.getPrimeiro();

    while(pElAux != nullptr){
        pUnAux = pElAux->getInfo();
        std::cout << "Universidade " << pUnAux->getNome() << " no sistema " << nome << std::endl;
        pElAux = pElAux->getProximo();
    }
}

void ListaUniversidades::listaUniversidadesInv(){
    Elemento<Universidade>* pElAux = nullptr;
    Universidade* pUnAux = nullptr;
    pElAux = LTUniversidades.getAtual();

    while(pElAux != nullptr){
        pUnAux = pElAux->getInfo();
        std::cout << "Universidade " << pUnAux->getNome() << " no sistema " << nome << std::endl;
        pElAux = pElAux->getAnterior();
    }
}

Universidade* ListaUniversidades::localizar(const char* n){
    Elemento<Universidade>* pAux = nullptr;
    pAux = LTUniversidades.getPrimeiro();
    while(pAux != nullptr){
        if(strcmp(pAux->getInfo()->getNome(), n) == 0){
            return pAux->getInfo();
        }
        pAux = pAux->getProximo();
    }
    return nullptr;
}