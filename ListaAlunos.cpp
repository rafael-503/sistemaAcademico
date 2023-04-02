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

void ListaAlunos::setNome(const char* n){
    std::strcpy(nome, n);
}

void ListaAlunos::listaAlunos(){
    ElAluno* pAux = pElAlunoPrim;
    while(pAux != nullptr){
        std::cout << "O aluno " << pAux->getNome() << " está matriculado na disciplina " << nome << std::endl;
        pAux = pAux->pProx;
    }
}

void ListaAlunos::listaAlunosInv(){
    ElAluno* pAux = pElAlunoAtual;
    while(pAux != nullptr){
        std::cout << "O aluno " << pAux->getNome() << " está matriculado na disciplina " << nome << std::endl;
        pAux = pAux->pAnt;
    }
}

void ListaAlunos::limpaLista(){
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


void ListaAlunos::gravarAlunos(){
    std::ofstream GravadorAlunos("alunos.dat", std::ios::out);

    if(!GravadorAlunos){
        std::cerr << "Erro ao abrir o arquivo" << std::endl;
        getchar();
        return;
    }

    ElAluno* pAuxElAluno = nullptr;
    Aluno* pAuxAluno = nullptr;
    pAuxElAluno = pElAlunoPrim;

    while(pAuxElAluno != nullptr){
        pAuxAluno = pAuxElAluno->getAluno();

        GravadorAlunos << pAuxAluno->getID() << ' '
                        << pAuxAluno->getRA() << ' '
                        << pAuxAluno->getNome() << std::endl;
        pAuxElAluno = pAuxElAluno->pProx;
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
