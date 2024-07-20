typedef int TipoItem;

struct Noh {
    TipoItem valor;
    Noh* proximo;

};

class pilhadinamica{
    private:
    Noh* noh_topo;

    public:
    pilhadinamica(); // construtor
    ~pilhadinamica();  // destrutor
    bool vazio();
    bool cheio();
    void empilhar(TipoItem item); // inserir
    TipoItem desempilhar();
    void imprimir();
};