#include "Principal.h"
#include <ctime>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

Principal::Principal():
 Einsten(), Newton(), Simao(),
 contIdAluno(0), contIdDepart(0), contIdDisc(0),
 Computacao1(contIdDisc++), Computacao2(contIdDisc++), Algoritmos(contIdDisc++), TecProg(contIdDisc++),
 AAA(contIdAluno++), BBB(contIdAluno++), CCC(contIdAluno++), DDD(contIdAluno++),
 DAINF(contIdDepart++), FisicaPrinceton(contIdDepart++), MatematicaCambdrige(contIdDepart++){
    // leitura da data atual
    time_t now = time(nullptr);
    tm *local = localtime(&now);
    diaAtual = local->tm_mday;
    mesAtual = local->tm_mon + 1;
    anoAtual = local->tm_year + 1900;

    inicializa();
}

Principal::~Principal(){}

void Principal::inicializa(){
    inicializaUniversidades();
    inicializaDepartamentos();
    inicializaProfessores();
    inicializaDisciplinas();
    inicializaAlunos();
}

void Principal::inicializaUniversidades(){
    UTFPR.setNome("UTFPR");
    LUniversidades.incluiInfo(&UTFPR, UTFPR.getNome());

    Princeton.setNome("Princeton University");
    LUniversidades.incluiInfo(&Princeton, Princeton.getNome());

    Cambdrige.setNome("Cambdrige University");
    LUniversidades.incluiInfo(&Cambdrige, Cambdrige.getNome());
}

void Principal::inicializaDepartamentos(){
    DAINF.setNome("DAINF");
    FisicaPrinceton.setNome("Fisica Princeton");
    MatematicaCambdrige.setNome("Matematica Cambdrige");

    LDepartamentos.incluiInfo(&DAINF, DAINF.getNome());
    LDepartamentos.incluiInfo(&FisicaPrinceton, FisicaPrinceton.getNome());
    LDepartamentos.incluiInfo(&MatematicaCambdrige, MatematicaCambdrige.getNome());

    UTFPR.setDepartamento(&DAINF);
    Princeton.setDepartamento(&FisicaPrinceton);
    Cambdrige.setDepartamento(&MatematicaCambdrige);
}

void Principal::inicializaProfessores(){
    // inicializacao dos professores
    Einsten.inicializa(14, 3, 1879, "Albert Einstein");
    Newton.inicializa(4, 1, 1643, "Isaac Newton");
    Simao.inicializa(3, 10, 1976, "Jean Simao");

    // associacao dos professores com as universidades
    Einsten.setUnivFiliado(&Princeton);
    Newton.setUnivFiliado(&Cambdrige);
    Simao.setUnivFiliado(&UTFPR);

    // associacao dos professores com os departamentos
    Einsten.setDptoFiliado(&FisicaPrinceton);
    Newton.setDptoFiliado(&MatematicaCambdrige);
    Simao.setDptoFiliado(&DAINF);
}

void Principal::inicializaDisciplinas(){
    Computacao1.setNome("Computacao 1");
    LDisciplinas.incluiInfo(&Computacao1, Computacao1.getNome());

    Computacao2.setNome("Computacao 2");
    LDisciplinas.incluiInfo(&Computacao2, Computacao2.getNome());

    Algoritmos.setNome("Algoritmos");
    LDisciplinas.incluiInfo(&Algoritmos, Algoritmos.getNome());

    TecProg.setNome("Tecnicas de Programacao");
    LDisciplinas.incluiInfo(&TecProg, TecProg.getNome());

    Computacao1.setDepartamento(&DAINF);
    Computacao2.setDepartamento(&DAINF);
    Algoritmos.setDepartamento(&DAINF);
    TecProg.setDepartamento(&DAINF);

    TecProg.incluiAluno(&AAA);
    TecProg.incluiAluno(&BBB);
    Algoritmos.incluiAluno(&AAA);
    Algoritmos.incluiAluno(&DDD);



    //TecProg.excluiAluno(&BBB);
    //TecProg.excluiAluno(&AAA);
}

void Principal::inicializaAlunos(){
    AAA.setNome("AA");
    LAlunos.incluiInfo(&AAA, AAA.getNome());

    BBB.setNome("BB");
    LAlunos.incluiInfo(&BBB, BBB.getNome());

    CCC.setNome("CC");
    LAlunos.incluiInfo(&CCC, CCC.getNome());

    DDD.setNome("DD");
    LAlunos.incluiInfo(&DDD, DDD.getNome());
}

void Principal::calcIdadeProf(){
    Einsten.calc_idade_imprime(diaAtual, mesAtual, anoAtual);
    Newton.calc_idade_imprime(diaAtual, mesAtual, anoAtual);
    Simao.calc_idade_imprime(diaAtual, mesAtual, anoAtual);
}

void Principal::univOndeProfsTrabalham(){
    Einsten.ondeTrabalho();
    Newton.ondeTrabalho();
    Simao.ondeTrabalho();
}

void Principal::dptoOndeProfsTrabalham(){
    Einsten.qualDepartamentoTrabalho();
    Newton.qualDepartamentoTrabalho();
    Simao.qualDepartamentoTrabalho();
}

void Principal::listaDiscDeptos(){
    DAINF.listaDisciplinas();
    FisicaPrinceton.listaDisciplinas();
    MatematicaCambdrige.listaDisciplinas();
}

void Principal::listaAlunosDisc(){
    TecProg.listaAlunos();
    //TecProg.listaAlunosInv(); lista inversa

    Algoritmos.listaAlunos();
    //Algoritmos.listaAlunosInv(); lista inversa
}

void Principal::executar(){
    //calcIdadeProf();
    //univOndeProfsTrabalham();
    //dptoOndeProfsTrabalham();
    //listaDiscDeptos();
    //listaAlunosDisc();
    menu();
}

void Principal::cadDisciplina(){
    
}

void Principal::cadDepartamento(){
    char nomeUniversidade[100];
    char nomeDepartamento[100];
    Universidade* pUniv = nullptr;
    Departamento* pDepart = nullptr;

    cout << "Informe o nome da universidade: ";
    cin >> nomeUniversidade;
    pUniv = LUniversidades.localizar(nomeUniversidade);

    if (pUniv != nullptr){
        cout << "Informe o nome do departamento: ";
        cin >> nomeDepartamento;

        pDepart = new Departamento();
        pDepart->setNome(nomeDepartamento);
        pDepart->setUniversidade(pUniv);
        LDepartamentos.incluiInfo(pDepart);
        pUniv->setDepartamento(pDepart);
    }
    else{
        cout << "Universidade não encontrada!" << endl;
    }
}

void Principal::cadUniversidade(){
    char nomeUniversidade[100];
    Universidade* pUniv = nullptr;

    cout << "Informe o nome da universidade: ";
    cin >> nomeUniversidade;

    pUniv = new Universidade();
    pUniv->setNome(nomeUniversidade);
    LUniversidades.incluiInfo(pUniv);

    cout << "Universidade cadastrada com sucesso!" << endl;
}

void Principal::cadAluno(){
    char nomeAluno[100];
    int ra;
    Aluno* pAluno = nullptr;

    cout << "Informe o nome do aluno: " << endl;
    cin >> nomeAluno;

    cout << "Informe o RA do aluno: " << endl;
    cin >> ra;

    pAluno = new Aluno(contIdAluno++);

    pAluno->setNome(nomeAluno);
    pAluno->setRA(ra);
    LAlunos.incluiInfo(pAluno);

    cout << "Aluno cadastrado com sucesso!" << endl;
}

void Principal::gravarTudo(){}
void Principal::gravarUniversidades(){}
void Principal::gravarDepartamentos(){}
void Principal::gravarDisciplinas(){}

void Principal::gravarAlunos(){
    //LAlunos.gravarAlunos();
}

void Principal::gravarProfessores(){}
void Principal::recuperarTudo(){}
void Principal::recuperarUniversidades(){}
void Principal::recuperarDepartamentos(){}
void Principal::recuperarDisciplinas(){}

void Principal::recuperarAlunos(){
    //LAlunos.recuperarAlunos();
}
void Principal::recuperarProfessores(){}

void Principal::menu(){
    int op= -1;

    while (op!= 5){
        system("clear");
        cout << "Informe a opção desejada: " << endl;
        cout << "1 - Cadastrar" << endl;
        cout << "2 - Executar" << endl;
        cout << "3 - Gravar" << endl;
        cout << "4 - Recuperar" << endl;
        cout << "5 - Sair" << endl;
        cin >> op;

        switch (op){
        case 1:{menuCad();}
            break;
        case 2:{menuExe();}
            break;
        case 3:{menuGravar();}
            break;
        case 4:{menuRecuperar();}
            break;
        case 5: {cout << "Saindo..." << endl;}
            break;
        default:{cout << "Opção inválida!" << endl;
                getchar();}
        }
    }
}

void Principal::menuCad(){
    int op= -1;

    while (op!= 5){
        system("clear");
        cout << "Informe a opção desejada: " << endl;
        cout << "1 - Cadastrar Disciplina" << endl;
        cout << "2 - Cadastrar Departamento" << endl;
        cout << "3 - Cadastrar Universidade" << endl;
        cout << "4 - Cadastrar Aluno" << endl;
        cout << "5 - Sair" << endl;
        cin >> op;

        switch (op){
        case 1:{cadDisciplina();
                getchar();
                getchar();}
            break;
        case 2:{cadDepartamento();
                getchar();
                getchar();}
            break;
        case 3:{cadUniversidade();
                getchar();
                getchar();}
            break;
        case 4:{cadAluno();
                getchar();
                getchar();}
            break;
        case 5: {cout << "Saindo..." << endl;}
            break;
        default:{cout << "Opção inválida!" << endl;
                getchar();}
        }
    }
}

void Principal::menuExe(){
    int op= -1;
    while(op!= 5){
        system("clear");
        cout << "Informe a opção desejada: " << endl;
        cout << "1 - Listar Disciplinas" << endl;
        cout << "2 - Listar Departamentos" << endl;
        cout << "3 - Listar Universidades" << endl;
        cout << "4 - Listar Alunos" << endl;
        cout << "5 - Sair" << endl;
        cin >> op;

        switch (op){
        case 1:{LDisciplinas.listaInfos();
                getchar();
                getchar();}
            break;
        case 2:{LDepartamentos.listaInfos();
                getchar();
                getchar();}
            break;
        case 3:{LUniversidades.listaInfos();
                getchar();
                getchar();}
            break;
        case 4:{LAlunos.listaInfos();
                getchar();
                getchar();}
            break;
        case 5: {cout << "Saindo..." << endl;}
            break;
        default:{cout << "Opção inválida!" << endl;
                getchar();
                getchar();}
        }
    }
}

void Principal::menuGravar(){
    int op= -1;
    while (op != 6){
        system("clear");
        cout << "Informe a opção desejada: " << endl;
        cout << "0 - Gravar Tudo" << endl;
        cout << "1 - Gravar Universidades" << endl;
        cout << "2 - Gravar Departamentos" << endl;
        cout << "3 - Gravar Disciplinas" << endl;
        cout << "4 - Gravar Alunos" << endl;
        cout << "5 - Gravar Professores" << endl;
        cout << "6 - Sair" << endl;
        cin >> op;

        switch (op){
        case 0:{gravarTudo();
                getchar();
                getchar();}
            break;
        case 1:{gravarUniversidades();
                getchar();
                getchar();}
            break;
        case 2:{gravarDepartamentos();
                getchar();
                getchar();}
            break;
        case 3:{gravarDisciplinas();
                getchar();
                getchar();}
            break;
        case 4:{gravarAlunos();
                getchar();
                getchar();}
            break;
        case 5:{gravarProfessores();
                getchar();
                getchar();}
            break;
        case 6: {cout << "Saindo..." << endl;}
            break;
        default:{cout << "Opção inválida!" << endl;
                getchar();
                getchar();}
        }
    }
}

void Principal::menuRecuperar(){
    int op= -1;
    while (op != 6){
        system("clear");
        cout << "Informe a opção desejada: " << endl;
        cout << "0 - Recuperar Tudo" << endl;
        cout << "1 - Recuperar Universidades" << endl;
        cout << "2 - Recuperar Departamentos" << endl;
        cout << "3 - Recuperar Disciplinas" << endl;
        cout << "4 - Recuperar Alunos" << endl;
        cout << "4 - Recuperar Professores" << endl;
        cout << "6 - Sair" << endl;
        cin >> op;

        switch (op){
        case 0:{recuperarTudo();
                getchar();
                getchar();}
            break;
        case 1:{recuperarUniversidades();
                getchar();
                getchar();}
            break;
        case 2:{recuperarDepartamentos();
                getchar();
                getchar();}
            break;
        case 3:{recuperarDisciplinas();
                getchar();
                getchar();}
            break;
        case 4:{recuperarAlunos();
                getchar();
                getchar();}
            break;
        case 5:{recuperarProfessores();
                getchar();
                getchar();}
            break;
        case 6: {cout << "Saindo..." << endl;}
            break;
        default:{cout << "Opção inválida!" << endl;
                getchar();
                getchar();}
        }
    }
}