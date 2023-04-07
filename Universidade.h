#pragma once
#include "ListaDepartamentos.h"
#include "Departamento.h"

class Universidade{
    private:
        char nome[100];
        ListaDepartamentos objDepartamentos;
        int id;
    
    public:
        Universidade(int i);
        ~Universidade();

        void setNome(const char* n);
        char* getNome();
        int getID();

        void incluiDepartamento(Departamento* pdep);
        void listaDepartamentos();
        void listaDepartamentosInv();
};