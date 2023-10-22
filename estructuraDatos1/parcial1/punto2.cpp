#include <iostream>
using namespace std;
//lista circular
typedef struct nc{
    int dato;
    struct nc *sgt;
}NodoC;

void eliminarPos(NodoC * cab, int pos){
    NodoC *ant = cab;
    int cont=1;
    for(NodoC *p = cab->sgt; p != cab; p = p->sgt){
        if(cont == pos){
            ant->sgt = p->sgt;
            delete p;
            return;
        }
        cont ++;
        ant = p;
    }
    if(pos == 0 && cab != NULL){
        ant->sgt = cab->sgt;
        delete cab;
        cab = ant->sgt;
    }
}

int main(){

    return 0;
}