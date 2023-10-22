#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct p{
    int *v, tam, cima;

    void inicializar(int n){
        tam=n;
        cima=-1;
        v=(int *) malloc(tam * sizeof(int));
    }
    bool llena(){
        return cima==(tam-1);
    }
    bool vacia(){
        return cima==-1;
    }
    void insertar(int d){
        if(!llena()){
            v[++cima]=d;
        }else{
            cout<<"Overflow"<<endl;
        }
    }
    int quitar(){
        if(!vacia()){
            return v[cima--];
            
        }else{
            cout<<"Underflow"<<endl;
            return NULL;
        }
    }
    void imprimir(){
        for(int i= cima; i>=0; i--){
            cout<<"["<<v[i]<<"]";
        }
        cout<<endl;
    }
    int datoCima(){
        if(!vacia()){
            return v[cima];
        }else{
            cout<<"Pila vacía"<<endl;
        }
    }
    void vaciarPila(){
        while(!vacia()){
            quitar();
        }
    }
}Pila;