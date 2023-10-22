#include <iostream>
#include <stdlib.h>
using namespace std;
typedef struct n{
    int dato;
    struct n * sgt;
}Nodo;
typedef struct c{
    Nodo * fr, *fin;
    void inicializar(){
        fr=NULL;
        fin=NULL;
    }
    bool vacia(){
        return fr==NULL;
    }
    void insertar(int d){
        Nodo * p= (Nodo *) malloc(sizeof(Nodo));
        p->dato=d;
        p->sgt=NULL;
        if(vacia()){
            fr=p;
            fin=p;
        }else{
            fin->sgt=p;
            fin=p;
        }
    }
    int quitar(){
        if(!vacia()){
            Nodo * p=fr;
            int aux=fr->dato;
            fr=fr->sgt;
            delete(p);
            return aux;
        }
        cout<<"Underflow"<<endl;
        return NULL;
    }
    int datoFrente(){
        if(!vacia())
            return fr->dato;
        cout<<"Cola vacía"<<endl;
        return NULL;
    }
    void vaciar(){
        while(!vacia()){
            quitar();
        }
    } 
    int tam(){
        int cont=0;
        for(Nodo *p=fr; p!=NULL; p=p->sgt)
            cont++;
        return cont;
    }
    void imprimir(){
        for(Nodo *p=fr; p!=NULL; p=p->sgt)
            cout<<"["<<p->dato<<"]";
        cout<<endl;
    }
}Cola;