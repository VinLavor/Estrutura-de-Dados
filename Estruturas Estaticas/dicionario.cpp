#include<iostream>
using namespace std;

struct dict{
 int chaves[5];
 std::string valor[5];
 int numero=0;
};

bool inserir(dict &D, int c, string v){
if(D.numero == 5 ){
    return false;
}
else{
    D.chaves[D.numero] = c;
    D.valor[D.numero] = v;
    D.numero++;
    return true;
}
}

 std::string verificar(dict &D, int c){
    for(int i = 0; i<D.numero; i++){
        if(D.chaves[i] == c){
            return D.valor[i];
        }
    }
    return false;
}

bool remover(dict &D, int c){
    for(int i = 0; i<D.numero; i++){
        if(D.chaves[i] == c){
            D.chaves[i] = D.chaves[D.numero];
            D.valor[i] = D.valor[D.numero];
            D.numero--;
        }
}
}



int main(){

}