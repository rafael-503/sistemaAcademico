#include "Disciplina.h"
#include <cstring>
#include <iostream>

Disciplina::Disciplina(int na, const char* ac){
    id = -1;
    std::strcpy(area_conhecimento, ac);
    pDptoAssociado = nullptr;
    pProx = nullptr;
    pAnt = nullptr;
    pAlunoPrim = nullptr;
    pAlunoAtual = nullptr;
    cont_alunos = 0;
    numero_alunos = na;
    std::strcpy(area_conhecimento, ac);
}

Disciplina::~Disciplina(){
    id = -1;
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
    if((cont_alunos < numero_alunos) && (pa != nullptr)){
        if(pAlunoPrim == nullptr){
            pAlunoPrim = pa;
            pAlunoAtual = pa;
        }
        else{
            pAlunoAtual->pProx = pa;
            pa->pAnt = pAlunoAtual;
            pAlunoAtual = pa;
        }
        cont_alunos++;
    }
    else{
        std::cout << "Aluno nao incluido, turma lotada" << std::endl;
    }
}

void Disciplina::listaAlunos(){
    Aluno* pAux = pAlunoPrim;

    while(pAux != nullptr){
        std::cout << "O aluno " << pAux->getNome() << " pertence a disciplina " << getNome() << std::endl;
        pAux = pAux->pProx;
    }
}

void Disciplina::listaAlunos2(){
    Aluno* pAux = pAlunoAtual;

    while(pAux != nullptr){
        std::cout << "O aluno " << pAux->getNome() << " pertence a disciplina " << getNome() << std::endl;
        pAux = pAux->pAnt;
    }
}