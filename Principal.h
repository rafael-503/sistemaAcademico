#pragma once
#include "Lista.h"
#include "Professor.h"
#include "Universidade.h"
#include "Departamento.h"
#include "Disciplina.h"
#include "Aluno.h"
#include "Estagiario.h"

class Principal{
    private:
        int contIdDisc;
        int contIdDepart;
        int contIdAluno;

        Universidade UTFPR;
        Universidade Princeton;
        Universidade Cambdrige;

        Departamento DAINF;
        Departamento FisicaPrinceton;
        Departamento MatematicaCambdrige;

        Professor Einsten;
        Professor Newton;
        Professor Simao;

        Disciplina Computacao1;
        Disciplina Computacao2;
        Disciplina Algoritmos;
        Disciplina TecProg;

        Aluno AAA;
        Aluno BBB;
        Aluno CCC;
        Aluno DDD;

        Estagiario Fulano;
        
        Lista<Universidade> LUniversidades;
        Lista<Departamento> LDepartamentos;
        Lista<Disciplina> LDisciplinas;
        Lista<Aluno> LAlunos;
        Lista<Pessoa> LPessoas;

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
        void inicializaEstagiarios();

        void calcIdadeProf();
        void univOndeProfsTrabalham();
        void dptoOndeProfsTrabalham();
        void listaDiscDeptos();
        void listaAlunosDisc();
        void executar();

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