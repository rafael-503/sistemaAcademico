#include "Pessoa.h"
#include <iostream>
#include <string.h>

Pessoa::Pessoa(int diaNA, int mesNA, int anoNA, const char* nome){
    diaP = diaNA;
    mesP = mesNA;
    anoP = anoNA;
    idadeP = -1;
    strcpy(nomeP, nome);
}

void Pessoa::calc_idade(int diaAT, int mesAT, int anoAT){
    idadeP = anoAT - anoP;
    
    if(mesP < mesAT)
        idadeP--;
    else{
        if(mesP == mesAT){
            if(diaP < diaAT)
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