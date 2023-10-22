#include <iostream>
#include <stdlib.h>
#include "listasCirculares.h"
using namespace std;

int main(){

    Nodo * cab=NULL;

    insertarCab(cab, 15);
    insertarCab(cab, 16);
    insertarCab(cab, 17);
    insertarCab(cab, 18);
    insertarCab(cab, 19);
    imprimir(cab);
    eliminar(cab, 19);
    imprimir(cab);
    //cout<<cab->sgt->dato<<endl<<endl;
    return 0;
}