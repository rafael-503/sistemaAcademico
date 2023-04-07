#pragma once
#include "Lista.h"
#include "Elemento.h"
#include "Departamento.h"

class ListaDepartamentos{
    private:
        int cont_dep;
        int numero_dep;
        char nome[100];
        Lista<Departamento> LTDepartamento;
    
    public:
        ListaDepartamentos(int nd=1000, const char* n="");
        virtual ~ListaDepartamentos();

        void setNome(const char* n);
        void incluiDepartamento(Departamento* pd);
        void listaDepartamentos();
        void listaDepartamentosInv();
        Departamento* localizar(const char* n);
};