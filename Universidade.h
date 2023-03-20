#pragma once
#include "Departamento.h"
#include <vector>

class Universidade{
    private:
        char nome[50];
        std::vector <Departamento*> LpDptos;
        int i;
    
    public:
        Universidade(const char* n="");
        ~Universidade();

        void setNome(const char* n);
        char* getNome();
        void setDepartamento(Departamento* pdep);
        void imprimeDepartamentos();
};