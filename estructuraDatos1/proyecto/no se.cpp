#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<cassert>

using namespace std;

int contarFilas(){
	ifstream f;
	f.open("matriz.csv");
	char cad[50];
	int fi=0;
	if(f.is_open()){
		while(!f.eof()){
			f.getline(cad,50);
			fi++;
		}
	}
	return fi;
}

int contarColumnas(){
    ifstream f;
    f.open("matriz.csv");
    int colum=0, i=0;
    string linea; 
	getline(f,linea);
    int carac = linea.length();
    if (f.is_open()){
        while (i<=carac){
    		if(isdigit((char)f.get())== true){
				colum++;
			}
			i++;
        }
    }
    return colum;
}

void rellenarMatriz(int** matriz, int filas, int columnas){
	ifstream f;
	f.open("matriz.csv");
	if(f.is_open()){
		while(!f.eof()){
			for(int i=0;i<filas;i++){
				char linea[50];
				f.getline(linea, 50);
				int k=0;
				for(int j =0; j<columnas ;j++){
					char num = linea[k];
					k+=2;
					cout<<num<<endl;
					if(isdigit(num)){
						matriz[i][j] = (int) num - 48;
						cout<<matriz[i][j]<<endl;
					}
				}
			}
		}
	}
}

/*
void rellenarMatriz(int** matriz, int filas, int columnas){
	srand(time(NULL));
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            matriz[i][j]=rand()%10;
        }
    }
}
*/

void imprimirArreglo(int **matriz, int rows, int cols){
    for(int i=0;i< rows;i++){
        for(int j=0;j< cols;j++){
            cout<<matriz[i][j]<<"\t";
        }
        cout<<endl;
    }
}

/*
char caminoCorto(int **m, int x, int y, int xf, int yf){
	char c;
	if(m[x][y] == m[xf][yf]){
		return c + (char)m[x][y];
	}else{
		if((m[x][y+1]+m[x][y])>(m[x][y]+m[x+1][y])){
			return (char)(c + caminoCorto(m,x+1,y,xf,yf));
		}else{
			return (char)(c + caminoCorto(m,x,y+1,xf,yf));
		}
	}
}
*/

int main(){
	int filas = contarFilas();
	int cols = contarColumnas();
	int** matriz= new int*[filas];
	for (int i = 0; i < cols; i++)
        matriz[i] = new int[cols];

	rellenarMatriz(matriz,filas,cols);
	imprimirArreglo(matriz,filas,cols);
	
	//cout<<caminoCorto(matriz,0,0,3,3);
	
	return 0;
}
