#pragma once
class Universidade;
class Disciplina;
class ListaDisciplinas;

class Departamento{
    private:
        int id;
        char nome[100];
        Universidade* pUniv;
        ListaDisciplinas* objDisciplinas;

    public:
        Departamento(int i=-1);
        ~Departamento();

        int getId();

        void setNome(const char* n);
        char* getNome();
        void setUniversidade(Universidade* pu);
        Universidade* getUniversidade();

        void incluiDisciplina(Disciplina* pd);
        void listaDisciplinas();
        void listaDisciplinasInv();
};