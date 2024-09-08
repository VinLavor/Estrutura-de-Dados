#include <iostream>
using namespace std;

class ArvoreBinaria{
    public:
    struct Noh{
        Noh* esquerda;
        Noh* direita;
        int valor;
    };

    Noh* raiz;

    
    ArvoreBinaria()
    {
        raiz = nullptr;
    }

    bool vazio()
    {
        if(raiz == nullptr) return true;
        else return false;
    }

    void adicionar(int valor)
    {
        Noh* novo_noh = new Noh{nullptr,nullptr,valor};
        if(vazio())
        {
            raiz = novo_noh;
            return;
        }

        Noh* temporario = raiz;

        while(true)
        {
            if(valor < temporario ->valor)
            {
                if(temporario->esquerda == nullptr)
                {
                    temporario ->esquerda = novo_noh;
                    return;
                }
                temporario = temporario->esquerda;
            }
            else
            {
                if(temporario->direita == nullptr)
                {
                    temporario->direita = novo_noh;
                    return;
                }
                temporario = temporario -> direita;
            }
                
        }
    }

    bool pertence(int valor)
    {
        Noh* temporario = raiz;
        
        while(temporario != nullptr)
        {
            if(temporario ->valor == valor) return true;
            else if(valor < temporario -> valor) temporario = temporario->esquerda;
            else if(valor > temporario -> valor) temporario = temporario->direita;

        }
        return false;
    }

    void remover(int valor)
    {
        Noh* temporario = raiz;
        Noh** cima = &raiz;
        while(temporario != nullptr)
        {
            if(valor < temporario->valor)
            {
                cima = &(temporario->esquerda);
                temporario = temporario->esquerda;
            }
            else if(valor > temporario->valor)
            {
                cima = &(temporario->direita);
                temporario = temporario->direita;
            }
            else break;
        }
        if(temporario == nullptr) return;

        if(temporario->direita == nullptr) *cima = temporario->esquerda;// o ponteiro apontado por cima, que é o ponteiro do nó pai, passaa apontar para o nó esquerdo do nó filho
        else if(temporario ->esquerda == nullptr) *cima = temporario->direita;
        else
        {
            Noh* busca = temporario->direita;
            Noh** cima_b = &temporario->direita; // aponta para o ponteiro que aponta para o filho direito

            while(busca -> esquerda !=nullptr)
            {
                cima_b = &busca->esquerda;
                busca = busca->esquerda;    
            }

            *cima_b = busca->direita; // cima_b controla o ponteiro do nó pai

            *cima = busca; 
            busca->esquerda = temporario->esquerda; 
            busca->direita = temporario->direita; 

        }
        delete temporario;
    }


    void exibir_arvore(Noh* raiz)
    {
        if (raiz == nullptr) {
        return;
    }
    exibir_arvore(raiz->esquerda);
    std::cout << raiz->valor << " ";
    exibir_arvore(raiz->direita);
    }

};




int main()
{
    ArvoreBinaria arvore;

    
    arvore.adicionar(50);
    arvore.adicionar(30);
    arvore.adicionar(70);
    arvore.adicionar(20);
    arvore.adicionar(40);
    arvore.adicionar(60);
    arvore.adicionar(80);

    cout << "Arvore apos insercoes: ";
    arvore.exibir_arvore(arvore.raiz);  
    
    cout << "Pertence 40? " << (arvore.pertence(40) ? "Sim" : "Não") << endl;
    cout << "Pertence 25? " << (arvore.pertence(25) ? "Sim" : "Não") << endl;

    
    arvore.remover(20);  
    cout << "Arvore após remover 20: ";
    arvore.exibir_arvore(arvore.raiz);

    arvore.remover(30);  
    cout << "Arvore após remover 30: ";
    arvore.exibir_arvore(arvore.raiz);

    arvore.remover(50);  
    cout << "Arvore após remover 50: ";
    arvore.exibir_arvore(arvore.raiz);

    return 0;
}
