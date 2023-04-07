#pragma once
#include "Aluno.h"

class Estagiario : public Aluno{
    protected:
        float bolsa_estagio;

    public:
        Estagiario(int diaNA, int mesNA, int anoNA, const char* nome="");
        Estagiario();  
        ~Estagiario();

        void incicializa();
        void setBolsaEstagio(float b);
        float getBolsaEstagio();
        void informaRenda();
};