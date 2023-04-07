#include "ListaDisciplinas.h"
#include "Disciplina.h"
#include <cstring>
#include <iostream>

ListaDisciplinas::ListaDisciplinas(int nd, const char* n){
    numero_disc = nd;
    cont_disc = 0;
    strcpy(nome, n);
}

ListaDisciplinas::~ListaDisciplinas(){
    LTDisciplinas.limpar();
}

void ListaDisciplinas::setNome(const char* n){
    std::strcpy(nome, n);
}

char* ListaDisciplinas::getNome(){
    return nome;
}

void ListaDisciplinas::incluiDisciplina(Disciplina* pd){
    if((cont_disc < numero_disc) && (pd != nullptr)){
        LTDisciplinas.incluiInfo(pd, pd->getNome());
        cont_disc++;
    }
    else{
        if(pd == nullptr)
            std::cout << "Erro: ponteiro disciplina nulo." << std::endl;
        else
            std::cout << "Erro: numero de disciplinas excedido" << std::endl;
    }
}

void ListaDisciplinas::listaDisciplinas(){
    Elemento<Disciplina>* pElAux = nullptr;
    Disciplina* pDiAux = nullptr;
    pElAux = LTDisciplinas.getPrimeiro();

    while(pElAux != nullptr){
        pDiAux = pElAux->getInfo();
        std::cout << "Disciplina " << pDiAux->getNome() << " do departamento " << pDiAux->getDepartamento()->getNome() << std::endl;
        pElAux = pElAux->getProximo();
    }
}

void ListaDisciplinas::listaDisciplinasInv(){
    Elemento<Disciplina>* pElAux = nullptr;
    Disciplina* pDiAux = nullptr;
    pElAux = LTDisciplinas.getAtual();

    while(pElAux != nullptr){
        pDiAux = pElAux->getInfo();
        std::cout << "Disciplina " << pDiAux->getNome() << " do departamento " << pDiAux->getDepartamento()->getNome() << std::endl;
        pElAux = pElAux->getAnterior();
    }
}