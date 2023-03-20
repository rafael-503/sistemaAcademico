#include "Universidade.h"
#include <iostream>
#include <cstring>

Universidade::Universidade(const char* n){
    int i;
    for(i=0; i<50; i++)
        LpDptos[i] = nullptr;
}

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
    int size = LpDptos.size();
    for(int i=0; i<size; i++){
        if(LpDptos[i] != nullptr)
            std::cout << LpDptos[i]->getNome() << std::endl;
    }
}