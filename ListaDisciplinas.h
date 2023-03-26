#pragma once
#include "ElDisciplina.h"
#include "Disciplina.h"

class ListaDisciplinas{
    private:
        int cont_disc;
        int numero_disc;
        char nome[100];

        ElDisciplina* pElDisciplinaPrim;
        ElDisciplina* pElDisciplinaAtual;

    public:
        ListaDisciplinas(int nd=1000, const char* n="");
        ~ListaDisciplinas();

        void setNome(const char* n);
        void incluiDisciplina(Disciplina* pd);

        void listaDisciplinas();
        void listaDisciplinasInv();
};