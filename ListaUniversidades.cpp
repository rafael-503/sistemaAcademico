#include "ListaUniversidades.h"
#include <cstring>
#include <iostream>
#include <fstream>

ListaUniversidades::ListaUniversidades(int nu, const char* n){
    cont_univ = 0;
    numero_univ = nu;
    strcpy(nome, n);
}

ListaUniversidades::~ListaUniversidades(){
    LTUniversidades.limpar();
}

void ListaUniversidades::incluiUniversidade(Universidade* pu){
    if((cont_univ < numero_univ) && (pu != nullptr)){
        LTUniversidades.incluiInfo(pu, pu->getNome());
        cont_univ++;
    }
    else{
        if(pu == nullptr)
            std::cout << "Erro: Ponteiro universidade nulo" << std::endl;
        else
            std::cout << "Erro: Universidade nao incluida, lista lotada." << std::endl;
    }
}

void ListaUniversidades::listaUniversidades(){
    Elemento<Universidade>* pElAux = nullptr;
    Universidade* pUnAux = nullptr;
    pElAux = LTUniversidades.getPrimeiro();

    while(pElAux != nullptr){
        pUnAux = pElAux->getInfo();
        std::cout << "Universidade " << pUnAux->getNome() << std::endl;
        pElAux = pElAux->getProximo();
    }
}

void ListaUniversidades::listaUniversidadesInv(){
    Elemento<Universidade>* pElAux = nullptr;
    Universidade* pUnAux = nullptr;
    pElAux = LTUniversidades.getAtual();

    while(pElAux != nullptr){
        pUnAux = pElAux->getInfo();
        std::cout << "Universidade " << pUnAux->getNome() << std::endl;
        pElAux = pElAux->getAnterior();
    }
}

Universidade* ListaUniversidades::localizar(const char* n){
    Elemento<Universidade>* pAux = nullptr;
    pAux = LTUniversidades.getPrimeiro();
    while(pAux != nullptr){
        if(strcmp(pAux->getInfo()->getNome(), n) == 0){
            return pAux->getInfo();
        }
        pAux = pAux->getProximo();
    }
    return nullptr;
}

void ListaUniversidades::gravarUniversidades(){
    std::ofstream GravadorUniversidades("universidades.dat", std::ios::out);

    if(!GravadorUniversidades){
        std::cerr << "Erro ao abrir o arquivo" << std::endl;
        getchar();
        return;
    }

    Elemento<Universidade>* pAuxElUniv = nullptr;
    pAuxElUniv = LTUniversidades.getPrimeiro();

    while(pAuxElUniv != nullptr){
        GravadorUniversidades << pAuxElUniv->getInfo()->getNome() << ' ' << pAuxElUniv->getInfo()->getID() << std::endl;
		pAuxElUniv = pAuxElUniv->getProximo();
    }
    GravadorUniversidades.close();

    std::cout << "Universidades gravadas com sucesso" << std::endl;
}

void ListaUniversidades::recuperarUniversidades(){
    std::ifstream RecuperadorUniversidades("alunos.dat", std::ios::in);

    if(!RecuperadorUniversidades){
        std::cerr << "Erro ao abrir o arquivo" << std::endl;
        getchar();
        return;
    }

    Universidade* pAuxUniv = nullptr;
    char nome[100];
    int id;

    while(RecuperadorUniversidades >> nome >> id){
        if(strcmp(nome, "") != 0){
            pAuxUniv = new Universidade(id);
            pAuxUniv->setNome(nome);
            incluiUniversidade(pAuxUniv);
            LTUniversidades.incluiInfo(pAuxUniv);
            cont_univ++;
        }
    }
    RecuperadorUniversidades.close();

    std::cout << "Universidades recuperadas com sucesso" << std::endl;
}