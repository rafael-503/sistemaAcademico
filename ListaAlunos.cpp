#include "ListaAlunos.h"
#include "Aluno.h"
#include <cstring>
#include <iostream>
#include <fstream>

ListaAlunos::ListaAlunos(){}

ListaAlunos::~ListaAlunos(){
    limpaLista();
}

void ListaAlunos::limpaLista(){
    LTAlunos.limpar();
}

void ListaAlunos::incluiAluno(Aluno* pa){
    if(pa != nullptr)
        LTAlunos.incluiInfo(pa, pa->getNome());
    else
        std::cout << "Erro: Aluno nao incluido, ponteiro aluno nulo." << std::endl;
}

void ListaAlunos::excluiAluno(Aluno* pa) {
    //LTAlunos.excluiInfo(pa);
}

void ListaAlunos::listaAlunos(){
    Elemento<Aluno>* pElAux = nullptr;
    Aluno* pAlAux = nullptr;
    pElAux = LTAlunos.getPrimeiro();

    while(pElAux != nullptr){
        pAlAux = pElAux->getInfo();
        std::cout << "Aluno " << pAlAux->getNome() << " com RA " << pAlAux->getRA() << std::endl;
        pElAux = pElAux->getProximo();
    }
}

void ListaAlunos::listaAlunosInv(){
    Elemento<Aluno>* pElAux = nullptr;
    Aluno* pAlAux = nullptr;
    pElAux = LTAlunos.getAtual();

    while(pElAux != nullptr){
        pAlAux = pElAux->getInfo();
        std::cout << "Aluno " << pAlAux->getNome() << " com RA " << pAlAux->getRA() << std::endl;
        pElAux = pElAux->getAnterior();
    }
}

void ListaAlunos::gravarAlunos(){
    std::ofstream GravadorAlunos("alunos.dat", std::ios::out);

    if(!GravadorAlunos){
        std::cerr << "Erro ao abrir o arquivo" << std::endl;
        getchar();
        return;
    }

    Elemento<Aluno> *pAuxElAluno = nullptr;
    Aluno* pAuxAluno = nullptr;
    pAuxElAluno = LTAlunos.getPrimeiro();

    while(pAuxElAluno != nullptr){
        pAuxAluno = pAuxElAluno->getInfo();

        GravadorAlunos << pAuxAluno->getID() << ' '
                        << pAuxAluno->getRA() << ' '
                        << pAuxAluno->getNome() 
                        << std::endl;
        pAuxElAluno = pAuxElAluno->getProximo();
    }
    GravadorAlunos.close();

    std::cout << "Alunos gravados com sucesso" << std::endl;
}

void ListaAlunos::recuperarAlunos(){
    std::ifstream RecuperadorAlunos("alunos.dat", std::ios::in);

    if(!RecuperadorAlunos){
        std::cerr << "Erro ao abrir o arquivo" << std::endl;
        getchar();
        return;
    }

    limpaLista();
    Aluno* pAuxAluno = nullptr;
    int id, RA;
    char nome[100];

    while(RecuperadorAlunos >> id >> RA >> nome){
        if(strcmp(nome, "") != 0){
            pAuxAluno = new Aluno(-1);
            pAuxAluno->setID(id);
            pAuxAluno->setRA(RA);
            pAuxAluno->setNome(nome);

            incluiAluno(pAuxAluno);
        }
    }
    RecuperadorAlunos.close();

    std::cout << "Alunos recuperados com sucesso" << std::endl;
}