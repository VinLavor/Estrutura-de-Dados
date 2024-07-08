#include<iostream>
#include<string>
using namespace std;

struct pilha_num{
    static constexpr int tam = 10;
    double vetor[tam];
    int numero = 0;
};

struct pilha_ope{
    static constexpr int tam = 10;
    std :: string vetor[tam];
    int numero = 0;
};

bool empilhar_num(pilha_num &P, double d){
 P.vetor[P.numero] = d;
 P.numero ++;
 return true;
}

bool empilhar_ope(pilha_ope &P, char s){
 P.vetor[P.numero] = s;
 P.numero ++;
 return true;
}

double desempilhar_num(pilha_num &P){
 double resultado = P.vetor[P.numero - 1];
 P.numero --;
 return resultado;
}

bool pilhas_operacao(pilha_num &N, pilha_ope &O){
    double num1, num2, res;
    string operacao = O.vetor[O.numero - 1];

    num2 = desempilhar_num(N);
    num1 = desempilhar_num(N);

if (operacao == "+") res = num1 + num2; 
else if(operacao == "-") res = num1 - num2;
else if(operacao == "*") res = num1 * num2;
else if(operacao == "/") res = num1 / num2;

O.numero --;

empilhar_num(N, res);

return true;
}


main(){
    pilha_num num;
    pilha_ope ope;
    double numero = 0;
    string str;
    char compara;
    int i = 0;


std:: cout << "digite sua expressão: " << endl;
getline(cin, str);

while(i < str.length()){
    compara = str[i];
    if ((compara >= '0') and (compara<='9')){
       numero = numero * 10 + (compara - '0'); // recebe a string e converte em double
    }
    else if (compara =='+' || compara == '-' || compara == '*' || compara == '/'){
        empilhar_num(num, numero);
        numero = 0;
        empilhar_ope(ope, compara);
    }
    if (compara == ')'){
        empilhar_num(num, numero);
        numero = 0;
        pilhas_operacao(num,ope);
    }
    i ++;
}
for(int i =0; i < 6; i++){
    cout << num.vetor[i] << endl;
}
std :: cout << desempilhar_num(num);

}