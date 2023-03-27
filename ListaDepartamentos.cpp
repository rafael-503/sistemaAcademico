#include "ListaDepartamentos.h"
#include <cstring>
#include <iostream>

ListaDepartamentos::ListaDepartamentos(int nd, const char* n){
    numero_dep = nd;
    cont_dep = 0;
    pElDepartamentoPrim = nullptr;
    pElDepartamentoAtual = nullptr;
    strcpy(nome, n);
}

ListaDepartamentos::~ListaDepartamentos(){
    ElDepartamento* pAux;
    pAux = pElDepartamentoPrim;
    
    while(pElDepartamentoPrim != nullptr){
        pElDepartamentoPrim = pElDepartamentoPrim->pProx;
        delete pAux;
        pAux = pElDepartamentoPrim;
    }
    
    pElDepartamentoAtual = nullptr;
    pElDepartamentoPrim = nullptr;
}

void ListaDepartamentos::setNome(const char* n){
    std::strcpy(nome, n);
}

void ListaDepartamentos::setDepartamento(Departamento* pd){
    if((cont_dep < numero_dep) && (pd != nullptr)){
        ElDepartamento* pAux = nullptr;
        pAux = new ElDepartamento();
        pAux->setDepartamento(pd);

        if(pElDepartamentoPrim == nullptr){
            pElDepartamentoPrim = pAux;
            pElDepartamentoAtual = pAux;
        }
        else{
            pElDepartamentoAtual->pProx = pAux;
            pAux->pAnt = pElDepartamentoAtual;
            pElDepartamentoAtual = pAux;
        }
        cont_dep++;
    }
    else{
        std::cout << "Erro: numero de departamentos excedido ou ponteiro nulo" << std::endl;
    }
}

void ListaDepartamentos::incluiDepartamento(Departamento* pd){
    if((cont_dep < numero_dep) && (pd !=nullptr)){
        ElDepartamento* pAux = nullptr;
        pAux = new ElDepartamento();
        pAux->setDepartamento(pd);
        pAux->pProx = nullptr;
        pAux->pAnt = nullptr;

        if(pElDepartamentoPrim == nullptr){
            pElDepartamentoPrim = pAux;
            pElDepartamentoAtual = pAux;
        }
        else{
            pElDepartamentoAtual->pProx = pAux;
            pAux->pAnt = pElDepartamentoAtual;
            pElDepartamentoAtual = pAux;
        }
        cont_dep++;
    }
    else{
        std::cout << "Erro: numero de departamentos excedido ou ponteiro nulo" << std::endl;
    }
}

void ListaDepartamentos::listaDepartamentos(){
    ElDepartamento* pAux = pElDepartamentoPrim;
    while(pAux != nullptr){
        std::cout << "Departamento: " << pAux->getDepartamento()->getNome() << std::endl;
        pAux = pAux->pProx;
    }
}

void ListaDepartamentos::listaDepartamentosInv(){
    ElDepartamento* pAux = pElDepartamentoAtual;
    while(pAux != nullptr){
        std::cout << "Departamento: " << pAux->getDepartamento()->getNome() << std::endl;
        pAux = pAux->pAnt;
    }
}
