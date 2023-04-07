#include "Universidade.h"
#include <iostream>
#include <cstring>


Universidade::Universidade(int i): objDepartamentos(){
    id = i;
}

Universidade::~Universidade(){}

void Universidade::setNome(const char* n){
    std::strcpy(nome, n);
    objDepartamentos.setNome(n);
}

char* Universidade::getNome(){
    return nome;
}

int Universidade::getID(){
    return id;
}

void Universidade::incluiDepartamento(Departamento* pdep){
    objDepartamentos.incluiDepartamento(pdep);
}

void Universidade::listaDepartamentos(){
    objDepartamentos.listaDepartamentos();
}

void Universidade::listaDepartamentosInv(){
    objDepartamentos.listaDepartamentosInv();
}