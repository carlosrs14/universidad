#include <iostream>
#include <string.h>
using namespace std;
//inciso a
typedef struct veh{
    string marca;
    int modelo;
    int cilindrada;
    float precio;
    struct veh * sgt;
}Vehiculo;
typedef struct ven{
    string nombre;
    string apellido;
    int edad;
    float sueldo;
    struct ven * sgt;
    Vehiculo * lv; 
}Vendedor;
//inciso b
float calcularSueldo(string nombre, Vendedor * cab){
    float sueldo = 0;
    for(Vendedor * v = cab; v != NULL; v = v->sgt){
        if(v->nombre.compare(nombre) == 0){
            sueldo = v->sueldo;
            for(Vehiculo * c = v->lv; c != NULL; c = c->sgt){
                sueldo += (c->precio * 0.1);
            }
        }
    }
    return sueldo;
}
//inciso c
void imprimirTodo(Vendedor * cab){
    for(Vendedor *v = cab; v != NULL; v = v->sgt){
        cout<<endl<<endl<<"Nombre: "<<v->nombre<<endl;
        cout<<"Apellido: "<<v->apellido<<endl;
        cout<<"Edad: "<<v->edad<<endl;
        cout<<"Sueldo: "<<v->sueldo<<endl;
        for(Vehiculo * c = v->lv; c != NULL; c = c->sgt){
            cout<<endl<<"Marca: "<<c->marca<<endl;
            cout<<"Modelo: "<<c->modelo<<endl;
            cout<<"Precio: "<<c->precio<<endl;
            cout<<"Cilindrada: "<<c->cilindrada<<endl;
        }
 
    }
}
int main(){
    return 0;
}