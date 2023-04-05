#include "ListaAlunos.h"
#include <cstring>
#include <iostream>
#include <fstream>

ListaAlunos::ListaAlunos(int na, const char* n){
    cont_alunos = 0;
    numero_alunos = na;
    std::strcpy(nome, n);
    
    pElAlunoPrim = nullptr;
    pElAlunoAtual = nullptr;
}

ListaAlunos::~ListaAlunos(){
    limpaLista();
}

void ListaAlunos::incluiAluno(Aluno* pa){
    if((cont_alunos < numero_alunos) && (pa != nullptr)){
        Elemento<Aluno> *pAux = nullptr;
        pAux = new Elemento<Aluno>();
        pAux->setInfo(pa);
        
        if(pElAlunoPrim == nullptr){
            pElAlunoPrim = pAux;
            pElAlunoAtual = pAux;
        }
        else{
            pElAlunoAtual->setProximo(pAux);
            pAux->setAnterior(pElAlunoAtual);
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
    Elemento<Aluno> *pAux = pElAlunoPrim;

    while (pAux != nullptr) {
        if (pAux->getInfo() == pa) {
            if (pAux == pElAlunoPrim) {
                
                pElAlunoPrim = pAux->getProximo();
            }
            if (pAux == pElAlunoAtual) {
                pElAlunoAtual = pAux->getAnterior();
            }
            if (pAux->getAnterior() != nullptr) {
                pAux->setAnterior(pAux->getProximo());
            }
            if (pAux->getProximo() != nullptr) {
                pAux->setAnterior(pAux->getAnterior());
            }
            cont_alunos--;
            break;
        }
        pAux = pAux->getProximo();
    }
}

void ListaAlunos::setNome(const char* n){
    std::strcpy(nome, n);
}

void ListaAlunos::listaAlunos(){
    Aluno* pAuxAluno = nullptr;
    Elemento<Aluno> *pAuxEl = nullptr;
    pAuxEl = pElAlunoPrim;

    while(pAuxEl != nullptr){
        pAuxAluno = pAuxEl->getInfo();
        std::cout << "O aluno " << pAuxAluno->getNome() << " está matriculado na disciplina " << nome << std::endl;
        pAuxEl = pAuxEl->getProximo();
    }
}

void ListaAlunos::listaAlunosInv(){
    Elemento<Aluno> *pAux = pElAlunoAtual;
    while(pAux != nullptr){
        std::cout << "O aluno " << pAux->getNome() << " está matriculado na disciplina " << nome << std::endl;
        pAux = pAux->getAnterior();
    }
}

void ListaAlunos::limpaLista(){
    Elemento<Aluno> *pAux;
    pAux = pElAlunoPrim;
    
    while(pElAlunoPrim != nullptr){
        pElAlunoPrim = pElAlunoPrim->getProximo();
        delete pAux;
        pAux = pElAlunoPrim;
    }

    pElAlunoAtual = nullptr;
    pElAlunoPrim = nullptr;
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
    pAuxElAluno = pElAlunoPrim;

    while(pAuxElAluno != nullptr){
        pAuxAluno = pAuxElAluno->getInfo();

        GravadorAlunos << pAuxAluno->getID() << ' '
                        << pAuxAluno->getRA() << ' '
                        << pAuxAluno->getNome() << std::endl;
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
