#include <iostream>
#include <stdlib.h>
using namespace std;
typedef int Tdato;
typedef struct nodo{
	Tdato dato;
	struct nodo * sgt;
}Nodo;
typedef struct cola{
	Nodo *fr, *fin;
	void inicializar(){
		fr=NULL;
		fin=NULL;
	}
	bool vacia(){
		return fr==NULL;
	}
	void insertar(Tdato d){
		Nodo * p= (Nodo *) malloc(sizeof(Nodo));
		p->dato=d;
		p->sgt=NULL;

		if(vacia()){
			fr = p;
			fin = p;
		}else{
			fin->sgt=p;
			fin=p;
		}
	}
	void imprimir(){
		for(Nodo *p =fr; p!=NULL; p=p->sgt){
			cout<<"["<<p->dato<<"]";
		}
		cout<<endl;
	}
	Tdato quitar(){
		if(!vacia()){
			Tdato aux=fr->dato;
			Nodo *p=fr;
			fr=fr->sgt;
			delete(p);
			return aux;
		}
		cout<<"Underflow"<<endl;
		return NULL;
	}
	Tdato datofrente(){
		if(!vacia()){
			return fr->dato;
		}
		cout<<"Cola vacia"<<endl;
		return NULL;
	}	
	int tam(){
		int cont=0;
		for(Nodo *p =fr; p!=NULL; p=p->sgt){
			cont++;
		}
		return cont;
	}
	
	bool buscar(Tdato d){
		for(Nodo *p=fr; p!=NULL; p=p->sgt){
			if(p->dato==d)
				return true;
		}
		return false;
	}
}Cola;

bool buscar(Cola c, Tdato d){
	int t= c.tam();
	
	bool r=false;
	
	for(int i=0; i<t; i++){
		if(c.datofrente()==d){
			r=true;
		}
		c.insertar(c.quitar());
	}
	return r;
}

Cola sumaColas(Cola c1, Cola c2){
	Cola c3;
	c3.inicializar();

	for(int i=0; i<c1.tam(); i++){
		c3.insertar(c1.datofrente()+c2.datofrente());
		c1.insertar(c1.quitar());
		c2.insertar(c2.quitar());
	}

	return c3;
}

int main(){
	Cola c1, c2;
	c1.inicializar();
	c2.inicializar();

	c1.insertar(1);
	c1.insertar(2);
	c1.insertar(3);
	c1.insertar(4);
	c1.insertar(5);
	
	c2.insertar(8);
	c2.insertar(3);
	c2.insertar(6);
	c2.insertar(3);
	c2.insertar(0);

	cout<<buscar(c1, 7)<<endl;
	cout<<buscar(c1, 1)<<endl;
	
	cout<<"c1:";
	c1.imprimir();

	cout<<"c2:";
	c2.imprimir();

	cout<<"c3:";
	sumaColas(c1, c2).imprimir();

	return 0;
}
