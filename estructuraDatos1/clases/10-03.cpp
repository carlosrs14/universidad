#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct nodo{
	
	int dato;
	struct nodo * sgt;	
	
}Nodo;

typedef struct lista{
	Nodo * cab;
	
	void inicializar(){
		cab=NULL;
	}
	Nodo * crearNodo(int d, Nodo *s){
		Nodo *p = (Nodo *) malloc(sizeof(Nodo));
		p->dato=d;
		p->sgt=s;
		return p;
	}
	
	void insertarCab(int d){
		Nodo * p=crearNodo(d, cab);
		cab=p;
	}
	
	void imprimir(){
		for(Nodo * p=cab; p!=NULL; p=p->sgt){
			cout<<"["<<p->dato<<"]->";
		}
		cout<<"NULL"<<endl;
	}
	void crearBucle(){
		Nodo *p=cab;
		for(; p->sgt!=NULL; p=p->sgt);
		p->sgt=cab->sgt->sgt->sgt;	
	}
	
	bool verificar(){
		Nodo *cab2, *p=cab, *q;
		int sw=0;
		if(p!=NULL){
			cab2=p->sgt;
			p->sgt=NULL;
			
			while(cab2!=NULL && cab2!=cab){
				q=cab2;
				p=cab;
				while(p!=NULL){
					if(q->sgt==p){
						sw=1;
						cout<<"Tiene ciclo"<<endl;
						break;
					}
					if(p->sgt!=NULL)
						p=p->sgt;
					else
						break;
						
				}
				p->sgt=cab2;
				if(sw==1){
					return true;
				}else{
					cab2=cab2->sgt;
					p=p->sgt;
					p->sgt=NULL;
				}
			}
			cout<<"NO tiene ciclo"<<endl;
			return false;
			
		}
		cout<<"NO hay ningun elemento en la lista"<<endl;
		return false;
	}
	
}Lista;

int main(){
	
	Lista l1;
	
	l1.inicializar();
	l1.verificar();
	l1.insertarCab(1);
	l1.insertarCab(2);
	l1.insertarCab(3);
	l1.insertarCab(4);
	l1.insertarCab(5);
	l1.imprimir();
	
	l1.verificar();
	//l1.crearBucle();
	l1.verificar();
	return 0;
}
