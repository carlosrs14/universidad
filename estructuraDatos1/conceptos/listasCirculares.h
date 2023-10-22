#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct nodo{
    int dato;
    struct nodo *sgt;
}Nodo;

Nodo * crearNodo(int d, Nodo * s){
    Nodo * p = (Nodo *) malloc(sizeof(Nodo));
    p->dato=d;
    p->sgt=s;
    return p;
}

void insertarCab(Nodo *&cab, int d){
    Nodo * p = crearNodo(d, NULL);
    p->sgt=p;
    if(cab!=NULL){
        p->sgt=cab->sgt;
        cab->sgt=p;

    }
    cab=p;
}

void imprimir(Nodo *cab){
    Nodo *p;
    for(p=cab->sgt; p!=cab; p=p->sgt){
        cout<<"["<<p->dato<<"]->";        
    }
    cout<<"["<<p->dato<<"]->"<<endl;
}

void eliminar(Nodo *&cab, int d){
    Nodo *p=cab->sgt, *ant=cab;
    
    for(;p!=cab; p=p->sgt){
        if(p->dato==d){
            ant->sgt=p->sgt;
            delete(p);
            cout<<"Eliminado"<<endl;
            return;
        }
        ant=p;
    }
    if(d==cab->dato){
        ant->sgt=p->sgt;
        cab=p->sgt;
        delete(p);
        cout<<"Eliminado"<<endl;
        return;
    }
    cout<<"No se encontró el dato;"<<endl;

}