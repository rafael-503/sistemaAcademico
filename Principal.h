#pragma once
#include "Professor.h"
#include "Universidade.h"
#include "Aluno.h"
#include "Departamento.h"
#include "Disciplina.h"

class Principal{
    private:
        Professor Einsten;
        Professor Newton;
        Professor Simao;

        Universidade UTFPR;
        Universidade Princeton;
        Universidade Cambdrige;

        Departamento DAINF;
        Departamento FisicaPrinceton;
        Departamento MatematicaCambdrige;

        Disciplina Computacao1;
        Disciplina Computacao2;
        Disciplina Algoritmos;
        Disciplina TecProg;

        Aluno AAA;
        Aluno BBB;
        Aluno CCC;
        Aluno DDD;

        int diaAtual;
        int mesAtual;
        int anoAtual;

    public:
        Principal();
        ~Principal();

        void inicializa();
        void inicializaUniversidades();
        void inicializaDepartamentos();
        void inicializaProfessores();
        void inicializaDisciplinas();
        void inicializaAlunos();

        void calcIdadeProf();
        void univOndeProfsTrabalham();
        void dptoOndeProfsTrabalham();
        void ListaDiscDeptos();
        void ListaAlunosDisc();
        void executar();
};