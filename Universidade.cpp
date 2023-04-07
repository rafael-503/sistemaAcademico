#include "Universidade.h"
#include <iostream>
#include <cstring>


Universidade::Universidade(): objDepartamentos(){}

Universidade::~Universidade(){}

void Universidade::setNome(const char* n){
    std::strcpy(nome, n);
}

char* Universidade::getNome(){
    return nome;
}


void Universidade::setDepartamento(Departamento* pdep){
    objDepartamentos.incluiInfo(pdep);
}

void Universidade::listaDepartamentos(){
    objDepartamentos.listaInfos();
}

void Universidade::listaDepartamentosInv(){
    //objDepartamentos.listaDepartamentosInv();
}