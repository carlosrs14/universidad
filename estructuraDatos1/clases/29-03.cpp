#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef char tdato;
typedef struct n{
	tdato dato;
	struct n *sgt;
}pc;
typedef struct pila_char{
	pc * cima;
	void inicializar(){
		cima=NULL;
	}
	bool vacia(){
		return cima==NULL;
	}
	void insertar(int d){
		pc*p=(pc *) malloc(sizeof(pc));
		p->sgt=cima;
		p->dato=d;
		cima=p;
	}
	tdato quitar(){
		tdato aux;
		if(!vacia()){
			aux=cima->dato;
			pc *p=cima;
			cima=cima->sgt;
			delete(p);
			return aux;
		}
		return NULL;
	}
	void imprimir(){
		for(pc *p=cima; p!=NULL; p=p->sgt){
			cout<<"["<<p->dato<<"]->";
		}
		cout<<"NULL"<<endl;
	}
	int tamPila(){
		int cont=0;
		for(pc *p=cima; p!=NULL; p=p->sgt){
			cont++;
		}
		return cont;
	}
	tdato datoCima(){
		if(!vacia())
			return cima->dato;
		return NULL;
	}
}Pila_char;

typedef double tdato2;
typedef struct p{
	tdato2 dato;
	struct p *sgt;
}pd;
typedef struct Pila_double{
	pd * cima;
	void inicializar(){
		cima=NULL;
	}
	bool vacia(){
		return cima==NULL;
	}
	void insertar(int d){
		pd*p=(pd *) malloc(sizeof(pd));
		p->sgt=cima;
		p->dato=d;
		cima=p;
	}
	tdato2 quitar(){
		tdato2 aux;
		if(!vacia()){
			aux=cima->dato;
			pd *p=cima;
			cima=cima->sgt;
			delete(p);
			return aux;
		}
		return NULL;
	}
	void imprimir(){
		for(pd *p=cima; p!=NULL; p=p->sgt){
			cout<<"["<<p->dato<<"]->";
		}
		cout<<"NULL"<<endl;
	}
	int tamPila(){
		int cont=0;
		for(pd*p=cima; p!=NULL; p=p->sgt){
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
		case'^':
			return 3;
		case '*':
			return 2;
		case'/':
			return 2;
		case'+':
			return 1;
		case'-':
			return 1;
		case '(':
			return 0;
	}
	return -1;
}
char* posfija(char infija[50]){
	int tam=strlen(infija);
	char pos[50];
	int j=0;
	Pila_char p1;
	p1.inicializar();
	for(int i=0;i<tam;i++){
		char c=infija[i];
		if(c>='a' & c<='z'){
			pos[j]=c;
			j++;
		}else{
			if(prioridadDentro(c)!=-1){
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
	return pos;
}
void valores(double v[27], char exp[50]){
	int tam=strlen(exp);	
	bool ver[27];
	for(int i=0; i<tam; i++){
		ver[i]=false;
	}
	for(int i=0; i<tam; i++){
		if(exp[i]>='a' && exp[i]<='z'){
			if(!ver[exp[i]-'a']){
				cout<<"Ingrese la variable "<<exp[i]<<": ";cin>>v[exp[i]-'a'];
				ver[exp[i]-'a']=true;
			}			
		}
	}
	for(int i=0;i<27 ; i++){
		cout<<"["<<v[i]<<"]";
	}
}


void operar(){
	double res=0;
	double vector[27];
	
	posfija(cadena);
	cout<<cadena<<"aqui hay una linea de código";
	valores(vector, cadena);
}

int main(){
	char cadena[50];
	cout<<"Ingrese la cadena: ";cin>>cadena;
	
	operar(cadena);
	return 0;
}
