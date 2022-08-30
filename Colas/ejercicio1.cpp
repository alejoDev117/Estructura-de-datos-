#include <iostream>

using namespace std;

int main(){
	int numero;
	int *puntero;
	puntero = &numero;
	
	cout<<"Ingrese numero\n";
	cin>>numero;
	
	if(*puntero % 2 == 0){
		cout<<"El numero  "<<*puntero<<"  Es par, con direccion de memoria: "<<puntero;
	}
	else{
		cout<<"El numero  "<<*puntero<<"  Es impar, con direccion de memoria: "<<puntero;		
	}
	return 0;
}
