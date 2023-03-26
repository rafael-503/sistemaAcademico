#pragma once
#include "Departamento.h"

class ElDepartamento{
    private:
        Departamento* pDepartamento;
    public:
        ElDepartamento();
        ~ElDepartamento();
        ElDepartamento* pProx;
        ElDepartamento* pAnt;
        void setDepartamento(Departamento* pd);
        Departamento* getDepartamento();
        char* getNome();
};