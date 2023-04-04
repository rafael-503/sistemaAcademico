#pragma once

template <class TIPO>

class Elemento{
    private:
        Elemento<TIPO>* pProximo;
        Elemento<TIPO>* pAnterior;
        TIPO* pInfo;
        char nome[150];

    public:
        Elemento();
        ~Elemento();

        void setProximo(Elemento<TIPO>* pProx);
        Elemento<TIPO> *getProximo();

        void setAnterior(Elemento<TIPO>* pAnt);
        Elemento<TIPO> *getAnterior();

        void setInfo(TIPO* pInf);
        TIPO *getInfo();

        void setNome(char* n);
        char* getNome();         
};