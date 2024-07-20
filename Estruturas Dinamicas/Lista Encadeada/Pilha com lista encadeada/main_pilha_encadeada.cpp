#include<iostream>
#include "pilha_com_lista_encadeada.h"

using namespace std;


int main(){
pilhadinamica pilha;
TipoItem item;
int opcao;

do
{
cout << "digite a operaçao que deseja fazer \n";
cout << "0: parar o programa \n";
cout << "1: adicionar um elemento\n";
cout << "2: remover um elemento\n";
cout << "3: ver a pilha\n";

cin >> opcao;
 if (opcao == 1){
            cout << "Digite o elemento a ser inserido:\n";
            cin >> item;
            pilha.empilhar(item);
        } else if (opcao == 2){
            item = pilha.desempilhar();
            cout << "Elemento Removido: " << item << endl;
        } else if (opcao == 3){
            pilha.imprimir();
        }

} while (opcao != 0);




}