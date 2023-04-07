#pragma once
#include "Elemento.h"
#include "Disciplina.h"

class ListaDisciplinas{
    private:
        int cont_disc;
        int numero_disc;
        char nome[100];

        Elemento<Disciplina>* pElDisciplinaPrim;
        Elemento<Disciplina>* pElDisciplinaAtual;

    public:
        ListaDisciplinas(int nd=1000, const char* n="");
        ~ListaDisciplinas();

        void setNome(const char* n);
        char* getNome();

        void incluiDisciplina(Disciplina* pd);
        void listaDisciplinas();
        void listaDisciplinasInv();
};