#pragma once
#include "Pessoa.h"
#include "Universidade.h"

class Professor: public Pessoa{
    private:
        Universidade* pUnivFiliado;
        Departamento* pDptoFiliado;
        float salario;
        float bolsa_projeto;
        
    public:
        Professor(int diaNA, int mesNA, int anoNA, const char* nome="");
        Professor();
        ~Professor();

        void inicializa();
        void setUnivFiliado(Universidade* pUniv);
        void setDptoFiliado(Departamento* pDpto);
        void ondeTrabalho();
        void qualDepartamentoTrabalho();

        void setSalario(float s);
        float getSalario();
        void setBolsaProjeto(float b);
        float getBolsaProjeto();
        void informaRenda();
};