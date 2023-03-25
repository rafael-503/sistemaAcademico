#include "ElAluno.h"

ElAluno::ElAluno(){
    pProx = nullptr;
    pAnt = nullptr;
}

ElAluno::~ElAluno(){
    pProx = nullptr;
    pAnt = nullptr;
}

void ElAluno::setAluno(Aluno* pa){
    pAluno = pa;
}

Aluno* ElAluno::getAluno(){
    return pAluno;
}

char* ElAluno::getNome(){
    return pAluno->getNome();
}