#include "Universidade.h"
#include <cstring>

Universidade::Universidade(const char* n){
    std::strcpy(nome, n);
}

Universidade::~Universidade(){}

void Universidade::setNome(const char* n){
    std::strcpy(nome, n);
}

char* Universidade::getNome(){
    return nome;
}