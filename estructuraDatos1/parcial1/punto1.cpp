#include <string.h>
#include <iostream>
using namespace std;
typedef struct a{
   string nombre;
   int edad;
   char genero;
   struct a *sgt;
   struct a *ant;
}Alumno;


void intercalar(Alumno * cab){
    for(Alumno * a = cab; a->sgt != NULL; a = a->sgt){
        if(a->genero == a->sgt->genero){
            for(Alumno * b = a->sgt->sgt; b!=NULL; b = b->sgt){
                if(b->genero != a->genero){
                    b->ant->sgt = b->sgt;
                    b->sgt->ant = b->ant;
                    
                    b->sgt = a->sgt;
                    a->sgt->ant=b;

                    b->ant = a;
                    a->sgt =b;
                }
            }
        }

    }
}

int main(){
    return 0;
}