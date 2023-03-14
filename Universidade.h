#pragma once

class Universidade{
    private:
        char nome[50];
    
    public:
        Universidade(const char* n="");
        ~Universidade();

        void setNome(const char* n);
        char* getNome();
};