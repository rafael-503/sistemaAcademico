#include "Disciplina.h"
#include <cstring>
#include <iostream>

Disciplina::Disciplina(int na, const char* ac){
    id = -1;
    std::strcpy(area_conhecimento, ac);
    pDptoAssociado = nullptr;
    pProx = nullptr;
    pAnt = nullptr;
    pElAlunoPrim = nullptr;
    pElAlunoAtual = nullptr;
    cont_alunos = 0;
    numero_alunos = na;
    std::strcpy(area_conhecimento, ac);
}

Disciplina::~Disciplina(){
    ElAluno* pAux;
    pAux = pElAlunoPrim;
    
    while(pElAlunoPrim != nullptr){
        pElAlunoPrim = pElAlunoPrim->pProx;
        delete pAux;
        pAux = pElAlunoPrim;
    }

    pDptoAssociado = nullptr;
    pElAlunoAtual = nullptr;
    pElAlunoPrim = nullptr;
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
        ElAluno* pAux = nullptr;
        pAux = new ElAluno();
        pAux->setAluno(pa);

        if(pElAlunoPrim == nullptr){
            pElAlunoPrim = pAux;
            pElAlunoAtual = pAux;
        }
        else{
            pElAlunoAtual->pProx = pAux;
            pAux->pAnt = pElAlunoAtual;
            pElAlunoAtual = pAux;
        }
        cont_alunos++;
    }
    else{
        if(pa != nullptr)
            std::cout << "Aluno nao incluido, turma lotada" << std::endl;
        else
            std::cout << "Ponteiro nulo" << std::endl;
    }
}

void Disciplina::excluiAluno(Aluno* pa) {
    ElAluno* pAux = pElAlunoPrim;

    while (pAux != nullptr) {
        if (pAux->getAluno() == pa) {
            if (pAux == pElAlunoPrim) {
                pElAlunoPrim = pAux->pProx;
            }
            if (pAux == pElAlunoAtual) {
                pElAlunoAtual = pAux->pAnt;
            }
            if (pAux->pAnt != nullptr) {
                pAux->pAnt->pProx = pAux->pProx;
            }
            if (pAux->pProx != nullptr) {
                pAux->pProx->pAnt = pAux->pAnt;
            }
            cont_alunos--;
            break;
        }
        pAux = pAux->pProx;
    }
}

void Disciplina::listaAlunos(){
    ElAluno* pAux = pElAlunoPrim;

    while(pAux != nullptr){
        std::cout << "O aluno " << pAux->getNome() << " pertence a disciplina " << getNome() << std::endl;
        pAux = pAux->pProx;
    }
}

void Disciplina::listaAlunosInv(){
    ElAluno* pAux = pElAlunoAtual;

    while(pAux != nullptr){
        std::cout << "O aluno " << pAux->getNome() << " pertence a disciplina " << getNome() << std::endl;
        pAux = pAux->pAnt;
    }
}