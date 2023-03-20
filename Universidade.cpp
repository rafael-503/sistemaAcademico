#include "Universidade.h"
#include <iostream>
#include <cstring>
#include <list>

Universidade::Universidade(){}

Universidade::~Universidade(){}

void Universidade::setNome(const char* n){
    std::strcpy(nome, n);
}

char* Universidade::getNome(){
    return nome;
}

void Universidade::setDepartamento(Departamento* pdep){
    if(pdep != nullptr)
        LpDptos.push_back(pdep);
}

void Universidade::imprimeDepartamentos(){
    std::list <Departamento*>::iterator it;

    for(it = LpDptos.begin(); it != LpDptos.end(); it++){
        if(*it != nullptr)
            std::cout << (*it)->getNome() << std::endl;
    }
}