#pragma once
#include "Pessoa.h"

class Aluno: public Pessoa{
    private:
        int RA;

    public:
        Aluno(int diaNA, int mesNA, int anoNA, const char* nome="");
        Aluno();
        ~Aluno();

        Aluno* pProx;
        Aluno* pAnt;

        void setRA(int ra);
        int getRA();
};