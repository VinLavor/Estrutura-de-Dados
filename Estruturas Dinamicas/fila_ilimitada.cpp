#include<iostream>
using namespace std;

struct fila{
    int* array;
    int primeiro = -1;
    int ultimo = -1;
    int tamanho;
};

void inicializar(fila &fila, int tamanho){
    fila.array = new int[tamanho];
    fila.tamanho = tamanho;
}

void redimensionar(fila& fila, int tamanho){
    int *novo_array = new int[tamanho];
    int novo_ultimo = fila.ultimo - fila.primeiro;
    for(int i = 0; i < fila.tamanho; i++){
        novo_array[i] = fila.array[fila.primeiro + i]; // copiando os elementos para o novo espaço na memoria
    }
    delete[] fila.array;

    fila.array = novo_array;
    fila.tamanho = tamanho;
    fila.primeiro = 0;
    fila.ultimo = novo_ultimo;
}

void enfilar(fila &fila, int numero){
    if(fila.ultimo + 1 == fila.tamanho){
        redimensionar(fila, fila.tamanho * 2); // se a filar ficar cheia, aloca uma memoria maior 
    }
    if(fila.primeiro == -1){
        fila.primeiro = 0;
        fila.ultimo =0;
        fila.array[fila.primeiro] = numero;
    }
    else{
    fila.array[fila.ultimo + 1] = numero;
    fila.ultimo++;
    }
    
    
}

void desenfilar(fila& fila){
    fila.primeiro++;
    if((fila.ultimo - fila.primeiro + 1) <= fila.tamanho/4){
    redimensionar(fila,fila.tamanho/2); // caso o espaço ocupado da fila seja menor ou igual a 25%, realoca para um espaço menor
    }
}

void mostrar_fila(fila& fila){
    for(int i = fila.primeiro; i<=fila.ultimo;i++){
        cout << fila.array[i] << " " ;
    }
    cout << " " << endl;
}

int main(){

fila fila;
int elemento;
int operacao;
inicializar(fila,2);

while(operacao != 3){

cout << "digite a operacao a ser feita: 1-Enfilar, 2-Desenfilar, 3-Sair" << endl;
cin >> operacao;

if(operacao == 1){
    cout << "digite o numero a ser enfilado: "<< endl;
    cin >> elemento;
    enfilar(fila,elemento);
    mostrar_fila(fila);
}

else if(operacao == 2){
    desenfilar(fila);
    mostrar_fila(fila);
    

}

}
}