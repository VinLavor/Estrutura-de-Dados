#include<iostream>
#include"pilha_com_lista_encadeada.h"
#include <cstddef>
using namespace std;



pilhadinamica:: pilhadinamica(){
    noh_topo = nullptr;


}



pilhadinamica:: ~pilhadinamica(){
    Noh* temporario;
    while(temporario != nullptr){
        temporario = noh_topo;
        noh_topo = noh_topo ->proximo;
        delete temporario;  

    }

}

bool pilhadinamica:: vazio(){
    return(noh_topo == nullptr);
}

bool pilhadinamica:: cheio(){
    Noh* novo_noh;
    try{
        novo_noh = new Noh;
        delete novo_noh;
        return false;
    } catch(bad_alloc exception){
        return true;
    }
    
}


void pilhadinamica:: empilhar(TipoItem item){
    if(cheio()){
        cout << "A pilha está cheia \n";
        cout << "não foi possivel inserir o elemento";
    } else{

        Noh* novo_noh = new Noh; // cria o novo nó
        novo_noh -> valor = item;  // o novo nó recebe o valor
        novo_noh ->proximo = noh_topo; // o novo nó aponta para o anterior
        noh_topo = novo_noh; // o novo_noh passa a ser o novo topo da pilha   
    }

}



TipoItem pilhadinamica:: desempilhar(){
    if(vazio()){
        cout << "a pilha esta vazia/n";
        cout << "nao eh possivel remover";
        return 0;
    }else{
        Noh* temporario = noh_topo; // cria um nó temporario
        TipoItem valor = noh_topo ->valor; // guarda o valor a ser retornado
        noh_topo = noh_topo ->proximo; // o topo passa a ser o ultimo no antes daquele a ser removido
        delete temporario;
        return valor;
    }

}





void pilhadinamica:: imprimir(){
        Noh *temporario = noh_topo;
        while(temporario != nullptr){ // enquanto não for um null pointer
            
            cout << temporario ->valor << " ";
            temporario = temporario->proximo;   

        }
        cout << endl;

    }

