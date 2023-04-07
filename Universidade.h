#pragma once
#include "ListaDepartamentos.h"
#include "Departamento.h"

class Universidade{
    private:
        char nome[100];
        ListaDepartamentos objDepartamentos;
        int i;
    
    public:
        Universidade();
        ~Universidade();

        void setNome(const char* n);
        char* getNome();

        void incluiDepartamento(Departamento* pdep);
        void listaDepartamentos();
        void listaDepartamentosInv();
};