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
        int getIdade();
};