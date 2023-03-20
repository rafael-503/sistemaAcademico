#include "Departamento.h"
#include "Universidade.h"
#include "Disciplina.h"
#include <cstring>
#include <iostream>

Departamento::Departamento(){
    pDisciplPrim = nullptr;
    pDisciplAtual = nullptr;
}

Departamento::~Departamento(){
    pDisciplPrim = nullptr;
    pDisciplAtual = nullptr;
}

void Departamento::setNome(const char* n){
    std::strcpy(nome, n);
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
    if(pd != nullptr){
        if(pDisciplPrim == nullptr){
            pDisciplPrim = pd;
            pDisciplAtual = pd;
        }
        else{
            pDisciplAtual->pProx = pd;
            pd->pAnt = pDisciplAtual;
            pDisciplAtual = pd;
        }
    }
}

void Departamento::listaDisciplinas(){
    Disciplina* pAux = pDisciplPrim;

    while(pAux != nullptr){
        std::cout << "A disciplina " << pAux->getNome() << " pertence ao departamento " << getNome() << std::endl;
        pAux = pAux->pProx;
    }
}

void Departamento::listaDisciplinas2(){
    Disciplina* pAux = pDisciplAtual;

    while(pAux != nullptr){
        std::cout << "A disciplina " << pAux->getNome() << " pertence ao departamento " << getNome() << std::endl;
        pAux = pAux->pAnt;
    }
}