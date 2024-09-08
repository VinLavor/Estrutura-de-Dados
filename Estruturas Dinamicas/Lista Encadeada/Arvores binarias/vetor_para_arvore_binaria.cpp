#include <iostream>
using namespace std;

struct Noh {
    Noh* esquerda;
    Noh* direita;
    int valor;
};


Noh* construir_arvore(int* lista, int inicio, int fim) {
    if (inicio > fim) {
        return nullptr;
    }

    int meio_vetor = inicio + (fim - inicio) / 2;
    Noh* raiz = new Noh{nullptr, nullptr, lista[meio_vetor]}; 

    raiz->esquerda = construir_arvore(lista, inicio, meio_vetor - 1);
    raiz->direita = construir_arvore(lista, meio_vetor + 1, fim);

    return raiz;
}


void mostrar(Noh* raiz) {
    if (raiz == nullptr) {
        return;
    }
    mostrar(raiz->esquerda);
    std::cout << raiz->valor << " ";
    mostrar(raiz->direita);
}

int main() {
    int lista[]{2,4,6,8,10,12,14};
    Noh* arvore = construir_arvore(lista, 0, 6);
    mostrar(arvore);
    return 0;
}