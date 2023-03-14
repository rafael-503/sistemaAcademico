#include "Universidade.h"
#include <iostream>
#include <cstring>

Universidade::Universidade(const char* n){
    int i;
    for(i=0; i<50; i++)
        pDpto[i] = nullptr;
}

Universidade::~Universidade(){}

void Universidade::setNome(const char* n){
    std::strcpy(nome, n);
}

char* Universidade::getNome(){
    return nome;
}

void Universidade::setDepartamento(Departamento* pdep, int i){
    pDpto[i] = pdep;
}

void Universidade::imprimeDepartamentos(){
    for(int i=0; i<50; i++){
        if(pDpto[i])
            std::cout << pDpto[i]->getNome() << std::endl;
    }
}