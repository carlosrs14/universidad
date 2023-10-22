#include <iostream>
#include <stdlib.h>

using namespace std;

struct NodoD{
    int dato;
    struct NodoD * ant;
    struct NodoD * sgt;
};
void insertarCab(NodoD **cab, int d){
    NodoD * nuevo = new NodoD;
    if(*cab != NULL){
       (*cab)->ant=nuevo;
    }
   
    nuevo->ant=NULL;
    nuevo->sgt=*cab;
    nuevo->dato=d;
    
    *cab=nuevo;
}

void insertarCola(NodoD **cab, int d){
    NodoD * nuevo = new NodoD;
    nuevo->dato=d;
    nuevo->sgt=NULL;

    if(*cab==NULL){
        nuevo->ant=NULL;
        *cab=nuevo;
    }else{
        NodoD * p=*cab;
        for(; p->sgt != NULL; p=p->sgt);
        p->sgt=nuevo;
        nuevo->ant=p;
    }
}

void imprimir(NodoD *cab){
    NodoD * p=cab;
    for(; p->sgt!=NULL; p=p->sgt){
        cout<<"["<<p->dato<<"]<=>";
    }
    cout<<"["<<p->dato<<"]<=>NULL"<<endl;

    for(; p!=NULL; p=p->ant){
        cout<<"["<<p->dato<<"]<=>";
    }
    cout<<"NULL"<<endl;
}

void eliminarPrimera(NodoD **cab, int d){
    for(NodoD * p=*cab; p!=NULL; p=p->sgt){
        if(p->dato==d){
            if(p != *cab)
                p->ant->sgt=p->sgt;
            if(p->sgt != NULL)    
                p->sgt->ant=p->ant;
            
            if(p == *cab)
                *cab=(*cab)->sgt;
            
            delete(p);
            return;
        }
    }
    cout<<"Dato no encontrado"<<endl;

}
//falta validar un caso
void eliminarTodas(NodoD **cab, int d){
    NodoD * ant=NULL;
    for(NodoD * p=*cab; p!=NULL; p=p->sgt){

        if(p->dato==d){
            if(p != *cab)
                p->ant->sgt=p->sgt;
            if(p->sgt != NULL)    
                p->sgt->ant=p->ant;
            if(p == *cab)
                *cab=(*cab)->sgt;
            delete(p);
            p=ant;
        }
        ant=p;
    }
}

NodoD * buscar(NodoD *p, int d){
    for(;p!=NULL; p=p->sgt){
        if(p->dato==d){
            cout<<"Dato encontrado"<<endl;
            return p;
        }
    }
    cout<<"Dato NO encontrado"<<endl;
    return NULL;
}
int main(){

    NodoD * cab=NULL;
    
    int opcion, dato;

    do{
        cout<<"1 - Insertar por cabeza"<<endl;
        cout<<"2 - Insertar por cola"<<endl;
        cout<<"3 - eliminar primera aparicion"<<endl;
        cout<<"4 - eliminar todas las apariciones"<<endl;
        cout<<"5 - buscar un dato "<<endl;
        cout<<"6 - imprimir lista"<<endl;
        cout<<"0 - salir"<<endl;
        cout<<"Ingrese su opción: ";
        cin>>opcion;

        switch (opcion){
            case 1 :{
                cout<<"Ingrese el número a insertar: "<<endl;
                cin>>dato;
                insertarCab(&cab, dato);
                break;
            }
            case 2 :{
                cout<<"Ingrese el número a insertar: "<<endl;
                cin>>dato;
                insertarCola(&cab, dato);
                break;
            }
            case 3 :{
                cout<<"Ingrese el dato a eliminar: "<<endl;
                cin>>dato;
                eliminarPrimera(&cab, dato);
                break;
            }
            case 4 :{
                cout<<"Ingrese el dato a eliminar: "<<endl;
                cin>>dato;
                eliminarTodas(&cab, dato);
                break;
            }
            case 5 :{
                cout<<"Ingrese el dato a buscar: "<<endl;
                cin>>dato;
                buscar(cab, dato);
                break;
            }
            case 6 :{
                imprimir(cab);
                break;
            }
            
        }
        system("pause");
        system("cls");

    }while(opcion!=0);
    cout<<"Fin del programa"<<endl;
    return 0;
}