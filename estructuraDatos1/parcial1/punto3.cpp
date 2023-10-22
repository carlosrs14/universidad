#include <iostream>
using namespace std;
typedef struct nodo{
    int dato;
    struct nodo * sgt;
}Nodo;

//punto 3
void funcion3(Nodo * cab){
    int suma=0, cont=0, max, min;
    float promedio;

    for(Nodo * p = cab; p != NULL; p = p->sgt){
        suma += p->dato;
        cont++;
        if(cont == 1){
            max = p->dato;
            min = p->dato;
        }else{
            if(p->dato > max){
                max = p->dato;
            }
            if(p->dato < min){
                min = p->dato;
            }
        }
    }
    if(cont!=0){
        promedio = (float) suma/cont;
        cout<<"El numero de elementos fue: "<<cont<<endl;
        cout<<"La suma de los elementos fue: "<<suma<<endl;
        cout<<"El numero maximo fue: "<<max<<endl;
        cout<<"El numero minimo fue: "<<min<<endl;
        cout<<"El promedio fue: "<<promedio<<endl;
    }

}
int main(){
    return 0;
}