#include<iostream>
#include "deque_com_lista_encadeada.h"

using namespace std;


int main(){
Deque deque;
TipoItem item;
int opcao;

do
{
cout << "digite a operaçao que deseja fazer \n";
cout << "0: parar o programa \n";
cout << "1: adicionar um elemento a esquerda\n";
cout << "2: adicionar um elemento a direita\n";
cout << "3: remover um elemento a esquerda\n";
cout << "4: remover um elemento a direita\n";
cout << "5: ver o deque\n";

cin >> opcao;
 if (opcao == 1){
            cout << "Digite o elemento a ser inserido:\n";
            cin >> item;
            deque.inserir_esq(item);
        } else if (opcao == 2){
            cout << "Digite o elemento a ser inserido:\n";
            cin >> item;
            deque.inserir_dir(item);
        } else if (opcao == 3){
            deque.remover_esq();
        } else if(opcao == 4){
            deque.remover_dir();
        } else if(opcao == 5){
            deque.visualizar();
        }

} while (opcao != 0);




}