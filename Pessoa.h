#pragma once
#include "Universidade.h"

class Pessoa{
    protected:
        int diaP;
        int mesP;
        int anoP;
        int idadeP;
        char nomeP[50];
        int id;

    public:
        Pessoa(int diaNA, int mesNA, int anoNA, const char* nome="");
        Pessoa(int i=-1);
        ~Pessoa();

        void Inicializa(int diaNA, int mesNA, int anoNA, const char* nome="");
        void calc_idade(int diaAT, int mesAT, int anoAT);
        void imprime_idade();
        void calc_idade_imprime(int diaAT, int mesAT, int anoAT);
        int getIdade();
        void setID(int i);
        int getID();
        void setNome(const char* n);
        char* getNome();
        virtual void informaRenda();
};