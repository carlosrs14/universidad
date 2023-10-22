#include <iostream>
#include <stdlib.h>
//con pilas dinamicas
using namespace std;
typedef struct nodo{
    int dato;
    struct nodo *sgt;
} Nodo;

typedef struct pila{
    Nodo *cima;

    void inicializar(){
        cima=NULL;
    }
    void insertar(int d){
        Nodo * p=new Nodo;
        p->dato=d;
        p->sgt=cima;
        cima=p;
    }
    
    bool vacia(){
        return cima==NULL;
    }
    int datoCima(){
        if(!vacia()){
            return cima->dato;
        }
        return NULL;
    }

    int quitar(){
        if(!vacia()){
            int aux=cima->dato;
            Nodo *ptraux=cima;
            cima=cima->sgt;
            delete(ptraux);
            return aux;
        }
        cout<<"La pila está vacía (underflow)"<<endl;
        return NULL;
    }

    void vaciarPila(){
        while(!vacia()){
            quitar();
        }
    }
    void imprimir(){
        for(Nodo *iter=cima; iter!=NULL; iter=iter->sgt){
            cout<<"["<<iter->dato<<"]"<<endl;
        }
    }

    int contar(){
        int cont=0;
        for(Nodo * iter= cima; iter!=NULL; iter= iter->sgt){
            cont++;
        }
        return cont;
    }
}Pila;

void organizar(Pila torre1, Pila aux, Pila torre2){
    if(aux.cima==NULL && torre1.contar() == 2){
        
        //terminado
        aux.insertar(torre1.quitar());
        torre2.insertar(torre1.quitar());
        torre2.insertar(aux.quitar());
        
        cout<<endl<<"Torre2: "<<endl;
        torre2.imprimir();
        cout<<"terminado"<<endl;
    
    
    }else{
        cout<<"Aún no se termina"<<endl;


        organizar(torre1, aux, torre2);
          
    }
}

void torreHanoi(int ncapas){

    Pila torre1, aux, torre2;
    torre1.inicializar(); aux.inicializar(); torre2.inicializar();
    
    for(int i = ncapas; i > 0; i--){
        torre1.insertar(i);
    }
    organizar(torre1, aux, torre2);

}




int main(){
    int ncapas;
    cout<<"Ingrese el número de capas: ";cin>>ncapas;
    torreHanoi(ncapas);

    cout<<"\n\n\n\n";
    return 0;
}