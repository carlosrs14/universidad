#include "cola_dinamica.h"
#include "pila_dinamica.h"
#include <iostream>
using namespace std;

// 1  4  4  5  6  7         9
//1 vector
Pila encontrarSumas(int vec[], int n){
    Pila p1;
    p1.inicializar();
    for(int i=0; i<sizeof(vec)-1;i++){
        for(int j=i+1; j<sizeof(vec);j++){
            if(vec[i]+vec[j]==n){
                int v[]={i,j};//si es por indice 
                int v[]={vec[i],vec[j]};//si es por valor
                p1.insertar(v);
            }
        }
    }
    return p1;
}

//2 bicola
void ingresarPaciente(Cola c, int edad){
    if(!c.vacia() && edad>=60){
        Pila aux;
        aux.inicializar();
        while(edad <= c.datoFrente()){
            aux.insertar(c.quitarFrente());
        }
        c.insertarFrente(edad);
        while(!aux.vacia()){
            c.insertarFrente(aux.quitar());
        }
        
    }else{
        c.insertarCola(edad);
    }
}

//3 matriz
Cola matriz(int n, int matriz[][]){
    Cola c;
    c.inicializar();
    int i=0, j=0;   
         //i        //j==n-1
    while(i<n-1 || j<n-1){
        if(i==n-1){
            j++;
            c.insertar(matriz[i][j]);
        }else{
            if(j==n-1){
                i++;
                c.insertar(matriz[i][j]);
            }else{
                if(matriz[i+1][j]<matriz[i][j+1]){
                    c.insertar(matriz[++i][j]);
                }else{
                    c.insertar(matriz[i][++j]);
                }
            }
        }
    }
    return c;
}

int main(){
    int vect[5];
    cout<<vect<<endl<<endl;
    return 0;
}

