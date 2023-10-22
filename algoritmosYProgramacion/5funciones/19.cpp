//A un trabajador le pagan según sus horas trabajadas y la tarifa está a un valor por hora
//Si la cantidad de horas trabajadas es mayor a 40 horas
//la tarifa por hora se incrementa en un 50% para las horas extras
//Calcular el salario del trabajador dadas las horas trabajadas y la tarifa.

#include <stdio.h>
#include <stdlib.h>

float salario(int, int);

int main(){
    
    int horas, tarifa;
    float sal;

    printf("Ingrese el número de horas trabajadas:");
    scanf("%d", &horas);
    printf("Ingrese la tarifa:");
    scanf("%d", &tarifa);
    
    sal=salario(horas, tarifa);
    printf("El salario del trabajador será de: %.2f", sal);
    return 0;
}

float salario(int horas, int tarifa){
    
    int sal;

    if(horas>40){
        tarifa =tarifa + tarifa/2;
    }


    return sal;
}