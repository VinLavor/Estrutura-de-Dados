#include <iostream>
using namespace std;

struct set
{
char s [5];
int n = 0;
};
bool iniciializar(set&S){
    for (int i = 0; i<5;i++){
        S.s[i] = -1;
    }
    return true;
}

bool cheia(set &S){
    if(S.n == 5) return true;
    else return false ;
}
bool vazia(set &S){
    if(S.n == 0) return true;
    else return false ;
}

bool pertence(set &S, char b){
    int i = 0 , f = S.n-1; // i e f representam respectivamente a posição inicio e final na qual o vetor vai percorrer
    while(i<=f){ // se voce observar, no momento em que o marcador de inicio deixar de ser menor o conjunto todo foi verificado
        int m = (i + f)/2; // pegar o meio do intervalo para verificar
        if(b == S.s[m]) return true;
        if(b < S.s[m]){
            f = m-1; // mover o final do intervalo pra frente
        }
        else{
            i = m+1; // mover o inicio do intervalo pra frente
        }
    } 
    return false;
}
bool adicionar (set &S, char b){
 if (vazia(S)) {
        S.s[0] = b;
        S.n++;
        return true;
    }
    if (cheia(S)) {
        return false;
    }

    int i = 0;
    // Encontra a posição correta para inserir o novo elemento
    while (i < S.n && S.s[i] < b) {
        i++;
    }

    // Move os elementos maiores para abrir espaço para o novo elemento
    for (int j = S.n - 1; j >= i; j--) {
        S.s[j + 1] = S.s[j];
    }

    // Insere o novo elemento na posição correta
    S.s[i] = b;
    S.n++;
    return true;
}

bool adicionar_testado (set &S, char b){
    if(pertence(S,b)) {
        return false;
    }
    else{
        adicionar(S,b);
        return true;
    }
}
bool remover(set &S, char b){
    int i = 0 , f = S.n-1; // i e f representam respectivamente a posição inicio e final na qual o vetor vai percorrer
    while(i<=f){
        int m = (i + f)/2;
        if(b == S.s[m]) {
            for (int j = m; j<S.n-1; j++){
                S.s[j] = S.s[j+1];
            }
            S.n = S.n - 1;
            return true;
        }
        if(b < S.s[m]){
            f = m-1;
        }
        else{
            i = m+1;
        }
    } 
    return false;
}
int main(){
    set s;
    iniciializar(s);
    if (adicionar(s,'a')){
       std:: cout << "adicionado"<< endl;   
    }
    else std::cout << "erro";

    if (adicionar(s,'c')){
       std:: cout << "adicionado"<< endl;   
    }
    else std::cout << "erro"<< endl;

    if (adicionar(s,'b')){
       std:: cout << "adicionado"<< endl;   
    }
    else std::cout << "erro"<< endl;

     for (int i = 0; i<5;i++){
        cout << s.s[i] << endl;
    }

    if(pertence(s,'a')) cout << "pertence"<<endl ;
    else cout << "nao pertence" ;

    if(remover(s,'a')) cout << "removido"<<endl ;
    else cout << "nao removido" ;

    if(vazia(s)) cout << "vazia"<<endl ;
    else cout << "nao vazia"<< endl ;

    for (int i = 0; i<5;i++){
        cout << s.s[i] << endl;
    }
    cout << s.n;

     if (adicionar(s,'d')){
       std:: cout << "adicionado"<< endl;   
    }
    else std::cout << "erro"<< endl;

    if (adicionar(s,'a')){
       std:: cout << "adicionado"<< endl;   
    }
    else std::cout << "erro"<< endl;
    for (int i = 0; i<5;i++){
        cout << s.s[i] << endl;
    }
}