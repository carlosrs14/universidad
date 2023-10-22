#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef char tdato;

typedef struct n{
	int dato;
	struct n *sgt;
}Nodo;

typedef struct pila{
	Nodo * cima;
	
	void inicializar(){
		cima=NULL;
	}

	bool vacia(){
		return cima==NULL;
	}
	
	void insertar(int d){
		Nodo*p=(Nodo *) malloc(sizeof(Nodo));
		p->sgt=cima;
		p->dato=d;
		cima=p;
	}
	
	tdato quitar(){
		tdato aux;
		if(!vacia()){
			aux=cima->dato;
			Nodo *p=cima;
			cima=cima->sgt;
			delete(p);
			return aux;
		}
		return NULL;
	}
	
	void imprimir(){
		for(Nodo *p=cima; p!=NULL; p=p->sgt){
			cout<<"["<<p->dato<<"]->";
		}
		cout<<"NULL"<<endl;
	}
	int tamPila(){
		int cont=0;
		for(Nodo *p=cima; p!=NULL; p=p->sgt){
			cont++;
		}
		return cont;
	}
	
	tdato datoCima(){
		if(!vacia())
			return cima->dato;
		return NULL;
	}
	
}Pila;

int prioridadFuera(char c){
	switch(c){
		case '^':
			return 4;
		case '*':
			return 2;
		case '/':
			return 2;
		case '+':
			return 1;
		case '-':
			return 1;
		case '(':
			return 5;
	}
	return -1;
}

int prioridadDentro(char c){
	switch(c){
		case '^':
			return 3;
		case '*':
			return 2;
		case '/':
			return 2;
		case '+':
			return 1;
		case '-':
			return 1;
		case '(':
			return 0;
	}
	return -1;
}

void posfija(char infija[50]){
	int tam=strlen(infija), j=0;
	char pos[50], c;
	Pila p1;
	p1.inicializar();
	
	for(int i=0; i<tam; i++){
		c=infija[i];
		if(c>='a' && c<='z'){
				pos[j]=c;
				j++;
		}else{
			if(prioridadFuera(c)!=-1){
				if(p1.vacia()){
					p1.insertar(c);
				}else{
					if(prioridadFuera(c)>prioridadDentro(p1.datoCima())){
						p1.insertar(c);
					}else{
						while(prioridadFuera(c)<=prioridadDentro(p1.datoCima())){
							
							pos[j]=p1.quitar();
							j++;
						}
						p1.insertar(c);
					}
				}
			}else{
				while(p1.datoCima()!='('){
					pos[j]=p1.quitar();
					j++;
				}
				p1.quitar();
			}
		}
	
		
	}
	
	while(!p1.vacia()){
		pos[j]=p1.quitar();
		j++;
	}
	pos[j]='\0';
	cout<<"Tam: "<<tam<<endl;
	cout<<pos<<endl;
	p1.imprimir();
}



int main(){
	char cadena[]="a*(b+c-(d/e^f)-g)-h";
	posfija(cadena);
	
	
	return 0;
}


