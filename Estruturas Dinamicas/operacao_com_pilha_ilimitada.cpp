#include<iostream>
#include<cstring>
using namespace std;

struct Pilha_Numeros{
    int* array;
    int num_elementos = 0;
    int tamanho;
};

struct Pilha_Operadores{
    char* array;
    int num_elementos = 0;
    int tamanho;
};

void inicializar_pilhas(Pilha_Numeros& pilha_num, Pilha_Operadores& pilha_op, int tamanho){
    pilha_num.array = new int[tamanho];
    pilha_op.array = new char[tamanho];
    pilha_num.tamanho = tamanho;
    pilha_op.tamanho = tamanho;
}

void redimensionar_num(Pilha_Numeros& pilha){
    int novo_tamanho = pilha.tamanho * 2;
    int *novo_array = new int[novo_tamanho];

    for(int i = 0; i < pilha.tamanho; i++){
        novo_array[i] = pilha.array[i];
    }
    delete[] pilha.array;

    pilha.array = novo_array;
    pilha.tamanho = novo_tamanho;
}

void redimensionar_op(Pilha_Operadores& pilha){
    int novo_tamanho = pilha.tamanho * 2;
    char *novo_array = new char[novo_tamanho];

    for(int i = 0; i < pilha.tamanho; i++){
        novo_array[i] = pilha.array[i];
    }
    delete[] pilha.array;

    pilha.array = novo_array;
    pilha.tamanho = novo_tamanho;
}

void empilhar_num(Pilha_Numeros &pilha, int numero){
    if(pilha.num_elementos == pilha.tamanho){
        redimensionar_num(pilha);
    }
    
    pilha.array[pilha.num_elementos] = numero;
    pilha.num_elementos++;
}

void empilhar_op(Pilha_Operadores& pilha, char operador){
    if(pilha.num_elementos == pilha.tamanho){
        redimensionar_op(pilha);
    }
    
    pilha.array[pilha.num_elementos] = operador;
    pilha.num_elementos++;
}

int desempilhar_num(Pilha_Numeros& pilha){
    pilha.num_elementos--;
    return pilha.array[pilha.num_elementos];
}

char desempilhar_op(Pilha_Operadores& pilha){
    pilha.num_elementos--;
    return pilha.array[pilha.num_elementos];
}

void operacao(Pilha_Numeros& pilha_num, Pilha_Operadores& pilha_op){
    int num1, num2, res;
    char operador = desempilhar_op(pilha_op);

    num2 = desempilhar_num(pilha_num);
    num1 = desempilhar_num(pilha_num);

    if(operador == '+')      res = num1 + num2;
    else if(operador == '-') res = num1 - num2;
    else if(operador == '*') res = num1 * num2;
    else if(operador == '/') res = num1 / num2;

    empilhar_num(pilha_num, res);
}

int main(){
    Pilha_Numeros pilha_num;
    Pilha_Operadores pilha_op;

    string expressao;
    char comparador;
    int numero;
    int i = 0;

    inicializar_pilhas(pilha_num, pilha_op, 5);

    cout << "Digite a sua expressao: " << endl;
    getline(cin, expressao);

    while(i < expressao.length()){
        comparador = expressao[i];

        if(comparador >= '0' && comparador <= '9'){
            numero = comparador - '0';
            empilhar_num(pilha_num, numero);
        }
        else if(comparador == '+' || comparador == '-' || comparador == '*' || comparador == '/'){
            empilhar_op(pilha_op, comparador);
        }
        else if(comparador == ')'){
            operacao(pilha_num, pilha_op);
        }

        i++;
    }

    cout << "Resultado: " << pilha_num.array[pilha_num.num_elementos - 1] << endl;

  
    delete[] pilha_num.array;
    delete[] pilha_op.array;

    return 0;
}