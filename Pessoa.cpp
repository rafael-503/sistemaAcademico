#include "Pessoa.h"

// passagem por referencia ->
void calc_idade(struct Pessoa *p, int dia, int mes, int ano){
    p->idade = ano - p->ano;
    
    if(p->mes > mes)
        p->idade--;
    else{
        if(p->mes == mes){
            if(p->dia > dia)
                p->idade--;
        }
    }
}