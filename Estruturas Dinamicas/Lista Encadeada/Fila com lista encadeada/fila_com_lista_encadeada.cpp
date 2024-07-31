#include<iostream>
using namespace std;

class Fila{

struct Noh{
int valor;
Noh* prox;
};

private:
Noh* inicio;
Noh* fim;

public:
Fila(){
    inicio = fim = nullptr;
}

void enfilar(int elemento){
    Noh* novo_noh = new Noh;
        novo_noh->valor = elemento;
        novo_noh->prox = nullptr;
    if(inicio == nullptr and fim == nullptr){
        inicio = fim = novo_noh;
    }
    else{
        fim->prox = novo_noh;
        fim = novo_noh;
    }
    
}

void enfilar_primeiro(int elemento){
    Noh* novo_noh = new Noh;
        novo_noh->prox = inicio;
        novo_noh->valor = elemento;
        inicio = novo_noh;

}

int verificar(){
    return inicio->valor;
}

void desenfilar(){
    Noh* temporario;
    if(inicio == fim){
        temporario = inicio;
        inicio = fim = nullptr;
        delete temporario;
    }
    else{
        temporario = inicio;
        inicio = inicio->prox;
        delete temporario;
    }
}

void mostrar_fila(){
    Noh* temporario;
    temporario = inicio;

    while(temporario != nullptr){
        
    cout << temporario->valor << " ";
    temporario = temporario->prox;
    }
    cout << "\n";
}
};
        





int main(){
 Fila fila;
 int opcao = 1;
 int valor;


 while(opcao != 0){
 cout << "digite a operacao que deseja realizar:\n";
 cout << "0-Parar programa\n";
 cout << "1-Enfilar elemento\n";
 cout << "2-Desenfilar elemento\n";
 cout << "3-Verificar Primeiro\n";
 cout << "4-Verificar a fila \n";
 cout << "5-Enfilar em primeiro \n";


 cin >> opcao;

    if(opcao == 1){
        cout << "digite o elemento a ser inserido\n";
        cin >> valor;
        fila.enfilar(valor);
    }
    else if(opcao == 2){
        fila.desenfilar();
    }
    else if(opcao == 3){
        cout << fila.verificar() << "\n";
    }
    else if(opcao == 4){
        fila.mostrar_fila();
    }
    else if(opcao == 5){
        cout << "digite o elemento a ser inserido\n";
        cin >> valor;
        fila.enfilar_primeiro(valor);
    }

 }
}