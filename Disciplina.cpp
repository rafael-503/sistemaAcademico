#include "Disciplina.h"
#include <cstring>
#include <iostream>

Disciplina::Disciplina(int i, int na, const char* ac): ObjLAlunos(){
    id = i;
    std::strcpy(area_conhecimento, ac);
    pDptoAssociado = nullptr;
    cont_alunos = 0;
    numero_alunos = na;
}

Disciplina::~Disciplina(){
    pDptoAssociado = nullptr;
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
    ObjLAlunos.incluiInfo(pa);
}

void Disciplina::excluiAluno(Aluno* pa) {
    //ObjLAlunos.excluiInfo(pa);
}

void Disciplina::listaAlunos(){
    ObjLAlunos.listaInfos();
    Elemento<Aluno>* pAux = nullptr;
    pAux = ObjLAlunos.getPrimeiro();

    if(pAux != nullptr){
        Aluno* pAluno = nullptr;
        pAluno = pAux->getInfo();

        std::cout << "Aluno: " << pAluno->getNome() << " com RA: " << pAluno->getRA() << std::endl;
        pAux = pAux->getProximo();
    }
}

void Disciplina::listaAlunosInv(){
    //ObjLAlunos.listaAlunosInv();
}