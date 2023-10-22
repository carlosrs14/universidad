#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef char tdato1;
typedef struct n{
    tdato1 dato;
    struct n * sgt;
}Nodo_char;
typedef struct p{
    Nodo_char * cima;
    void inicializar(){
        cima=NULL;
    }
    void insertar(int d){
        Nodo_char * p=(Nodo_char *)malloc(sizeof(Nodo_char));
        p->dato=d;
        p->sgt=cima;
        cima=p;
    }
    void imprimir(){
        for(Nodo_char * p=cima; p!=NULL; p=p->sgt){
            cout<<"["<<p->dato<<"]->";
        }
        cout<<"NULL"<<endl;
    }
    bool vacia(){
        return cima==NULL;
    }
    tdato1 quitar(){
        if(!vacia()){
            tdato1 aux=cima->dato;
            Nodo_char * p=cima;
            cima=cima->sgt;
            delete(p);
            return aux;
        }
        return NULL;
    }
    void vaciarPila(){
        while(!vacia())
            quitar();
    }
    tdato1 datoCima(){
        if(!vacia())
            return cima->dato;
        return NULL;
    }
}Pila_char;


void posFija(char exp[10]){
    int tam = strlen(exp), i, j=0;
    
    tdato1 pos[tam];
    Pila_char p1;
    
    
    p1.inicializar();
    for(i=0; i<tam; i++){
        if(exp[i]>='a' && exp[i]<='z'){
            pos[j]=exp[i];
            j++;
        }else{
            //un operador entra en el vector final solo si
            //la pila esta vacía
            //el operador tiene igual o mayor prioridad

            if(p1.vacia()){
                pos[j]=exp[i];
            }
        }
    }
    
    
    i=0;
    while(!p1.vacia()){
        pos[j]=p1.quitar();
        j++;
    }
    
    
    
    cout<<pos<<endl;
}

int main(){
    char expresion[50];
    cout<<"Ingrese una expresión: ";
    cin>>expresion;

    posFija(expresion);
    return 0;
}

//(a+b)/c
//ab+c/

//a+b/c
//abc/+