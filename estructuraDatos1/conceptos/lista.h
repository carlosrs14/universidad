#include <iostream>
#include <stdlib.h>
#include <locale.h>
using namespace std;
typedef struct n{
    int dato;
    struct n *sgt;
}Nodo;
Nodo * crearNodo(int d, Nodo * s){
    Nodo * p=(Nodo *) malloc(sizeof(Nodo));
    p->dato=d;
    p->sgt=s;
    return p;
}
typedef struct l{
    Nodo * cab;
    void inicializar(){
        cab=NULL;
    }
    void insertarCab(int d){
        cab=crearNodo(d, cab);
    }
    bool vacia(){
        return cab==NULL;
    }
    void insertarCola(int d){
        Nodo*q=crearNodo(d, NULL);
        if(cab==NULL){
            cab=q;
        }else{
            Nodo *p=cab;
            for(;p->sgt!=NULL; p=p->sgt);
            p->sgt=q;
        }
    }
    void imprimir(){
        for(Nodo *p=cab;p!=NULL; p=p->sgt)
            cout<<"["<<p->dato<<"]->";
        cout<<"NULL"<<endl;
    }
    Nodo * buscar(int d){
        for(Nodo *p=cab;p!=NULL; p=p->sgt)
            if(p->dato==d)
                return p;
        return NULL;
    }
    int contarRepeticiones(int d){
        int cont = 0;
        for(Nodo * p=cab; p!=NULL; p=p->sgt)
            if(p->dato==d)
                cont++;
        return cont;
    }
    void insertarAntes(int db, int di){
        Nodo * ant=NULL;
        for(Nodo * p=cab; p!=NULL; p=p->sgt){
            if(p->dato==db){
                if(p==cab)
                    cab=crearNodo(di, cab);
                else
                    ant->sgt=crearNodo(di, p);
                return;
            }
            ant=p;
        }
        cout<<"No se encontró el dato"<<endl;

    }
    void insertarDespues(int db, int di){
        for(Nodo *p=cab; p!=NULL; p=p->sgt){
            if(p->dato==db){
                p->sgt=crearNodo(di, p->sgt);
                return;
            }
        }
        cout<<"No se encontró el dato"<<endl;
    }   
    bool eliminar(int d){
        Nodo * ant=NULL;
        for(Nodo *p=cab; p!=NULL; p=p->sgt){
            if(p->dato==d){
                if(p==cab)
                    cab=cab->sgt;
                else
                    ant->sgt=p->sgt;
                delete(p);
                return true;
            }
            ant=p;
        }
        return false;
    }
    void eliminarTodasApariciones(int d){
        while(eliminar(d));
    }
}Lista;