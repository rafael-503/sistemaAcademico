#pragma once
#include "Lista.h"
#include "Elemento.h"
#include "Aluno.h"

class ListaAlunos{
    private:
        Lista<Aluno> LTAlunos;

    public:
        ListaAlunos();
        ~ListaAlunos();

        void limpaLista();
        void incluiAluno(Aluno* pa);
        void excluiAluno(Aluno* pa);
        void listaAlunos();
        void listaAlunosInv();
        void gravarAlunos();
        void recuperarAlunos();

};