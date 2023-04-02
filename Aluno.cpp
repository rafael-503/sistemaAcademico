#include "Aluno.h"
#include <cstring>

Aluno::Aluno(int diaNA, int mesNA, int anoNA, const char* nome): Pessoa(diaNA, mesNA, anoNA, nome){
    RA = 0;
    std::strcpy(nomeP, nome);
}

Aluno::Aluno(int i): Pessoa(i), RA(0){
    id = i;
}

Aluno::~Aluno(){
    RA = -1;
}

void Aluno::setRA(int ra){
    RA = ra;
}

int Aluno::getRA(){
    return RA;
}