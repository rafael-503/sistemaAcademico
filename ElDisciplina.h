#pragma once
#include "Disciplina.h"

class ElDisciplina{
    private:
        Disciplina* pDisciplina;
    public:
        ElDisciplina();
        ~ElDisciplina();
        ElDisciplina* pProx;
        ElDisciplina* pAnt;
        void setDisciplina(Disciplina* pd);
        Disciplina* getDisciplina();
        char* getNome();
};