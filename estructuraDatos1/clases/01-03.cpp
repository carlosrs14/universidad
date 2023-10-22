#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef struct veh{
	char marca[20];
	char modelo[20];
	int anio;
	struct veh *sgt;
}Vehiculo;

typedef struct rel{
	Vehiculo *pv;
	struct rel *sgt;
}Relacion;

typedef struct per{
	int id;
	char nombre[20];
	char email[20];
	Relacion *lv;
	struct per * sgt;
}Persona;

Persona * crearPersona(int id, char n[20], char e[20], Persona * s){
	Persona * p= (Persona *) malloc(sizeof(Persona));
	strcpy(p->nombre, n);
	strcpy(p->email, e);
	p->id=id;
	p->sgt=s;
	p->lv=NULL;
	return p;	
}

void insertarPerCab(Persona *&cab){
	Persona * p = crearPersona(0, "", "", cab);
	cout<<"ID: ";
	cin>>p->id;
	cout<<"Nombre: ";
	cin>>p->nombre;
	cout<<"Email: ";
	cin>>p->email;
	cab=p;
	
}

Vehiculo * crearVeh( char mar[20], char mod[20], int anio, Vehiculo * s){
	Vehiculo * v= (Vehiculo *) malloc(sizeof(Vehiculo));
	strcpy(v->marca, mar);
	strcpy(v->modelo, mod);
	v->sgt=s;
	v->anio=anio;
	return v;
	
}

void insertarVeh(Vehiculo *&cab){
	Vehiculo * p = crearVeh("", "",0, cab);
	cout<<"Marca: ";
	cin>>p->marca;
	cout<<"Modelo: ";
	cin>>p->modelo;
	cout<<"Anio: ";
	cin>>p->anio;
	cab=p;

}

Persona * buscarPersona(Persona *p, int id){
	for(;p!=NULL; p=p->sgt){
		if(id==p->id){
			return p;
		}
	}
	cout<<"NO se encontro la persona"<<endl;
	int var;
	cout<<"presione una tecla...";
	cin>>var;
	//system("pause");
	return NULL;
}

Vehiculo * buscarVehiculo(Vehiculo *p, char marca[20], char modelo[20], int anio){
	for(;p!=NULL; p=p->sgt){
		if(strcmp(marca, p->marca)==0 && strcmp(modelo, p->modelo)==0 && anio==p->anio){
			return p;
		}
	}
	cout<<"NO se encontro el vehiculo"<<endl;
	system("pause");
	return NULL;
}
void imprimirPersonas(Persona * p){
	for(; p!=NULL; p=p->sgt){
		cout<<p->id<<endl;
		cout<<p->nombre<<endl;
		cout<<p->email<<endl<<endl;
		cout<<"Vehiculos"<<endl;
		for(Relacion * r; r!=NULL; r=r->sgt){
			cout<<r->pv->marca<<endl;
			cout<<r->pv->modelo<<endl;
			cout<<r->pv->anio<<endl<<endl;
			
		}
	}
	//system("pause");
	int var;
	cout<<"presione una tecla...";
	cin>>var;
}

void imprimirVeh(Vehiculo * p){
	for(; p!=NULL; p=p->sgt){
		cout<<p->marca<<endl;
		cout<<p->modelo<<endl;
		cout<<p->anio<<endl<<endl;
	}
	system("pause");
}

int main(){
	Persona * cab=NULL;
	Vehiculo * cabV=NULL;
	int op=0;	
	do{
		system("clear");
		cout<<"1 - Agregar persona"<<endl;
		cout<<"2 - Imprimir persona"<<endl;
		cout<<"3 - Agregar vehiculo"<<endl;
		cout<<"4 - Imprimir vehiculo"<<endl;
		cout<<"5 - Relacionar"<<endl;
		cin>>op;
		
		switch(op){
			
			case 1:
				insertarPerCab(cab);
				break;
			
			case 2:
				imprimirPersonas(cab);
				break;
				
			case 3:
				insertarVeh(cabV);
				break;
			
			case 4:
				imprimirVeh(cabV);
				break;
			case 5:
				int aux;
				cout<<"ID: ";
				cin>>aux;
				Persona * p =buscarPersona(cab, aux);
				Vehiculo *q;
				if(p!=NULL){
					char marc[20], mod[20];
					int anio;
					cout<<"marca";
					cin>>marc;
					cout<<"modelo";
					cin>>mod;
					cout<<"anio";
					cin>>anio;
					q=buscarVehiculo(cabV, marc, mod, anio);
					if(q!=NULL){
						Relacion * pr=(Relacion *) malloc(sizeof(Relacion));
						pr->pv=q;
						p->lv=pr;
						pr->sgt=NULL;
						
					}else{
						cout<<"Vehiculo no encontrado"<<endl;
					}
				}else{
					cout<<"No se encontro la persona"<<endl;
				}
				imprimirVeh(cabV);
				break;
			
		}
			
	}while(op!=0);
	
	return 0;
}
