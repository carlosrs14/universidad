#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct nodoDoble{
	int dato;
	struct nodoDoble* sgt;
	struct nodoDoble* ant;
	
}NodoDoble;

NodoDoble * crearNodoDoble(NodoDoble * ant, NodoDoble * sgt, int d){
	NodoDoble * p= (NodoDoble *) malloc(sizeof(NodoDoble));
	p->dato=d;
	p->sgt=sgt;
	p->ant=ant;
	return p;
		
}


void insertarCab(NodoDoble *&cab, int d ){
	
	if(cab==NULL){
		cab=crearNodoDoble(NULL, NULL, d);
	}
	else{
	
		NodoDoble * p=crearNodoDoble(NULL, cab, d);
		cab->ant=p;
		cab=p;	
	}	
}

void imprimir(NodoDoble *cab){
	NodoDoble *p;
	NodoDoble *q;
	
	for(p=cab; p!=NULL; p=p->sgt){
		cout<<"["<<p->dato<<"]<=>";
		q=p;	
	}
	cout<<"NULL"<<endl;
	
	/*for(q; q!=NULL; q=q->ant){
		cout<<"["<<q->dato<<"]<=>";		
	}
	cout<<"NULL"<<endl;*/
}
void insertarCola(NodoDoble *&cab, int d ){
	
	if(cab==NULL){
		cab=crearNodoDoble(NULL, NULL, d);
	}
	else{
		for(NodoDoble * q=cab; q!=NULL; q=q->sgt){	
			if(q->sgt==NULL){
				NodoDoble * p=crearNodoDoble(q,NULL,d);
				q->sgt=p;
				return;
			}
		}	
	}	
}

NodoDoble * buscar(int db, NodoDoble *cab){
	for(NodoDoble *p = cab; p!=NULL; p=p->sgt){
		if(p->dato==db){
			return p;
		}
	}
	cout<<"No se encontro el dato"<<endl;
}

void insertarAntes(NodoDoble *&cab,int db, int di){
	if(db==cab->dato){
		insertarCab(cab, di);
		return;
	}else{
		NodoDoble*q=buscar(db, cab);
		NodoDoble*ant=q->ant;
		q->ant=crearNodoDoble(ant,q, di);
		ant->sgt=q->ant;
		
	}
}

void insertarDesp(NodoDoble *&cab,int db, int di){
	if(cab==NULL){
		cout<<"La lista esta vacia"<<endl;
	}
	
	NodoDoble *q= buscar(db, cab);
	NodoDoble *desp =q->sgt;
	
	q->sgt=crearNodoDoble(q,desp, di);
	desp->ant=q->sgt;  
	
	
}



int main(){
	NodoDoble * cab=NULL;
	insertarCab(cab, 15);
	insertarCab(cab, 16);
	insertarCab(cab, 17);
	insertarCab(cab, 18);
	imprimir(cab);
	insertarCola(cab, 19);
	insertarCola(cab, 20);
	imprimir(cab);
	insertarAntes(cab, 19, 21);
	imprimir(cab);
	insertarAntes(cab, 16, 22);
	imprimir(cab);
	insertarDesp(cab, 17, 23);
	imprimir(cab);
	insertarDesp(cab, 18, 24);
	imprimir(cab);
	
	return 0;
}
