typedef int TipoItem;

struct Noh{
    Noh* ant;
    TipoItem valor;
    Noh* prox;

};

class Deque{
    private:
    Noh* esq, *dir;
    
    public:
    Deque();
    ~Deque();
    bool vazio();
    void inserir_esq(TipoItem valor);
    void inserir_dir(TipoItem valor);
    void remover_esq();
    void remover_dir();
    void visualizar();

};

