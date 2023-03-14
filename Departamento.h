#pragma once

class Departamento{
    private:
        char nome[100];
    public:
        Departamento();
        ~Departamento();

        void setNome(const char* n);
        char* getNome();
};