#include <iostream>
#include <stdlib.h>

using namespace std;

typedef int tdato; 

typedef struct nodo{
	tdato dato;
	struct nodo *sgt;
}Nodo;

typedef struct pila{
	Nodo * cima;
	void inicializar(){
		cima = NULL;
	}
	
	void insertar(tdato d){
		Nodo * p=(Nodo *) malloc(sizeof(Nodo));
		p->sgt=cima;
		p->dato=d;
		cima=p;
	}
	
	bool vacia(){
		return cima==NULL;
		
	}
	
	tdato quitar(){
		tdato aux;
		if(!vacia()){
			aux=cima->dato;
			Nodo*p=cima;
			cima=cima->sgt;
			delete(p);
			return aux;
		}
		return NULL;
	}
	
	tdato cimaPila(){
		if(!vacia())
			return cima->dato;
		return NULL;
	}
	
	int tamPila(){
		int cont=0;
		for(Nodo*p=cima; p!=NULL; p=p->sgt)
			cont++;
		return cont;
	}
	
	
	void imprimir(){
		for(Nodo*p=cima; p!=NULL; p=p->sgt)
			cout<<"["<<p->dato<<"]->";
		cout<<"NULL"<<endl;
	}
	
	void vaciarPila(){
		
		while(!vacia())
			quitar();
	
	}
}Pila;


int main(){
	
	
	Pila p1;
	p1.inicializar();
	p1.insertar(15);
	p1.insertar(16);
	p1.insertar(17);
	p1.imprimir();
	p1.vaciarPila();
	p1.imprimir();
	
	
	
	return 0;
}
