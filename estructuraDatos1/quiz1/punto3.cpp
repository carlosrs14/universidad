#include <iostream>
using namespace std;

typedef struct nodo{
    int dato;
    struct nodo * ant;
    struct nodo * sgt;
}Nodo;

void eliminarListaDoble(Nodo *&cab, int dato){
    for(Nodo * p = cab; p != NULL; p = p->sgt){
        if(p->dato==dato){
            if(p != cab)
                p->ant->sgt = p->sgt;
            if(p->sgt != NULL)
                p->sgt->ant = p->ant;
            if(p == cab)
                cab = cab->sgt;
            
            delete p;
        }
    }
}
int main(){
    return 0;
}