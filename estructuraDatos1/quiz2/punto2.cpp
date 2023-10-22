#include <iostream>
#include <stack>
using namespace std;
int funcion(stack<int> &pila, int n){
    int valor  = -1;
    if(n <= pila.size() && n > 0){
        stack<int> aux; int cont = 1;
        
        while(cont++ != n){
            aux.push(pila.top());
            pila.pop();
        }
        valor = pila.top();
        while(!aux.empty()){
            pila.push(aux.top());
            aux.pop();
        }

    }else{
        cout<<"El parámetro 1 es mayor que el tamano de la lista o menor que 1"<<endl;
    }
    return valor;
}

int main(){
    stack<int> pila;
    for(int i = 0; i < 10; i++){
        pila.push(i);
    }
    cout<<funcion(pila, 0)<<endl;
    return 0;
}