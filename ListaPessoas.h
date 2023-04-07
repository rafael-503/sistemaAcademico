#pragma once
#include "Lista.h"
#include "Elemento.h"
#include "Pessoa.h"

class ListaPessoas{
    private:
        Lista<Pessoa> LTPessoas;

    public:
        ListaPessoas();
        virtual ~ListaPessoas();
        void incluiPessoa(Pessoa* pp);
        void listaPessoas();
        void listaPessoasInv();
        void listaRenda();
};