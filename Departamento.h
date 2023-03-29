#pragma once
class Universidade;
class Disciplina;
class ListaDisciplinas;

class Departamento{
    private:
        char nome[100];
        Universidade* pUniv;
        Disciplina* pDisciplPrim;
        Disciplina* pDisciplAtual;
        ListaDisciplinas* objDisciplinas;
        int id;

    public:
        Departamento(int i=-1);
        ~Departamento();

        void setNome(const char* n);
        char* getNome();
        void setUniversidade(Universidade* pu);
        Universidade* getUniversidade();

        void incluiDisciplina(Disciplina* pd);
        void listaDisciplinas();
        void listaDisciplinasInv();
};