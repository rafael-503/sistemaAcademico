#include "Disciplina.h"
#include <cstring>
#include <iostream>

Disciplina::Disciplina(int na, const char* ac): ObjAlunos(na, ac){
    id = -1;
    std::strcpy(area_conhecimento, ac);
    pDptoAssociado = nullptr;
    pProx = nullptr;
    pAnt = nullptr;
    cont_alunos = 0;
    numero_alunos = na;
}

Disciplina::~Disciplina(){
    pDptoAssociado = nullptr;
    pProx = nullptr;
    pAnt = nullptr;
}

void Disciplina::setId(int i){
    id = i;
}

int Disciplina::getId(){
    return id;
}

void Disciplina::setNome(const char* n){
    std::strcpy(nome, n);
}

char* Disciplina::getNome(){
    return nome;
}

void Disciplina::setDepartamento(Departamento* pdpto){
    pDptoAssociado = pdpto;
    pdpto->incluiDisciplina(this);
}

Departamento* Disciplina::getDepartamento(){
    return pDptoAssociado;
}

void Disciplina::incluiAluno(Aluno* pa){
    ObjAlunos.incluiAluno(pa);
}

void Disciplina::excluiAluno(Aluno* pa) {
    ObjAlunos.excluiAluno(pa);
}

void Disciplina::listaAlunos(){
    ObjAlunos.listaAlunos();
}

void Disciplina::listaAlunosInv(){
    ObjAlunos.listaAlunosInv();
}