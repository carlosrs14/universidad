//Que exprese en horas, minutos y segundos un tiempo expresado en segundos.

#include <stdio.h>
#include <stdlib.h>

void tiempo(int);

int main(){
    int seg;

    printf("Ingrese los segundos: ");
    scanf("%d", &seg);

    tiempo(seg);

    return 0;
}



void tiempo(int segundos_totales){

    int horas, minutos, segundos;

    printf("El tiempo transcurrido fue: ");

    if(segundos_totales>=3600){

        horas = segundos_totales/3600;
        segundos_totales = segundos_totales%3600;
        minutos  = segundos_totales/60;
        segundos = segundos_totales%60;
        printf("%d horas, %d minutos y %d segundos",horas, minutos, segundos);
    }else 
        if(segundos_totales>=60){

            minutos  = segundos_totales/60;
            segundos = segundos_totales%60;


            printf("0 horas, %d minutos y %d segundos", minutos, segundos);
        }else{
            printf("0 horas, 0 minutos y %d segundos", segundos_totales);
        }

}
