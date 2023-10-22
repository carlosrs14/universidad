#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct n{  
    int fila;
    int columna;
    int dato;
    struct n * sgt;

}Nodo;


void insertarCab(Nodo *&cab, int f, int c, int d){
    Nodo * p= (Nodo *) malloc(sizeof(Nodo));
    p->columna=c;
    p->dato=d;
    p->fila=f;
    p->sgt=cab;
    cab=p;
}

void imprimir(Nodo * p){
    cout<<" f  c  d"<<endl;
    for(; p!=NULL; p=p->sgt){
        cout<<"["<<p->fila<<"]["<<p->columna<<"]["<<p->dato<<"]"<<endl;
    }
}

Nodo * hallarTranspuesta(Nodo * cabeza){
    Nodo * cabezaTranspuesta=NULL;
    for(Nodo * iter=cabeza; iter!=NULL; iter=iter->sgt){
        Nodo * nuevo=new Nodo;
        nuevo->dato = iter->dato;
        nuevo->fila = iter->columna;
        nuevo->columna = iter->fila;
        if(cabezaTranspuesta == NULL){
            cabezaTranspuesta=nuevo;
        }else{
            Nodo * iterTranspuesta=cabezaTranspuesta, *ant=NULL;
            for(;iterTranspuesta!=NULL && nuevo->fila >= iterTranspuesta->fila; iterTranspuesta=iterTranspuesta->sgt){
                ant=iterTranspuesta;
            }
            nuevo->sgt=iterTranspuesta;
            if(ant!=NULL){
                ant->sgt=nuevo;
            }
            else{
                cabezaTranspuesta=nuevo;
            }    
        }
    }
    imprimir(cabezaTranspuesta);
    return cabezaTranspuesta;
}

int main(){
    Nodo * cab=NULL;
    insertarCab(cab, 7,1,0);
    insertarCab(cab, 5,1,0);
    insertarCab(cab, 4,2,0);
    insertarCab(cab, 3,4,0);
    insertarCab(cab, 2,5,0);
    insertarCab(cab, 1,3,0);
    insertarCab(cab, 1,1,0);
    imprimir(cab);

    hallarTranspuesta(cab);
    return 0;
}