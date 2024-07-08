#include <iostream>
using namespace std ;

struct fila{
    char lista [5];
    int numero;
    int primeiro;
};

bool vazia(fila &F){
    if(F.numero == 0){
        return true;
    }
    else{
        return false;
    }
}
bool cheia(fila &F){
    if(F.numero == 5){
        return true;
    }
    else{
        return false;
    }
}

bool enfilar(fila &F, char b){
    if(cheia(F)) return false;
        
    if(vazia(F)){
        F.lista[0] = b;
        F.primeiro = 0;
        F.numero = 1;
        return true;
    }
    else{
        F.lista[(F.numero + F.primeiro) % 5] = b;
        F.numero ++;
        return true;
    }
}

bool desenfilar (fila &F){
    if(vazia(F)) return false;
    F.numero--;
    F.primeiro++;
    return true;
}


int main(){
    fila f;
 if (enfilar(f,'a')){
       std:: cout << "adicionado"<< endl;   
    }
    else std::cout << "erro";

    if (enfilar(f,'b')){
       std:: cout << "adicionado"<< endl;   
    }
    else std::cout << "erro"<< endl;

    if (enfilar(f,'c')){
       std:: cout << "adicionado"<< endl;   
    }
    else std::cout << "erro"<< endl;

     for (int i = 0; i<5;i++){
        cout << f.lista[i] << endl;
    }
    
    if (desenfilar(f)){
       std:: cout << "removido"<< endl;   
    }
    else std::cout << "erro"<< endl;
    
    if (enfilar(f,'d')){
       std:: cout << "adicionado"<< endl;   
    }
    else std::cout << "erro"<< endl;
    if (enfilar(f,'e')){
       std:: cout << "adicionado"<< endl;   
    }
    else std::cout << "erro"<< endl;
    if (enfilar(f,'f')){
       std:: cout << "adicionado"<< endl;   
    }
    else std::cout << "erro"<< endl;


     for (int i = 0; i<5;i++){
        cout << f.lista[i] << endl;
    }
}