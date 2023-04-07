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
 DAINF(contIdDepart++), FisicaPrinceton(contIdDepart++), MatematicaCambdrige(contIdDepart++),
 LUniversidades(1000, "Sistema Universidades"){
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
    inicializaAlunos();
    inicializaDepartamentos();
    inicializaDisciplinas();
    inicializaEstagiarios();
    inicializaProfessores();
    inicializaUniversidades();
}

void Principal::inicializaAlunos(){
    Pessoa* ponteiroPessoa = nullptr;
    Aluno* ponteiroAluno = nullptr;

    AAA.setNome("AA");
    LAlunos.incluiAluno(&AAA);
    ponteiroAluno = &AAA;
    ponteiroPessoa = static_cast <Pessoa*> (ponteiroAluno);
    LPessoas.incluiPessoa(ponteiroPessoa);

    BBB.setNome("BB");
    LAlunos.incluiAluno(&BBB);
    ponteiroAluno = &BBB;
    ponteiroPessoa = static_cast <Pessoa*> (ponteiroAluno);
    LPessoas.incluiPessoa(ponteiroPessoa);

    CCC.setNome("CC");
    LAlunos.incluiAluno(&CCC);
    ponteiroAluno = &CCC;
    ponteiroPessoa = static_cast <Pessoa*> (ponteiroAluno);
    LPessoas.incluiPessoa(ponteiroPessoa);

    DDD.setNome("DD");
    LAlunos.incluiAluno(&DDD);
    ponteiroAluno = &DDD;
    ponteiroPessoa = static_cast <Pessoa*> (ponteiroAluno);
    LPessoas.incluiPessoa(ponteiroPessoa);
}

void Principal::inicializaDepartamentos(){
    DAINF.setNome("DAINF");
    FisicaPrinceton.setNome("Fisica Princeton");
    MatematicaCambdrige.setNome("Matematica Cambdrige");

    LDepartamentos.incluiDepartamento(&DAINF);
    LDepartamentos.incluiDepartamento(&FisicaPrinceton);
    LDepartamentos.incluiDepartamento(&MatematicaCambdrige);

    UTFPR.incluiDepartamento(&DAINF);
    Princeton.incluiDepartamento(&FisicaPrinceton);
    Cambdrige.incluiDepartamento(&MatematicaCambdrige);
}

void Principal::inicializaDisciplinas(){
    Algoritmos.setNome("Algoritmos");
    Computacao1.setNome("Computacao 1");
    Computacao2.setNome("Computacao 2");
    TecProg.setNome("Tecnicas de Programacao");

    LDisciplinas.incluiDisciplina(&Algoritmos);
    LDisciplinas.incluiDisciplina(&Computacao1);
    LDisciplinas.incluiDisciplina(&Computacao2);
    LDisciplinas.incluiDisciplina(&TecProg);

    Algoritmos.setDepartamento(&DAINF);
    Computacao1.setDepartamento(&DAINF);
    Computacao2.setDepartamento(&DAINF);
    TecProg.setDepartamento(&DAINF);

    Algoritmos.incluiAluno(&AAA);
    Algoritmos.incluiAluno(&DDD);
    TecProg.incluiAluno(&AAA);
    TecProg.incluiAluno(&BBB);
}

void Principal::inicializaEstagiarios(){
    Pessoa* ponteiroPessoa = nullptr;
    Aluno* ponteiroAluno = nullptr;
    Estagiario* ponteiroEstagiario = nullptr;

    Fulano.setNome("Fulano");
    Fulano.setBolsaEstagio(500);

    ponteiroEstagiario = &Fulano;
    ponteiroAluno = static_cast <Aluno*> (ponteiroEstagiario);
    LAlunos.incluiAluno(ponteiroAluno);

    ponteiroPessoa = static_cast <Pessoa*> (ponteiroAluno);
    LPessoas.incluiPessoa(ponteiroPessoa);
}

void Principal::inicializaProfessores(){
    Pessoa* ponteiroPessoa = nullptr;
    Professor* ponteiroProfessor = nullptr;

    // inicializacao dos professores
    Einsten.Inicializa(14, 3, 1879, "Albert Einstein");
    Newton.Inicializa(4, 1, 1643, "Isaac Newton");
    Simao.Inicializa(3, 10, 1976, "Jean Simao");

    // associacao dos professores com as universidades
    Einsten.setUnivFiliado(&Princeton);
    Newton.setUnivFiliado(&Cambdrige);
    Simao.setUnivFiliado(&UTFPR);

    // associacao dos professores com os departamentos
    Einsten.setDptoFiliado(&FisicaPrinceton);
    Newton.setDptoFiliado(&MatematicaCambdrige);
    Simao.setDptoFiliado(&DAINF);

    Einsten.setSalario(20000);
    Newton.setSalario(20000);
    Simao.setSalario(10000);
    Simao.setBolsaProjeto(1800);

    ponteiroProfessor = &Einsten;
    ponteiroPessoa = static_cast<Pessoa*>(ponteiroProfessor);
    LPessoas.incluiPessoa(ponteiroPessoa);

    ponteiroProfessor = &Newton;
    ponteiroPessoa = static_cast<Pessoa*>(ponteiroProfessor);
    LPessoas.incluiPessoa(ponteiroPessoa);

    ponteiroProfessor = &Simao;
    ponteiroPessoa = static_cast<Pessoa*>(ponteiroProfessor);
    LPessoas.incluiPessoa(ponteiroPessoa);
}

void Principal::inicializaUniversidades(){
    Cambdrige.setNome("Cambdrige University");
    Princeton.setNome("Princeton University");
    UTFPR.setNome("UTFPR");

    LUniversidades.incluiUniversidade(&Cambdrige);
    LUniversidades.incluiUniversidade(&Princeton);
    LUniversidades.incluiUniversidade(&UTFPR);
}

void Principal::executar(){
    menu();
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

void Principal::listaAlunosDisc(){
    TecProg.listaAlunos();
    //TecProg.listaAlunosInv(); lista inversa

    Algoritmos.listaAlunos();
    //Algoritmos.listaAlunosInv(); lista inversa
}

void Principal::listaRendaPessoas(){
    LPessoas.listaRenda();
}


void Principal::listaDiscDeptos(){
    DAINF.listaDisciplinas();
    FisicaPrinceton.listaDisciplinas();
    MatematicaCambdrige.listaDisciplinas();
}

void Principal::cadDisciplina(){
    char nomeDepartamento[100];
    char nomeDisciplina[100];

    cout << "Qual o nome do departamentoda disciplina " << endl;
    cin >> nomeDepartamento;

    Departamento* pDepart = LDepartamentos.localizar(nomeDepartamento);
    if(pDepart != nullptr){
        cout << "Informe o nome da disciplina " << endl;
        cin >> nomeDisciplina;

        Disciplina* pDisc = new Disciplina(contIdDisc);
        contIdDisc++;
        pDisc->setNome(nomeDisciplina);
        pDepart->incluiDisciplina(pDisc);
        LDisciplinas.incluiDisciplina(pDisc);
        cout << "Disciplina cadastrada com sucesso!" << endl;
    }
    else{
        cout << "Departamento não encontrado!" << endl;
    }
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

        pDepart = new Departamento(contIdDepart);
        contIdDepart++;
        pDepart->setNome(nomeDepartamento);
        pDepart->setUniversidade(pUniv);
        LDepartamentos.incluiDepartamento(pDepart);
        pUniv->incluiDepartamento(pDepart);
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
    LUniversidades.incluiUniversidade(pUniv);

    cout << "Universidade cadastrada com sucesso!" << endl;
}

void Principal::cadAluno(){
    char nomeAluno[100];
    int ra;
    Aluno* ponteiroAluno = nullptr;
    Pessoa* ponteiroPessoa = nullptr;

    cout << "Informe o nome do aluno: " << endl;
    cin >> nomeAluno;

    cout << "Informe o RA do aluno: " << endl;
    cin >> ra;

    ponteiroAluno = new Aluno(contIdAluno++);
    ponteiroAluno->setNome(nomeAluno);
    ponteiroAluno->setRA(ra);

    LAlunos.incluiAluno(ponteiroAluno);
    ponteiroPessoa = static_cast <Pessoa*> (ponteiroAluno);
    LPessoas.incluiPessoa(ponteiroPessoa);

    cout << "Aluno cadastrado com sucesso!" << endl;
}

void Principal::gravarTudo(){}
void Principal::gravarUniversidades(){}
void Principal::gravarDepartamentos(){}
void Principal::gravarDisciplinas(){}

void Principal::gravarAlunos(){
    LAlunos.gravarAlunos();
}

void Principal::gravarProfessores(){}
void Principal::recuperarTudo(){}
void Principal::recuperarUniversidades(){}
void Principal::recuperarDepartamentos(){}
void Principal::recuperarDisciplinas(){}

void Principal::recuperarAlunos(){
    LAlunos.recuperarAlunos();
}
void Principal::recuperarProfessores(){}

void Principal::menu(){
    int op = -1;

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
    while(op!= 8){
        system("clear");
        cout << "Informe a opção desejada: " << endl;
        cout << "1 - Listar Disciplinas" << endl;
        cout << "2 - Listar Departamentos" << endl;
        cout << "3 - Listar Universidades" << endl;
        cout << "4 - Listar Alunos" << endl;
        cout << "5 - Listar Professores" << endl;
        cout << "6 - Listar Pessoas" << endl;
        cout << "7 - Listar Renda Pessoas" << endl;
        cout << "8 - Sair" << endl;
        cin >> op;

        switch (op){
        case 1:{LDisciplinas.listaDisciplinas();
                getchar();
                getchar();}
            break;
        case 2:{LDepartamentos.listaDepartamentos();
                getchar();
                getchar();}
            break;
        case 3:{LUniversidades.listaUniversidades();
                getchar();
                getchar();}
            break;
        case 4:{LAlunos.listaAlunos();
                getchar();
                getchar();}
        case 5:{dptoOndeProfsTrabalham();
                getchar();
                getchar();}
        case 6:{LPessoas.listaPessoas();
                getchar();
                getchar();}
        case 7:{listaRendaPessoas();
                getchar();
                getchar();}
            break;
        case 8: {cout << "Saindo..." << endl;}
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