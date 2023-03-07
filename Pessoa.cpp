#include "Pessoa.h"

Pessoa::Pessoa(int diaNA, int mesNA, int anoNA){
    diaP = diaNA;
    mesP = mesNA;
    anoP = anoNA;
    idadeP = -1;
    }

void Pessoa::calc_idade(int diaAT, int mesAT, int anoAT){
    idadeP = anoAT - anoP;
    
    if(mesP < mesAT)
        idadeP--;
    else{
        if(mesP == mesAT){
            if(diaP > diaAT)
                idadeP--;
        }
    }
}

int Pessoa::getIdade(){
    return idadeP;
}