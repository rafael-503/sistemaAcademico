#pragma once
#include "Lista.h"
#include "Departamento.h"
#include "Aluno.h"

class Disciplina{
    private:
        int id;
        char nome[100];
        char area_conhecimento[100];
        int numero_alunos;
        int cont_alunos;
        Departamento* pDptoAssociado;
        Lista<Aluno> ObjLAlunos;
        
    public:
        Disciplina(int i, int na=45, const char* ac="");
        ~Disciplina();

        void setId(int i);
        int getId();

        void setNome(const char* n);
        char* getNome();

        void setDepartamento(Departamento* pdpto);
        Departamento* getDepartamento();

        void incluiAluno(Aluno* pa);
        void excluiAluno(Aluno* pa);
        void listaAlunos();
        void listaAlunosInv();
};