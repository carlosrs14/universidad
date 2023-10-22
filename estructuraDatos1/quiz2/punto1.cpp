#include <iostream>
#include <stack>
using namespace std;
void funcion(stack<int> &pila, int n){
    stack<int> aux;
    while(!pila.empty()){
        aux.push(pila.top());
        pila.pop();
    }
    while(!aux.empty()){
        pila.push(aux.top() * n);
        aux.pop();
    }
}

int main(){
    stack<int> pila;
    
    for(int i = 0; i < 10; i++){
        pila.push(i);
    }
    funcion(pila, 5);
    for(int i = 0; i < 10; i++){
        cout<<pila.top()<<endl;
        pila.pop();
    }
    return 0;
}