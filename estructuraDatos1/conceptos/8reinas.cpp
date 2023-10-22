#include<iostream>
using namespace std;
void inicializar(int m[8][8]){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			m[i][j]=0;
		}
	}
}
void imprimir(int m[8][8]){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(m[i][j]==0)
			cout<<"[ ]";
			else{
				cout<<"[W]";
			}
		}
		cout<<endl;
	}
}
bool verificar(int m[8][8], int x, int y){
	int i=1,sw=1;
	while(sw<8){
		sw=1;
		if(y-i>=0){
			if(m[x][y-i]!=0)
				return false;
		}else{
			sw++;
		}
		if(y+i<=7){
			if(m[x][y+i]!=0)
				return false;
		}else{
			sw++;
		}
		if(x-i>=0){
			if(m[x-i][y]!=0)
				return false;
		}else{
			sw++;
		}
		if(x+i<=7){
			if(m[x+i][y]!=0)
				return false;
		}else{
			sw++;
		}
		if(y-i>=0 && x-i>=0){
			if(m[x-i][y-i]!=0)
				return false;
		}else{
			sw++;
		}
		if(y+i<=7 && x-i>=0){
			if(m[x-i][y+i]!=0)
				return false;
		}else{
			sw++;
		}
		if(y-i>=0 && x+i<=7){
			if(m[x+i][y-i]!=0)
				return false;
		}else{
			sw++;
		}
		if(y+i<=7 && x+i<=7){
			if(m[x+i][y+i]!=0)
				return false;
		}else{
			sw++;
		}
		i++;
			
	}
	return true;
}

void reinas(int m[8][8],int i, int &cr){
	if(cr<=8){
		for(int j=0;j<8;j++){
			if(verificar(m,i,j)){
				m[i][j]=cr;
				cr++;
				cout<<"ida:"<<endl;
				imprimir(m);
				reinas(m,i+1,cr);
				if(cr<=8){
					cout<<"regreso:"<<endl;
					imprimir(m);
					system("pause");
					m[i][j]=0;
					cr--;
				}
			}
		}
	}
}
int main(){
	int m[8][8];
	inicializar(m);
	int cr=1;
	reinas(m,0,cr);
	imprimir(m);
	
	return 0;
}






