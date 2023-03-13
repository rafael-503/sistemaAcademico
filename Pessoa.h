class Pessoa{
    private:
        int diaP;
        int mesP;
        int anoP;
        int idadeP;
        char nomeP[50];

    public:
        Pessoa(int diaNA, int mesNA, int anoNA, const char* nome);
        void calc_idade(int diaAT, int mesAT, int anoAT);
        void imprime_idade();
        void calc_idade_imprime(int diaAT, int mesAT, int anoAT);
        int getIdade();
};