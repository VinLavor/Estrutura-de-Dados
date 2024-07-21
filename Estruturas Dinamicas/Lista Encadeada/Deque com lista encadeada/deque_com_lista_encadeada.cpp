#include<iostream>
#include "deque_com_lista_encadeada.h"

using namespace std;

Deque :: Deque(){
    esq = dir = nullptr;

}
Deque ::~Deque(){

}
bool Deque:: vazio(){
    return(esq == nullptr and dir == nullptr);
}
void Deque:: inserir_esq(TipoItem valor){
    Noh* noh_novo = new Noh;
    noh_novo ->ant = nullptr;
    noh_novo -> valor = valor;
    noh_novo ->prox = esq;

    if(esq == nullptr){dir = noh_novo; }
    else{esq ->ant =noh_novo; }

    esq = noh_novo;

}
void Deque:: inserir_dir(TipoItem valor){
    Noh* noh_novo = new Noh;
    noh_novo ->valor = valor;
    noh_novo ->ant = dir;
    noh_novo ->prox = nullptr;
    if(dir == nullptr){esq = noh_novo; }
    else{dir ->prox = noh_novo; }

    dir = noh_novo;
}
void Deque:: remover_esq(){
    Noh* temporario;
    temporario = esq;
    esq = esq ->prox;
    if(esq == nullptr){dir = nullptr; }
    else{esq ->ant = nullptr; }
    delete temporario; 
    
}
void Deque:: remover_dir(){
    Noh* temporario;
    temporario = dir;
    dir= dir->ant;
    if(dir==nullptr){esq = nullptr; }
    else{dir->prox = nullptr; }
    delete temporario;  
}
void Deque:: visualizar(){
    Noh* temporario;
    temporario = esq;
    while(temporario != nullptr){
    cout << temporario ->valor << " ";
    temporario = temporario ->prox;

    }
    cout << endl;
}
