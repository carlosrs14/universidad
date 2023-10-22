#include <iostream>

using namespace std;

double potencia(float base, int exponente){
    if(exponente <0 && base != 0){
        return 1/potencia(base, -exponente);
    }

    if(exponente==0 && base!=0){
        return 1;
    }

    if(exponente==1){
        return base;
    }

    if(exponente%2 != 0 && exponente > 1){
        return base * potencia(base, exponente-1);
    }else{
        double aux=potencia(base, exponente/2);
        return aux*aux;
    }
    //indeterminado
    return NULL;

}

int main(){

    cout<<potencia(2,-4)<<endl;;
    return 0;
}