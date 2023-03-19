#include "Professor.h"
#include <iostream>

Professor::Professor(int diaNA, int mesNA, int anoNA, const char* nome): Pessoa(diaNA, mesNA, anoNA, nome){
    pUnivFiliado = nullptr;
    pDptoFiliado = nullptr;
}

Professor::Professor(): Pessoa(){
    pUnivFiliado = nullptr;
    pDptoFiliado = nullptr;
}

Professor::~Professor(){
    pUnivFiliado = nullptr;
    pDptoFiliado = nullptr;
}

void Professor::setUnivFiliado(Universidade* pUniv){
    pUnivFiliado = pUniv;
}

void Professor::setDptoFiliado(Departamento* pDpto){
    pDptoFiliado = pDpto;
}

void Professor::ondeTrabalho(){
    if(pUnivFiliado)
        std::cout << nomeP << " trabalha para a " << pUnivFiliado->getNome() << std::endl;
}

void Professor::qualDepartamentoTrabalho(){
    if(pDptoFiliado)
        std::cout << nomeP << " trabalha para o departamento de " << pDptoFiliado->getNome() << std::endl;
}

