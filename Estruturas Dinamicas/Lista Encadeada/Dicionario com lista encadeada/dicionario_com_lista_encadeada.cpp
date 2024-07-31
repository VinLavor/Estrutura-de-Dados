#include<iostream>
#include<string>
using namespace std;
using std::string;


class Dicionario{

struct Noh{

int chave;
string nome;
Noh * prox;

};

private:
Noh * primeiro;

public:

Dicionario(){
primeiro = nullptr;

}

void adicionar_novo(int chave, string nome){

 Noh *noh_novo = new Noh;
 noh_novo->chave = chave; // recebe a chave
 noh_novo->nome = nome; // recebe o valor 
 noh_novo->prox = primeiro;
 primeiro = noh_novo; // novo nó se torna o proximo a receber

}
struct Consulta{
bool achou;
string valor;
};

Consulta buscar(int chave){
 Consulta consulta;
 Noh* temporario;
 temporario = primeiro;

 while(temporario != nullptr){  

    if(temporario->chave == chave){
        consulta.achou = true;
        consulta.valor = temporario->nome;
        return consulta;
    }

    temporario = temporario->prox;



 }
  consulta.achou = false;
  consulta.valor = "essa chave nao existe";
  return consulta;
}

void adicionar(int chave, string valor){
    if(buscar(chave).achou){
        return;
    }
    else{
        adicionar_novo(chave,valor);
    }
}

void remover(int chave){
    Noh* temporario = primeiro;
    if(temporario == nullptr) return;

    if(temporario->chave == chave){ // se o primeiro já é a chave procurada
    primeiro= primeiro->prox;
    delete temporario;
    return;
    }

    while(temporario->prox != nullptr){
        if(temporario->prox->chave == chave){ // verifica o nó seguinte a esse
            Noh* remover;
            remover = temporario -> prox;
            temporario ->prox = remover -> prox;
            delete remover;
            return;
        }
        temporario = temporario->prox;
    }
}

};









int main(){
    Dicionario dicionario;
    int opcao;
    string elemento;
    int chave;


    while(opcao != 0){
        
    cout << "digite a operacao que deseja realizar:\n";
    cout << "0-Parar o programa\n";
    cout << "1-Adicionar elemento\n";
    cout << "2-Remover elemento\n";
    cout << "3-Buscar elemento\n";
    cin >> opcao;

    if(opcao == 1){
        cout << "Digite a chave do elemento e seu valor: \n";
        cin >> chave >> elemento;
        dicionario.adicionar_novo(chave,elemento);
    }
    else if(opcao == 2){
        cout << "Digite a chave do elemento a ser removido: \n";
        cin >> chave;
        dicionario.remover(chave);
    }
    else if(opcao == 3){
        cout << "Digite a chave do elemento a ser buscado: \n";
        cin >> chave;
        cout << dicionario.buscar(chave).valor << "\n";
    }
    }

}