#include "Pessoa.h"
#include <iostream>
#include <cstring>

Pessoa::Pessoa(int i){
    Inicializa(0, 0, 0);
    id = i;
}

Pessoa::~Pessoa(){}

Pessoa::Pessoa(int diaNA, int mesNA, int anoNA, const char* nome){
    Inicializa(diaNA, mesNA, anoNA, nome);
}

void Pessoa::Inicializa(int diaNA, int mesNA, int anoNA, const char* nome){
    diaP = diaNA;
    mesP = mesNA;
    anoP = anoNA;
    idadeP = -1;
    std::strcpy(nomeP, nome);
}

void Pessoa::calc_idade(int diaAT, int mesAT, int anoAT){
    idadeP = anoAT - anoP;
    
    if(mesP > mesAT)
        idadeP--;
    else{
        if(mesP == mesAT){
            if(diaP > diaAT)
                idadeP--;
        }
    }
}

void Pessoa::imprime_idade(){
    std::cout << nomeP << " atualmente tem " << idadeP << " anos" << std::endl;
}

void Pessoa::calc_idade_imprime(int diaAT, int mesAT, int anoAT){
    calc_idade(diaAT, mesAT, anoAT);
    imprime_idade();
}

int Pessoa::getIdade(){
    return idadeP;
}

void Pessoa::setID(int i){
    id = i;
}

int Pessoa::getID(){
    return id;
}

void Pessoa::setNome(const char* n){
    std::strcpy(nomeP, n);
}

char* Pessoa::getNome(){
    return nomeP;
}

void Pessoa::informaRenda(){
    std::cout << "Nenhuma informação sobre a renda de " << nomeP << std::endl;
}