#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef struct a{
	
	char marca[20];
	char modelo[20];
	int anio;
	struct a*sgt;
}vehiculo;

typedef struct n{
	int id;
	char nombre[20];
	char email[20];
	struct n * sgt;
	vehiculo * lv;	
}Persona;

Persona * crearPersona(int id, char n[20], char e[20], Persona * s, vehiculo * lv){
	
	Persona *p = (Persona *) malloc(sizeof(Persona));
	p->id=id;
	strcpy(p->nombre, n);
	strcpy(p->email, e);
	p->sgt=s;
	p->lv=lv;
	
	return p;
}

void insertarCab(Persona *&cab, int id, char n[20], char e[20]){
	Persona * p = crearPersona(id, n, e, cab, NULL);
	cab=p;
}

void insertarPersona(Persona *&cab){
	Persona * p = crearPersona(0, "", "", cab, NULL);
	cout<<"Id: ";
	cin>>p->id;
	cout<<"nombre: ";
	cin>>p->nombre;
	cout<<"email: ";
	cin>>p->email;
	cab=p;
}

void imprimir(Persona *p){
	system("cls");
	
	for(; p!=NULL; p=p->sgt){
		cout<<endl<<"Id: "<<p->id<<endl;
		cout<<"nombre: "<<p->nombre<<endl;
		cout<<"email: "<<p->email<<endl<<endl;	
	}
	system("pause");
}

Persona * buscarP(Persona * cab, int id){
	for(Persona * p= cab; p!=NULL; p=p->sgt){
		if(p->id==id){
			return p;
		}
	}
	return NULL;
}

void insertarVehiculo(vehiculo *&l){
	
	vehiculo * p = (vehiculo *) malloc(sizeof(vehiculo));
	
	cout<<"Marca: ";
	cin>>p->marca;
	cout<<"Modelo: ";
	cin>>p->modelo;
	cout<<"Anio: ";
	cin>>p->anio;
	
	p->sgt=l;
	l=p;
}

void imprimirVehi(vehiculo *p){
	system("cls");
	for(; p!=NULL; p=p->sgt){
		cout<<"Modelo: "<<p->modelo;
		cout<<"\tMarca: "<<p->marca;
		cout<<"\tAnio: "<<p->anio<<endl;
	}
	system("pause");

}
void datosPrograma(Persona *cab){
	system("cls");
	
	for(Persona *p=cab; p!=NULL; p=p->sgt){
		
		cout<<endl<<"Id: "<<p->id<<endl;
		cout<<"nombre: "<<p->nombre<<endl;
		cout<<"email: "<<p->email<<endl;
		
		for(vehiculo *v=p->lv; v!=NULL; v=v->sgt){
			cout<<"Modelo: "<<v->modelo;
			cout<<"\tMarca: "<<v->marca;
			cout<<"\tAnio: "<<v->anio<<endl;
		}
	}
	system("pause");

}

void editarInfo(Persona * p){
		int opcion;
		cout<<"1 - Nombre: "<<endl;
		cout<<"2 - Email: "<<endl;
		cout<<"cualquier otro numero para cancelar: "<<endl;
		cout<<"ingrese su opcion: ";
		cin>>opcion;
		
		switch(opcion){
			case 1:
				cout<<"Nombre: ";
				cin>>p->nombre;
				cout<<"El nombre ha sido modificado"<<endl;
				break;
			case 2:
				cout<<"Email: ";
				cin>>p->email;
				cout<<"El email ha sido modificados"<<endl;
				break;
			default:
				cout<<"Operacion cancelada"<<endl;
				break;
		}
		
		
		system("pause");
}

Persona * buscarPersona(Persona *p, char nombre[20]){
	for(;p!=NULL; p=p->sgt){
		if(strcmp(nombre, p->nombre)==0){
			return p;
		}	

	}
	return NULL;
}

int main(){
	int opcion;
	Persona * cab=NULL;
	
	do{
		system("cls");
		cout<<"Menu"<<endl;
		cout<<"1 - agregar persona"<<endl;
		cout<<"2 - imprimir"<<endl;
		cout<<"3 - agregar vehiculo"<<endl;
		cout<<"4 - mostrar vehiculos de una persona"<<endl;
		cout<<"5 - mostrar todos los datos"<<endl;
		cout<<"6 - editar una persona"<<endl;
		cout<<"7 - buscar por nombre "<<endl;
		cout<<"0 - salir"<<endl;
		cout<<"Digite su opcion: ";
		cin>>opcion;
		
		
		switch (opcion){
			case 1: 
				insertarPersona(cab);
				break;
				
			case 2:
				imprimir(cab); 
				break;
				
			case 3:{
				int id;
				cout<<"ID persona: ";
				cin>>id;
				Persona * ptemp=buscarP(cab, id);
				if(ptemp==NULL){
					cout<<"No se encontro la persona"<<endl;
					system("pause");
				}else{
					
					insertarVehiculo(ptemp->lv);
				}		
				 
				break;
			}
			case 4:{
				int id;
				cout<<"ID persona: ";
				cin>>id;
				Persona * ptemp=buscarP(cab, id);
				if(ptemp==NULL){
					cout<<"No se encontro la persona"<<endl;
					system("pause");
				}else{
					imprimirVehi(ptemp->lv);
				}
				break;
			}
			case 5:{
				Persona * p=cab;
				if(p==NULL){
					cout<<"No hay datos persona"<<endl;
					system("pause");
				}else{
					cout<<"Datos del programa: "<<endl;
					datosPrograma(p);
				}
				break;
			}
			case 6:{
				int id;
				cout<<"ID persona: ";
				cin>>id;
				Persona * p=buscarP(cab, id);
				if(p==NULL){
					cout<<"No se encontro la persona"<<endl;
					system("pause");
				}else{
					editarInfo(p);
				}
				break;
			}case 7:{
				char nombre[20];
				cout<<"ID persona: ";
				cin>>nombre;
				Persona * p=buscarPersona(cab, nombre);
				if(p==NULL){
					cout<<"No se encontro la persona"<<endl;
					system("pause");
				}else{
					cout<<"Nombre: "<<p->nombre<<endl;
					cout<<"Email: "<<p->email<<endl;
					system("pause");
				}
				break;
			}

		}
			
	}while(opcion != 0);
		
	return 0;
}
