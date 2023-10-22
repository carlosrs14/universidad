#include<iostream>
using namespace std;

//escribe una funcion recursiva, int product(v [], int b) que calcule el producto de los elementos del array v mayores que b.

int product(int v[], int b, int tam){
// preguntar si el array esta vacio	
	if(tam==0){
		return v[0];
	}
//un if donde preguntemos el numero si es mayor que b, recursiva
	if(v[tam]>b){
		return v[tam]*product(v,b,tam-1);
	}else{
		return product(v,b,tam-1);
	}
}

//cuando un for i++; v[i], i=0 -> v[0]; i=1 -> v[1]
//arr[]= {3,4,5,6,7,8}; -> arra[0]=3

int main(){
	
	int arr[]= {2,3,4,5,6};
	int tam = sizeof(arr)/sizeof(arr[0]);
	int b = 8;
	
	int resultado=product(arr,b,tam);
	
	if(resultado==arr[0]){
		cout<<"No hay elementos en el array mayores que "<<b<<endl;
	}else{
		cout<<"El producto de los elementos mayores que "<<b<<" es: "<<resultado<<endl;
	}
	
}
