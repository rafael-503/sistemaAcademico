#include "Estagiario.h"
#include <iostream>

Estagiario::Estagiario(int diaNA, int mesNA, int anoNA, const char* nome): Aluno(diaNA, mesNA, anoNA, nome){
    incicializa();
}

Estagiario::Estagiario(): Aluno(){
    incicializa();
} 

Estagiario::~Estagiario(){}

void Estagiario::incicializa(){
    bolsa_estagio = 0.0;
}

void Estagiario::setBolsaEstagio(float b){
    bolsa_estagio = b;
}

float Estagiario::getBolsaEstagio(){
    return bolsa_estagio;
}

void Estagiario::informaRenda(){
    std::cout << nomeP << " tem uma bolsa estagio no valor de " << bolsa_estagio << std::endl;
}