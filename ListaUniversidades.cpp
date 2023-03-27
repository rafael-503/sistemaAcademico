#include "ListaUniversidades.h"
#include <cstring>
#include <iostream>

ListaUniversidades::ListaUniversidades(int nu, const char* n){
    cont_univ = 0;
    numero_univ = nu;
    strcpy(nome, n);
    pElUniversidadePrim = nullptr;
    pElUniversidadeAtual = nullptr;
}

ListaUniversidades::~ListaUniversidades(){
    ElUniversidade* pAux;
    while(pElUniversidadePrim != nullptr){
        pAux = pElUniversidadePrim;
        pElUniversidadePrim = pElUniversidadePrim->pProx;
        delete pAux;
    }
    pElUniversidadePrim = nullptr;
    pElUniversidadeAtual = nullptr;
}

void ListaUniversidades::incluiUniversidade(Universidade* pu){
    if((cont_univ < numero_univ) && (pu != nullptr)){
        ElUniversidade* pAux = new ElUniversidade();
        pAux->setUniversidade(pu);
        pAux->pProx = nullptr;
        pAux->pAnt = nullptr;

        if(pElUniversidadePrim == nullptr){
            pElUniversidadePrim = pAux;
            pElUniversidadeAtual = pAux;
        }else{
            pElUniversidadeAtual->pProx = pAux;
            pAux->pAnt = pElUniversidadeAtual;
            pElUniversidadeAtual = pAux;
        }
        cont_univ++;
    }
}

void ListaUniversidades::listaUniversidades(){
    ElUniversidade* pAux = pElUniversidadePrim;
    while(pAux != nullptr){
        std::cout << "Universidade: " << pAux->getNome() << std::endl;
        pAux = pAux->pProx;
    }
}

void ListaUniversidades::listaUniversidadesInv(){
    ElUniversidade* pAux = pElUniversidadeAtual;
    while(pAux != nullptr){
        std::cout << "Universidade: " << pAux->getNome() << std::endl;
        pAux = pAux->pAnt;
    }
}

Universidade* ListaUniversidades::localizar(const char* n){
    ElUniversidade* pAux = pElUniversidadePrim;
    while(pAux != nullptr){
        if(strcmp(pAux->getNome(), n) == 0){
            return pAux->getUniversidade();
        }
        pAux = pAux->pProx;
    }
    return nullptr;
}