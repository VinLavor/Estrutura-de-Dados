#include<iostream>
using namespace std;

struct Pilha_Numeros{
    int* array;
    int num_elementos = 0;
    int tamanho;
};

struct Pilha_Operadores{
    int* array;
    int num_elementos = 0;
    int tamanho;
};

void inicializar_pilhas(Pilha_Numeros& pilha, int tamanho){
    pilha.array = new int[tamanho];
    pilha.tamanho = tamanho;
}

void redimensionar(Pilha_Numeros& pilha){
    int novo_tamanho = pilha.tamanho * 2;
    int *novo_array = new int[novo_tamanho];

    for(int i = 0; i < pilha.tamanho; i++){
        novo_array[i] = pilha.array[i];
    }
    delete[] pilha.array;

    pilha.array = novo_array;
    pilha.tamanho = novo_tamanho;
}

void empilhar(Pilha_Numeros &pilha, int numero){
    if(pilha.num_elementos == pilha.tamanho){
        redimensionar(pilha);
    }
    
    pilha.array[pilha.num_elementos] = numero;
    pilha.num_elementos++;
}

void desempilhar(Pilha_Numeros& pilha){
    pilha.num_elementos--;
}

int main(){




}