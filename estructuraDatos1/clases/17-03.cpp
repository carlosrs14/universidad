#include <iostream>
#include <stdlib.h>

//#define tam 10

using namespace std;

typedef char Tdato;

typedef struct pila{
	Tdato *vec;
	int cima;
	int tam;
	
	void inicializar(int t){
		int tam=t;
		vec= new Tdato[tam];
		int cima=-1;
	}
	
	bool llena(){
		if(cima == tam-1)
			return true;
		return false;
	}
	
	bool vacia(){
		if(cima == -1)
			return true;
		return false;
	}
	
	void insertar(Tdato d){
		if(!llena()){
			cima++;
			vec[cima]=d;
		}else{
			cout<<"Overflow"<<endl;
		}
		
	}
	Tdato quitar(){
		if(!vacia()){
			int tmp = vec[cima];
			cima--;
			return tmp;
		}else{
			cout<<"Underflow"<<endl;
		}
		return NULL;
	}
	
	int tam_pila(){
		return tam;
	}
	
	int cima_pila(){
		if(!vacia()){
			return vec[cima];
		}
		cout<<"Underflow"<<endl;
		return NULL;
	}
	
	void imprimir(){
		for(int i=cima; i>=0; i--){
			cout<<"["<<vec[i]<<"]"<<endl;
		}
	}
	
	
}Pila;

bool esPalindrome(char pal[], int t){
	int j=t-1;
	for(int i =0; i<t; i++){
		if(pal[i]!=pal[j]){
			return false;
		}
		j--;
	}
	return true;
}

int main(){
	
	Pila p;
	p.inicializar(10);
	
	char palabra1[]="hola";
	char palabra2[]="oso";
	if(esPalindrome(palabra1, 4)){
		cout<<"Es"<<endl;
	}else{
		cout<<"No es"<<endl;
	}
	
	if(esPalindrome(palabra2, 3)){
		cout<<"Es"<<endl;
	}else{
		cout<<"No es"<<endl;
	}
	
	return 0;
}
