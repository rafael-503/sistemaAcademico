#include "Departamento.h"
#include "Universidade.h"
#include "Disciplina.h"
#include "ListaDisciplinas.h"
#include <cstring>
#include <iostream>

Departamento::Departamento(int i): id(i){
    objDisciplinas = new ListaDisciplinas();
}

Departamento::~Departamento(){
    if(objDisciplinas != nullptr)
        delete objDisciplinas;
}

int Departamento::getId(){
    return id;
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