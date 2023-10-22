#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

void escribir(){
    fstream f;
    f.open("hola.txt");
    char cad[20];
    while(true){
        cin.getline(cad, 20);
        if(strcmp(cad, "Q")==0){
            break;
        }
        f<<cad;

    }
    f.close();
}

void leer(){
    true;
}

int main(){
    escribir();
    leer();
    return 0;
}