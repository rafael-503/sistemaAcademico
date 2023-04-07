#include "ListaPessoas.h"
#include <iostream>

ListaPessoas::ListaPessoas(){}

ListaPessoas::~ListaPessoas(){}

void ListaPessoas::incluiPessoa(Pessoa* pp){
    LTPessoas.incluiInfo(pp, pp->getNome());
}

void ListaPessoas::listaPessoas(){
    Elemento<Pessoa>* pElAux = nullptr;
    Pessoa* pPeAux = nullptr;
    pElAux = LTPessoas.getPrimeiro();

    while(pElAux != nullptr){
        pPeAux = pElAux->getInfo();
        std::cout << "Pessoa " << pPeAux->getNome()<< std::endl;
        pElAux = pElAux->getProximo();
    }
}

void ListaPessoas::listaPessoasInv(){
    Elemento<Pessoa>* pElAux = nullptr;
    Pessoa* pPeAux = nullptr;
    pElAux = LTPessoas.getAtual();

    while(pElAux != nullptr){
        pPeAux = pElAux->getInfo();
        std::cout << "Pessoa " << pPeAux->getNome()<< std::endl;
        pElAux = pElAux->getAnterior();
    }
}

void ListaPessoas::listaRenda(){
    Elemento<Pessoa>* ponteiroElPessoa = nullptr;
    Pessoa* ponteiroPessoa = nullptr;
    ponteiroElPessoa = LTPessoas.getPrimeiro();

    while(ponteiroElPessoa != nullptr){
        ponteiroPessoa = ponteiroElPessoa->getInfo();
        ponteiroPessoa->informaRenda();
        ponteiroElPessoa = ponteiroElPessoa->getProximo();
    }
}