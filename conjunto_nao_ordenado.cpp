#include <iostream>
using namespace std;

struct set
{
char s [5];
int n = 0;
};

bool cheia(set &S){
    if(S.n == 5) return true;
    else return false ;
}
bool vazia(set &S){
    if(S.n == 0) return true;
    else return false ;
}
bool pertence(set &S, char b){
    for(int i=0; i < S.n; i++){
        if(S.s[i] == b) return true;
    }
   return false;
}
bool adicionar (set &S, char b){
    if(S.n == 5){
     return false;
    }
    else{
        S.s[S.n] = b;
        S.n++;
        return true;
    }
     
}
bool adicionar_testado(set &S, char b){
    if(pertence(S,b)){
        return false;
    } 
    else{
        adicionar(S,b);
    }
}

bool remover(set &S, char b){
      for(int i=0; i < S.n; i++){
        if(S.s[i] == b){;
         S.s[i] = S.s[S.n-1];
         S.n--;
         return true;
    }
      }
   return false;
}

int main(){
     set s;
    if (adicionar(s,'b')){
       std:: cout << "adicionado"<< endl;   
    }
    else std::cout << "erro";

    if(pertence(s,'b')) cout << "pertence"<<endl ;
    else cout << "nao pertence" ;

    if(remover(s,'b')) cout << "removido"<<endl ;
    else cout << "nao removido" ;

    if(vazia(s)) cout << "vazia"<<endl ;
    else cout << "nao vazia" ;
}