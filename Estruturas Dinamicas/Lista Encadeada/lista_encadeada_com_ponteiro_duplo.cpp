#include<iostream>
using namespace std;

class ListaEncadeada{

struct Noh{

int chave;
string nome;
Noh * prox;

};

private:
Noh * frente;

public:

ListaEncadeada()
{
frente = nullptr;

}

void adicionar_novo(int chave, string nome)
{

  Noh* noh_novo = new Noh;
  noh_novo->chave = chave;  
  noh_novo->nome = nome;    
  noh_novo->prox = frente;  
        
       
  frente = noh_novo;
 
 


}

void remover(int chave)
{

    Noh** atual = &frente;
    while((*atual) != nullptr)
    {
        if((*atual)->chave == chave)
        {
            Noh* noh_a_remover = *atual;
            *atual = noh_a_remover->prox;
            delete noh_a_remover;
        }
    }
}
};


