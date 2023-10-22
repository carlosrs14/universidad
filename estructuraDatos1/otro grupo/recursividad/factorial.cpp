#include <iostream>
#include <stdlib.h>
using namespace std;

int factorial(int n){
    if(n==0)
        return 1;
    return n* factorial(n-1);
}

int main(){
    cout<<factorial(3)<<endl<<endl<<endl;
    return 0;
}