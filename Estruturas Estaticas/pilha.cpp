#include <iostream>
using namespace std ;

struct pilha{
    char p[5];
    int elementos = 0;
};
bool vazia (pilha &P){
    if (P.elementos == 0){
        return true;
    }
    return false;
}
bool cheia (pilha &P){
      if (P.elementos == 5){
        return true;
    }
    return false;
}
bool adicionar(pilha &P, char b){
    P.p[P.elementos] = b;
    P.elementos ++;
}
bool desempilhar(pilha &P){
    P.elementos--;
}


int main(){


}