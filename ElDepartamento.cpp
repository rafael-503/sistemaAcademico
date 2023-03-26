#include "ElDepartamento.h"

ElDepartamento::ElDepartamento(){
    pProx = nullptr;
    pAnt = nullptr;
}

ElDepartamento::~ElDepartamento(){
    pProx = nullptr;
    pAnt = nullptr;
}

void ElDepartamento::setDepartamento(Departamento* pd){
    pDepartamento = pd;
}

Departamento* ElDepartamento::getDepartamento(){
    return pDepartamento;
}

char* ElDepartamento::getNome(){
    return pDepartamento->getNome();
}