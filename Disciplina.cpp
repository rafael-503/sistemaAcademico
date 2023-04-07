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
    if(pa != nullptr){
        if(cont_alunos < numero_alunos){
            ObjLAlunos.incluiAluno(pa);
            cont_alunos++;
        }
        else
            std::cout << "Numero maximo de alunos atingido. Turma com " << numero_alunos << std::endl;
    }
    else
        std::cout << "Ponteiro aluno nulo." << std::endl;
}

void Disciplina::excluiAluno(Aluno* pa) {
    //ObjLAlunos.excluiInfo(pa);
}

void Disciplina::listaAlunos(){
    std::cout << "Alunos matriculados na disciplina " << nome << std::endl;
    ObjLAlunos.listaAlunos();
}

void Disciplina::listaAlunosInv(){
    std::cout << "Alunos matriculados na disciplina " << nome << std::endl;
    ObjLAlunos.listaAlunosInv();
}