#pragma once
#include "Pessoa.h"
#include "Universidade.h"

class Professor: public Pessoa{
    private:
        Universidade* pUnivFiliado;
        Departamento* pDptoFiliado;
        
    public:
        Professor(int diaNA, int mesNA, int anoNA, const char* nome="");
        Professor();
        ~Professor();

        void setUnivFiliado(Universidade* pUniv);
        void setDptoFiliado(Departamento* pDpto);
        void ondeTrabalho();
        void qualDepartamentoTrabalho();
};