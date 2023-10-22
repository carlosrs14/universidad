#include <iostream>
#include <stdlib.h>
using namespace std;

int nesimoFibonacci(int n){
    if(n==1)
        return 0;
    else if(n==2)
        return 1;
    else
        return nesimoFibonacci(n-1) + nesimoFibonacci(n-2);
}

int main(){
    cout<<nesimoFibonacci(29)<<endl<<endl<<endl;
    return 0;
}