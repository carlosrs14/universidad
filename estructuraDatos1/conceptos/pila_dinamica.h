#include <iostream>
#include <stdlib.h>
using namespace std;
typedef struct n{
    int dato;
    struct n *sgt;
}Nodo;
typedef struct p{
    Nodo * cima;
    void inicializar(){
       cima=NULL; 
    }
     bool vacia(){
        return cima==NULL;
    }
    void insertar(int d){
        Nodo * p= (Nodo *) malloc(sizeof(Nodo));
        p->dato=d;
        p->sgt=cima;
        cima = p;
    }
    int quitar(){
        if(!vacia()){
            Nodo * p= cima;
            int aux=cima->dato;
            cima=cima->sgt;
            delete(p);
            return aux;

        }
        cout<<"Underflow"<<endl;
        return NULL;
    }
    void vaciarPila(){
        while(!vacia()){
            quitar();
        }
    }
    int datoCima(){
        if(!vacia())
            return cima->dato;
        return NULL;
    }
    int tam(){
        int cont=0;
        for(Nodo * p= cima; p!=NULL; p=p->sgt)
            cont++;
        return cont;
    }
    void imprimr(){
        for(Nodo * p= cima; p!=NULL; p=p->sgt)
            cout<<"["<<p->dato<<"]";
        cout<<endl;
    }
}Pila;