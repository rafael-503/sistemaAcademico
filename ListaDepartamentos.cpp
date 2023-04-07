#include "ListaDepartamentos.h"
#include <cstring>
#include <iostream>

ListaDepartamentos::ListaDepartamentos(int nd, const char* n){
    numero_dep = nd;
    cont_dep = 0;
    strcpy(nome, n);
}

ListaDepartamentos::~ListaDepartamentos(){}

void ListaDepartamentos::setNome(const char* n){
    std::strcpy(nome, n);
}

void ListaDepartamentos::incluiDepartamento(Departamento* pd){
    if((cont_dep < numero_dep) && (pd != nullptr))
        LTDepartamento.incluiInfo(pd, pd->getNome());
    else{
        if(pd == nullptr)
            std::cout << "Erro: ponteiro departamento nulo" << std::endl;
        else
            std::cout << "Erro: departamento não incluido, quantidadade de departamentos lotada" << std::endl;
    }
}

void ListaDepartamentos::listaDepartamentos(){
    Elemento<Departamento>* pElAux = nullptr;
    Departamento* pDeAux = nullptr;
    pElAux = LTDepartamento.getPrimeiro();

    while(pElAux != nullptr){
        pDeAux = pElAux->getInfo();
        std::cout << "Departamento " << pDeAux->getNome() << " da universidade "<< nome <<std::endl;
        pElAux = pElAux->getProximo();
    }
}

void ListaDepartamentos::listaDepartamentosInv(){
    Elemento<Departamento>* pElAux = nullptr;
    Departamento* pDeAux = nullptr;
    pElAux = LTDepartamento.getAtual();

    while(pElAux != nullptr){
        pDeAux = pElAux->getInfo();
        std::cout << "Departamento " << pDeAux->getNome() << " da universidade "<< nome <<std::endl;
        pElAux = pElAux->getAnterior();
    }
}

Departamento* ListaDepartamentos::localizar(const char* n){
    Elemento<Departamento>* pAux = nullptr;
    pAux = LTDepartamento.getPrimeiro();

    while (pAux != nullptr){
        if(strcmp(pAux->getInfo()->getNome(), n) == 0)
            return pAux->getInfo();
        pAux = pAux->getProximo();
    }
    return nullptr;
}