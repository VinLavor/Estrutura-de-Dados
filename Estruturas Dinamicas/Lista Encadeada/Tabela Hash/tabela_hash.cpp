#include <iostream>
#include<string.h>
using namespace std;

class TabelaHash{
    private:

    struct Noh{
      int chave;
      string valor;
      Noh* prox;


    };

    int tamanho;
    int elementos;
    Noh** tabela; // vetor de ponteiros para ponteiros de noh
    Noh sentinela;

    public:

    TabelaHash()
    {
       tamanho = 1;
       elementos = 0;
       tabela = new Noh*[tamanho];
       tabela[0] = &sentinela;
    }

    int hash(int chave)
    {
        return chave % tamanho;
    }

    void redimensionar(int novo_tam){
        Noh** nova_tabela = new Noh* [novo_tam];
        int tam_atual = tamanho;
        tamanho = novo_tam;

        for (int i = 0; i < novo_tam; i++) 
        {
         nova_tabela[i] = &sentinela;
        }

        for (int i = 0; i < tam_atual; i++)
        {
          Noh* coluna = tabela[i];

          while(coluna != &sentinela)
          {
            Noh* auxiliar = coluna->prox;
            int local = hash(coluna->chave);
            coluna->prox = nova_tabela[local];  // vai apontar para onde a tabela esta apontando
            nova_tabela[local] = coluna;
            coluna = auxiliar;
          }
        
        }
        
        delete[] tabela;
        tabela = nova_tabela;

    }
    

    void adicionar(int chave, string nome)
    {
      if(tamanho == elementos) redimensionar(2*tamanho);
      
      int local = hash(chave);

      Noh* novo_noh = new Noh;
      novo_noh ->prox = tabela[local]; // caso vazio, aponta para o sentinela
      tabela[local] = novo_noh;
      
      novo_noh ->chave = chave;
      novo_noh ->valor = nome;
  
      ++elementos;
    }
  
   struct Achou{
    bool achou;
    string nome;
   };

   Achou buscar(int chave_p){
    int local = hash(chave_p);
    Achou busca;
    Noh* temporario = tabela[local];

    while(temporario != &sentinela)
    {
      if(temporario->chave == chave_p)
      {
        busca.achou = true;
        busca.nome = temporario->valor;
        return busca;
      }
      else
      {
        temporario = temporario->prox;
      }
    }
    busca.achou = false;
    busca.nome = "";
    return busca;
   }

   void remover(int chave_p){
    int local = hash(chave_p);
    Noh* temporario = tabela[local];

    if(tabela[local]->chave == chave_p)
    {
      tabela[local] = temporario->prox;
      delete temporario;
      return;
    }

    while(temporario != &sentinela)
    {
      if(temporario->prox->chave == chave_p)
      {
        Noh* remocao = temporario->prox;
        temporario-> prox = remocao->prox;
        delete remocao;

      }
      else
      {
        temporario = temporario ->prox;
      }
   }
   }

  
    
};



int main(){
    TabelaHash Tabela;
    int chave;
    string nome;
    int opcao;

    while(opcao != 0){
        
    cout << "digite a operacao que deseja realizar:\n";
    cout << "0-Parar o programa\n";
    cout << "1-Adicionar elemento\n";
    cout << "2-buscar elemento\n";
    cout << "3-remover elemento\n";
    cin >> opcao;

    if(opcao == 1){
        cout << "Digite a chave do elemento e seu valor: \n";
        cin >> chave >> nome;
        Tabela.adicionar(chave,nome);
    }

    else if(opcao == 2){
        cout << "Digite a chave do elemento a ser buscado: \n";
        cin >> chave;
        cout << Tabela.buscar(chave).nome << '\n';
    }

    else if(opcao == 3){
        cout << "Digite a chave do elemento a ser removido \n";
        cin >> chave;
        Tabela.remover(chave);
    }
    
    }
}

