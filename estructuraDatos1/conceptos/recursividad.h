#include <iostream>
using namespace std;

//división
int cociente(int n, int m){
    if(m>n)
        return 0;
    return 1 + cociente(n-m, m);
}

//resto de una división
int residuo(int n, int m){
    if(m>n)
        return n;
    return residuo(n-m, m);
}

//codigo torres de hanoi
void hanoi(char varinicial, char varcentral, char varfinal, int n){

    if (n == 1){
        cout<<"Mover disco "<<n<<" desde varilla "<<varinicial<<" a varilla "<<varfinal<<endl;
    }else{
        hanoi(varinicial, varfinal, varcentral, n - 1);
        cout<<"Mover disco "<<n<<" desde varilla "<<varinicial<<" a varilla "<<varfinal<<endl;
        hanoi(varcentral, varinicial, varfinal, n - 1);
    }
}

//codigo merge
void mergesort(double a[], int primero, int ultimo){
	int central;
	if (primero < ultimo)  {
		central = (primero + ultimo) / 2;
		mergesort(a, primero, central);
		mergesort(a, central + 1, ultimo);
		mezcla(a, primero, central, ultimo);
	}
}

void mezcla(double a[], int izda, int medio, int drcha){
	double* tmp;
	int i, k, z;
	tmp = new double[drcha - izda + 1];
	i = z = izda;
	k = medio + 1;
// bucle para la mezcla, utiliza tmp[] como array auxiliar
	while (i <= medio && k <= drcha) {
		if (a[i] <= a[k])
		    tmp[z++] = a[i++];
		else
	      tmp[z++] = a[k++];
	}
// se mueven elementos no mezclados de sublistas
	while (i <= medio)
        tmp[z++] = a[i++];
	while (k <= drcha)
        tmp[z++] = a[k++];
// Copia de elementos de tmp[] al array a[]
	for (i = izda; i <= drcha; i++)
	   a[i] = tmp[i];
    
    delete tmp;
}


//codigo 8 reinas