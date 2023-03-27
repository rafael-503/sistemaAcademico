#include "ListaDisciplinas.h"
#include <cstring>
#include <iostream>

ListaDisciplinas::ListaDisciplinas(int nd, const char* n){
    numero_disc = nd;
    cont_disc = 0;
    strcpy(nome, n);
    pElDisciplinaPrim = nullptr;
    pElDisciplinaAtual = nullptr;
}

ListaDisciplinas::~ListaDisciplinas(){
    ElDisciplina* pAux;
    pAux = pElDisciplinaPrim;
    
    while(pElDisciplinaPrim != nullptr){
        pElDisciplinaPrim = pElDisciplinaPrim->pProx;
        delete pAux;
        pAux = pElDisciplinaPrim;
    }
    
    pElDisciplinaAtual = nullptr;
    pElDisciplinaPrim = nullptr;
}

void ListaDisciplinas::setNome(const char* n){
    std::strcpy(nome, n);
}

void ListaDisciplinas::incluiDisciplina(Disciplina* pd){
    if((cont_disc < numero_disc) && (pd != nullptr)){
        ElDisciplina* pAux = nullptr;
        pAux = new ElDisciplina();

        if(pElDisciplinaPrim == nullptr){
            pElDisciplinaPrim = pAux;
            pElDisciplinaAtual = pAux;
        }
        else{
            pElDisciplinaAtual->pProx = pAux;
            pAux->pAnt = pElDisciplinaAtual;
            pElDisciplinaAtual = pAux;
        }
        cont_disc++;
    }
    else{
        std::cout << "Erro: numero de disciplinas excedido ou ponteiro nulo" << std::endl;
    }

}

void ListaDisciplinas::listaDisciplinas(){
    ElDisciplina* pAux = pElDisciplinaPrim;
    while(pAux != nullptr){
        std::cout << "Disciplina: " << pAux->getNome() << " do departamento: " << nome << std::endl;
        pAux = pAux->pProx;
    }
}

void ListaDisciplinas::listaDisciplinasInv(){
    ElDisciplina* pAux = pElDisciplinaAtual;
    while(pAux != nullptr){
        std::cout << "Disciplina: " << pAux->getNome() << " do departamento: " << nome << std::endl;
        pAux = pAux->pAnt;
    }
}