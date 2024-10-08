#include<iostream>
using namespace std;

struct Pilha{
    int* array;
    int num_elementos = 0;
    int tamanho;
};

void inicializar(Pilha &pilha, int tamanho){
    pilha.array = new int[tamanho];
    pilha.tamanho = tamanho;
}

void redimensionar(Pilha& pilha){
    int novo_tamanho = pilha.tamanho * 2;
    int *novo_array = new int[novo_tamanho];

    for(int i = 0; i < pilha.tamanho; i++){
        novo_array[i] = pilha.array[i];
    }
    delete[] pilha.array;

    pilha.array = novo_array;
    pilha.tamanho = novo_tamanho;
}

void empilhar(Pilha &pilha, int numero){
    if(pilha.num_elementos == pilha.tamanho){
        redimensionar(pilha);
    }
    
    pilha.array[pilha.num_elementos] = numero;
    pilha.num_elementos++;
}

void desempilhar(Pilha& pilha){
    pilha.num_elementos--;
}

int main(){
Pilha pilha;

inicializar(pilha,3);

for(int i = 0; i<10;i++){
    empilhar(pilha,i);
}
for(int i = 0; i<10;i++){
    cout << pilha.array[i] << " ";
}
cout << " "<< endl;

desempilhar(pilha);
empilhar(pilha,15);

for(int i = 0; i<10;i++){
    cout << pilha.array[i] << " ";
}
}