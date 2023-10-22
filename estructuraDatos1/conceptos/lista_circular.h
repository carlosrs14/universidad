#include <iostream>
#include <stdlib.h>
using namespace std;
typedef struct n{
    int dato;
    struct n * sgt;
}NodoC;

NodoC * crearNodoC(int d, NodoC *s){
    NodoC * p=(NodoC *) malloc(sizeof(NodoC));
    p->dato=d;
    p->sgt=s;
    return p;
}

void insertarCab(NodoC *&cab, int d){
    NodoC * p=crearNodoC(d, NULL);
}
void insertarCola(NodoC *&cab, int d){

}