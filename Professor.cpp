#include "Professor.h"
#include <iostream>

Professor::Professor(int diaNA, int mesNA, int anoNA, const char* nome): Pessoa(diaNA, mesNA, anoNA, nome){
    inicializa();
}

Professor::Professor(): Pessoa(){
    inicializa();
}

Professor::~Professor(){
    pUnivFiliado = nullptr;
    pDptoFiliado = nullptr;
}

void Professor::inicializa(){
    pUnivFiliado = nullptr;
    pDptoFiliado = nullptr;
    salario = 0.0;
    bolsa_projeto = 0.0;
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

void Professor::setSalario(float s){
    salario = s;
}

float Professor::getSalario(){
    return salario;
}

void Professor::setBolsaProjeto(float b){
    bolsa_projeto = b;
}

float Professor::getBolsaProjeto(){
    return bolsa_projeto;
}

void Professor::informaRenda(){
    std::cout << nomeP << " tem uma renda de " << salario + bolsa_projeto << std::endl;
}
