#pragma once
#include "Professor.h"
#include "Universidade.h"
#include "Departamento.h"
#include "Disciplina.h"
#include "Aluno.h"
#include "Estagiario.h"
#include "ListaUniversidades.h"
#include "ListaDisciplinas.h"
#include "ListaPessoas.h"

class Principal{
    private:
        int contIdAluno;
        int contIdDepart;
        int contIdDisc;
        int contIdUniv;

        Universidade Cambdrige;
        Universidade Princeton;
        Universidade UTFPR;

        Departamento DAINF;
        Departamento FisicaPrinceton;
        Departamento MatematicaCambdrige;

        Professor Einsten;
        Professor Newton;
        Professor Simao;

        Disciplina Algoritmos;
        Disciplina Computacao1;
        Disciplina Computacao2;
        Disciplina TecProg;

        Aluno AAA;
        Aluno BBB;
        Aluno CCC;
        Aluno DDD;

        Estagiario Fulano;
        
        ListaUniversidades LUniversidades;
        ListaDepartamentos LDepartamentos;
        ListaDisciplinas LDisciplinas;
        ListaAlunos LAlunos;
        ListaPessoas LPessoas;

        int diaAtual;
        int mesAtual;
        int anoAtual;

    public:
        Principal();
        ~Principal();

        void inicializa();
        void inicializaAlunos();
        void inicializaDepartamentos();
        void inicializaDisciplinas();
        void inicializaEstagiarios();
        void inicializaProfessores();
        void inicializaUniversidades();

        void executar();

        void calcIdadeProf();
        void univOndeProfsTrabalham();
        void dptoOndeProfsTrabalham();

        void listaAlunosDisc();
        void listaDiscDeptos();
        void listaRendaPessoas();
        
        void cadDisciplina();
        void cadDepartamento();
        void cadUniversidade();
        void cadAluno();

        void gravarTudo();
        void gravarUniversidades();
        void gravarDepartamentos();
        void gravarDisciplinas();
        void gravarAlunos();
        void gravarProfessores();

        void recuperarTudo();
        void recuperarUniversidades();
        void recuperarDepartamentos();
        void recuperarDisciplinas();
        void recuperarAlunos();
        void recuperarProfessores();

        void menu();
        void menuCad();
        void menuExe();
        void menuGravar();
        void menuRecuperar();
};