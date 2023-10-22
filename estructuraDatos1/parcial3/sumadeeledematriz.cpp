#include<iostream>
using namespace std;

//programar un algoritmo recursivo que permita sumar los elementos de una matriz

const int tammax = 100;

int sumardematriz( int m[tammax][tammax], int fila, int columna, int limfila, int limcol){
//tenemos que mirar cuando x &  y lleguen lim entonces retornamos la matriz
	if(fila==limfila && columna == limcol){
		return m[fila][columna];
	}
//sumar donde estamos	
	int sumar = m[fila][columna];
//movernos	
	if(columna==limcol){
		//cuando x llegue al tope, reseteamos e incrementamos y
		return sumar + sumardematriz(m,fila+1,0,limfila,limcol);
	}else{
		return sumar + sumardematriz(m,fila,columna+1,limfila,limcol);
	}
}


int main(){
	int limfila, limcol;
	
	cout<<"Ingrese el numero de filas de la matriz"<<endl;
	cin>>limfila;
	cout<<"Ingrese el numero de columnas de la matriz"<<endl;
	cin>>limcol;
	
	int m[tammax][tammax];
	
	for(int i =0;i<limfila;i++){
		for(int j=0;j<limcol;j++){
			cout<<"Ingrese el valor en la posicion ["<<i<<"] ["<<j<<"] ";
			cin>> m[i][j];
		}
	}
	
	int suma=sumardematriz(m,0,0,limfila,limcol);
	
	cout<<"La suma de los elementos de la matriz es: "<<suma<<endl;
}
