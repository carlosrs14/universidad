//Dada las horas trabajadas de una persona y el valor por hora. Calcular su salario y visualizarlos.

#include <stdio.h>
#include <stdlib.h>

void salario(int, int);

int main(){
    int horas, valor;

    printf("Ingrese las horas trabajadas: ");
    scanf("%d", &horas);
    printf("Ingrese el valor por hora: ");
    scanf("%d", &valor);

    salario(horas, valor);
    return 0;
}

void salario(int horas, int valor){
    printf("El salario a pagar es: %d", horas*valor);
}
