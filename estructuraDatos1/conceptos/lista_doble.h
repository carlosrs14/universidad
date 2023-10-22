#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct n{
    int dato;
    struct n *ant;
    struct n *sgt;
}NodoD;

NodoD * crearNodoD(NodoD * a, int d, NodoD * s){
    NodoD * p=(NodoD *) malloc(sizeof(NodoD));
    p->ant=a;
    p->dato=d;
    p->sgt=s;
    return p;
}

void insertarCab(int d, NodoD *&cab){
    NodoD *p =crearNodoD(NULL, d, cab);
    if(cab!=NULL)
        cab->ant=p;
    cab=p;
    
}

void insertarCola(NodoD *&cab, int d){
    NodoD * nuevo=crearNodoD(NULL, d, NULL);
    if(cab==NULL){
        cab=nuevo;
    }else{
        NodoD* p=cab;
        for(;p->sgt!=NULL; p=p->sgt);
        p->sgt=nuevo;
        nuevo->ant=p;
    }
}

void imprimir(NodoD *p){
    cout<<"NULL<=>";
    for(;p->sgt!=NULL; p=p->sgt)
        cout<<"["<<p->dato<<"]<=>";
    
    cout<<"["<<p->dato<<"]<=>NULL"<<endl<<"NULL<=>";
    for(;p!=NULL; p=p->ant)
        cout<<"["<<p->dato<<"]<=>";
    
    cout<<"NULL"<<endl;
}

NodoD * buscar(NodoD * p, int d){
    for(; p!=NULL; p=p->sgt)
        if(p->dato==d)
            return p;
    return NULL;
}

void insertarAntes(NodoD *&cab, int di, int db){
    NodoD *p = buscar(cab, db);
    if(p!=NULL){
        p->ant=crearNodoD(p->ant, di, p);
        if(p!=cab)
            p->ant->ant->sgt=p->ant;

    }else
        cout<<"No se encontró el dato"<<endl;
}
void insertarDespues(NodoD *&cab, int db, int di){
    NodoD *p = buscar(cab, db);
    if(p!=NULL){
        p->sgt=crearNodoD(p, di, p->sgt);
        if(p->sgt->sgt!=NULL)
            p->sgt->sgt->ant=p->sgt;

    }else
        cout<<"No se encontró el dato"<<endl;
}

int contarRepeticiones(NodoD *p, int d){
    int cont=0;
    for(;p!=NULL;p=p->sgt)
        if(p->dato==d)
            cont++;
    return cont;
}
bool eliminar(NodoD *&cab, int d){
    NodoD * p= buscar(cab, d);
    if(p!=NULL){
        if(p==cab){
            cab=cab->sgt;
        }
        if(p->ant!=NULL)
            p->ant->sgt=p->sgt;
        if(p->sgt!=NULL)
            p->sgt->ant=p->ant;
        delete(p);
        return true;
    }else
        return false;
}

void eliminarTodasApariciones(NodoD *&cab, int d){
    while(eliminar(cab, d));
}