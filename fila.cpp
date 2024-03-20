#include <iostream>
using namespace std ;

struct fila{
    char lista [5];
    int p,u;
};

void inicializar(fila &F)
{
F.p = -1;
}

bool vazia(fila &F)
{
 if (F.p == -1){
    return true;
 }
 else return false;
}

bool cheia(fila &F)
{
 if ((F.p == F.u + 1) or (F.p == 0 and F.u == 4))
 {
  return true;
 }
 else return false;
}
bool enfileirar(fila &F, char d)
{
 if(cheia(F)) return false;

 if (F.p == -1){
    F.p = F.u = 0;
}
 else
 {
    if(F.u == 4) F.u = 0;
    else ++F.u;
 }
 F.lista[F.u] = d;
 return true;
}

char primeiro (fila &F)
{
 return F.lista[F.p];
}

bool desenfilar(fila &F)
{
    if(F.p == -1) return false;
    if(F.p == F.u) F.p = -1;
    else
    {
    F.lista[F.p] = ' ';
    F.p = (F.p + 1) % 5;
    }
    return true;
}
int main()
{
    fila f ;
    inicializar(f);
    


}
