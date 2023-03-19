#pragma once
#include "Professor.h"
#include "Universidade.h"
#include "Departamento.h"

class Principal{
    private:
        Professor Einsten;
        Professor Newton;

        Universidade UTFPR;
        Universidade Princeton;
        Universidade Cambdrige;

        Departamento DAINF;
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