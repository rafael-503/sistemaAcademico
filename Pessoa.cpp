#include "Pessoa.h"

int calc_idade(struct Pessoa p, int anoAtual){
    int idade = anoAtual - p.ano;
    p.idade = idade;
    return idade;
}