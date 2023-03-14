#pragma once
#include "Pessoa.h"
#include "Universidade.h"

class Principal{
    private:
        Pessoa Einsten;
        Pessoa Newton;

        Universidade UTFPR;

        int diaAtual;
        int mesAtual;
        int anoAtual;

    public:
        Principal();
        ~Principal();
        void executar();
};