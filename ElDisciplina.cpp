#include "ElDisciplina.h"

ElDisciplina::ElDisciplina(){
    pProx = nullptr;
    pAnt = nullptr;
}

ElDisciplina::~ElDisciplina(){
    pProx = nullptr;
    pAnt = nullptr;
}

void ElDisciplina::setDisciplina(Disciplina* pd){
    pDisciplina = pd;
}

Disciplina* ElDisciplina::getDisciplina(){
    return pDisciplina;
}

char* ElDisciplina::getNome(){
    return pDisciplina->getNome();
}