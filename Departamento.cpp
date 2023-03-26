#include "Departamento.h"
#include "Universidade.h"
#include "Disciplina.h"
#include "ListaDisciplinas.h"
#include <cstring>
#include <iostream>

Departamento::Departamento(){
    pDisciplPrim = nullptr;
    pDisciplAtual = nullptr;
    objDisciplinas = new ListaDisciplinas(-1, "");
}

Departamento::~Departamento(){
    pDisciplPrim = nullptr;
    pDisciplAtual = nullptr;

    if(objDisciplinas != nullptr)
        delete objDisciplinas;
}

void Departamento::setNome(const char* n){
    std::strcpy(nome, n);
    objDisciplinas->setNome(n);
}

char* Departamento::getNome(){
    return nome;
}

void Departamento::setUniversidade(Universidade* pu){
    pUniv = pu;
}

Universidade* Departamento::getUniversidade(){
    return pUniv;
}

void Departamento::incluiDisciplina(Disciplina* pd){
    objDisciplinas->incluiDisciplina(pd);
}

void Departamento::listaDisciplinas(){
    objDisciplinas->listaDisciplinas();
}

void Departamento::listaDisciplinasInv(){
    objDisciplinas->listaDisciplinasInv();
}