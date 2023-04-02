#pragma once
#include "ElAluno.h"
#include "Aluno.h"

class ListaAlunos{
    private:
        int cont_alunos;
        int numero_alunos;
        char nome[100];

        ElAluno* pElAlunoPrim;
        ElAluno* pElAlunoAtual;

    public:
        ListaAlunos(int na=45, const char* n="");
        ~ListaAlunos();

        void incluiAluno(Aluno* pa);
        void excluiAluno(Aluno* pa);
        void setNome(const char* n);
        void listaAlunos();
        void listaAlunosInv();
        void limpaLista();
        void gravarAlunos();
        void recuperarAlunos();

};