#include "Departamento.h"
#include <cstring>

Departamento::Departamento(){
    std::strcpy(nome, "");
}

Departamento::~Departamento(){}

void Departamento::setNome(const char* n){
    std::strcpy(nome, n);
}

char* Departamento::getNome(){
    return nome;
}