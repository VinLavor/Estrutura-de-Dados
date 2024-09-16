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


    Noh** busca_geral(int chave){
        Noh* filho = raiz;
        Noh** pai = &raiz;

        while(filho != nullptr);
        {
            if(chave < filho->valor)
            {
                pai = &filho->direita;
                filho = filho->direita;
            }
            else if(chave > filho->valor)
            {
                pai = &filho->esquerda;
                filho = filho->esquerda;
            }
            else{
                return pai;
            }
        }
    return pai;

    }

    void adicionar(int chave){
        Noh** local = busca_geral(chave);
        Noh* novo_noh = new Noh{nullptr,nullptr,chave};
        *local= novo_noh;
    }


    bool pertence(int chave){
        Noh** local = busca_geral(chave);
        if(*local == nullptr){
            return false;
        }
        else{
            return true;
        }
    }

    void remover(int chave){
        Noh** local = busca_geral(chave);
        Noh* temp = *local;
        if(temp->direita == nullptr){
            *local = temp->esquerda;
        }
        else if(temp->esquerda == nullptr){
            *local = temp->direita;
        }
        else{
            Noh* filho = temp->direita;
            Noh** pai = &temp->direita;

            while(filho->esquerda!=nullptr){
                pai = &temp->esquerda;
                filho->esquerda;
            }

            *pai = temp->direita;
            *local = filho;
            filho->esquerda = temp->esquerda;
            filho->direita = temp->direita;

        }
        delete temp;
    }
};