#pragma once
#include "Pessoa.h"
#include "Universidade.h"
#include "Departamento.h"

class Principal{
    private:
        Pessoa Einsten;
        Pessoa Newton;

        Universidade UTFPR;
        Universidade Princeton;
        Universidade Cambdrige;

        Departamento FisicaPrinceton;
        Departamento MatematicaCambdrige;

        int diaAtual;
        int mesAtual;
        int anoAtual;

    public:
        Principal();
        ~Principal();
        void executar();
};