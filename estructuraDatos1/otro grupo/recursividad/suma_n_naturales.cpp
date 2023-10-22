#include <iostream>
#include <stdlib.h>
using namespace std;

int suma(int n){
    if(n==0){
        return 0;
    }
    return n + suma(n-1);
}

int main(){
    cout<<suma(9)<<endl<<endl<<endl;
    return 0;
}