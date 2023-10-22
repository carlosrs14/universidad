#include <iostream>
using namespace std;
typedef struct nodo{
    int dato;
    struct nodo * sgt;
    struct nodo * ant;
}Nodo;
void ordenarListaDoble(Nodo *&cab){
    for(Nodo * p = cab; p != NULL; p = p->sgt){
        Nodo * ant=NULL;
        for(Nodo * q = cab; q->sgt != NULL; q = q->sgt){
            if(q->sgt->dato < q->dato){
                //intercambio
                ant->sgt = q->sgt;
                q->sgt->sgt = q;
                q->sgt = q->sgt->sgt;
                
            }
            ant=q;
        }
    }
    
}

int main(){
    return 0;
}