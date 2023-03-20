#pragma once
#include "Departamento.h"
#include <list>

class Universidade{
    private:
        char nome[50];
        std::list <Departamento*> LpDptos;
        int i;
    
    public:
        Universidade();
        ~Universidade();

        void setNome(const char* n);
        char* getNome();
        void setDepartamento(Departamento* pdep);
        void imprimeDepartamentos();
};