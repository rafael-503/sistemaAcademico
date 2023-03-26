#include "ListaAlunos.h"
#include <cstring>
#include <iostream>

ListaAlunos::ListaAlunos(int na, const char* n){
    cont_alunos = 0;
    numero_alunos = na;
    std::strcpy(nome, n);
    pElAlunoPrim = nullptr;
    pElAlunoAtual = nullptr;
}

ListaAlunos::~ListaAlunos(){
    ElAluno* pAux;
    pAux = pElAlunoPrim;
    
    while(pElAlunoPrim != nullptr){
        pElAlunoPrim = pElAlunoPrim->pProx;
        delete pAux;
        pAux = pElAlunoPrim;
    }
    
    pElAlunoAtual = nullptr;
    pElAlunoPrim = nullptr;
}

void ListaAlunos::incluiAluno(Aluno* pa){
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

void ListaAlunos::excluiAluno(Aluno* pa) {
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

void ListaAlunos::listaAlunos(){
    ElAluno* pAux = pElAlunoPrim;
    while(pAux != nullptr){
        std::cout << "O aluno " << pAux->getAluno()->getNome() << " está matriculado na disciplina" << nome << std::endl;
        pAux = pAux->pProx;
    }
}

void ListaAlunos::listaAlunosInv(){
    ElAluno* pAux = pElAlunoAtual;
    while(pAux != nullptr){
        std::cout << pAux->getAluno()->getNome() << std::endl;
        pAux = pAux->pAnt;
    }
}