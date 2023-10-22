#include <iostream>
#include <queue>
using namespace std;
void funcion(queue<char> cola1, queue<char> cola2){
    cout<<"C1-C2"<<endl;
    while(!cola1.empty() && !cola2.empty()){
        if(cola1.front() != cola2.front()){
            cout<<cola1.front()<<" - "<<cola2.front()<<endl;
        }
        cola1.pop();
        cola2.pop();
    }
    while(!cola1.empty()){
        cout<<cola1.front()<<" -"<<endl;
        cola1.pop();
    }
    while(!cola2.empty()){
        cout<<"  - "<<cola2.front()<<endl;
        cola2.pop();
    }
}
int main(){
    queue<char> cola1, cola2;
    cola1.push('1');
    cola1.push('e');
    cola1.push('r');
    cola1.push('w');
    cola1.push('1');
    cola1.push('d');
    cola1.push('a');
    cola1.push('0');
    cola1.push('*');
    cola1.push('{');
    cola1.push('.');

    cola2.push('3');
    cola2.push('e');
    cola2.push('g');
    cola2.push('.');
    cola2.push('1');
    
    funcion(cola1, cola2);
    return 0;
}