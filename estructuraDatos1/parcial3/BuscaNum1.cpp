#include <iostream>
using namespace std;

int buscaNumero(int v[],int t, int b,int in){
	int mid=(in+t)/2;
	if(v[mid] == b)
		return mid;
	else if(v[mid]>b)
		return buscaNumero(v,mid,b,in);
	else{
		return buscaNumero(v,t,b,mid);
	}
}

int main(){
	int v[] = {1,2,3,4,5,6,7};
	int ini=0;
	cout<<buscaNumero(v,8,7,ini);
	return 0;
}

