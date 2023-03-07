class Pessoa{
    private:
        int diaP;
        int mesP;
        int anoP;
        int idadeP;

    public:
        Pessoa(int diaNA, int mesNA, int anoNA);
        void calc_idade(int diaAT, int mesAT, int anoAT);
        int getIdade();
};