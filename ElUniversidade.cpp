#include "ElUniversidade.h"

ElUniversidade::ElUniversidade(){
    pUniversidade = nullptr;
    pProx = nullptr;
    pAnt = nullptr;
}

ElUniversidade::~ElUniversidade(){
    pUniversidade = nullptr;
    pProx = nullptr;
    pAnt = nullptr;
}

void ElUniversidade::setUniversidade(Universidade* pu){
    pUniversidade = pu;
}

Universidade* ElUniversidade::getUniversidade(){
    return pUniversidade;
}

char* ElUniversidade::getNome(){
    return pUniversidade->getNome();
}