#pragma once
class Universidade;
class Disciplina;

class Departamento{
    private:
        char nome[100];
        Universidade* pUniv;
        Disciplina* pDisciplPrim;
        Disciplina* pDisciplAtual;

    public:
        Departamento();
        ~Departamento();

        void setNome(const char* n);
        char* getNome();
        void setUniversidade(Universidade* pu);
        Universidade* getUniversidade();

        void incluiDisciplina(Disciplina* pd);
        void listaDisciplinas();
        void listaDisciplinas2();
};