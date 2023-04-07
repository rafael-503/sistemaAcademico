#pragma once
#include "Elemento.h"
#include "Departamento.h"

class ListaDepartamentos{
    private:
        int cont_dep;
        int numero_dep;
        char nome[100];

        Elemento<Departamento>* pElDepartamentoPrim;
        Elemento<Departamento>* pElDepartamentoAtual;
    
    public:
        ListaDepartamentos(int nd=1000, const char* n="");
        ~ListaDepartamentos();

        void setNome(const char* n);
        void setDepartamento(Departamento* pd);
        void incluiDepartamento(Departamento* pd);
        void listaDepartamentos();
        void listaDepartamentosInv();
};