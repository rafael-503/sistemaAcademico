#pragma once
#include "Departamento.h"

class Universidade{
    private:
        char nome[50];
        Departamento* pDpto[50];
    
    public:
        Universidade(const char* n="");
        ~Universidade();

        void setNome(const char* n);
        char* getNome();
        void setDepartamento(Departamento* pdep, int i);
        void imprimeDepartamentos();
};