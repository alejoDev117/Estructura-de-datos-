#include <iostream>

using namespace std;

int main(){
	
	system("cls");
	system("color 0A");
	
	
	
	int numeros[10];
	int *puntero;
	
	for(int i = 0 ; i<10 ; i ++){
		cout<<"Ingrese numero\n";
		cin>>numeros[i];
	}
	//###################################

	puntero = *&numeros; //Asignacion de la direccion de memoria para un array
	
	//#########################################
	for(int i = 0; i<10 ; i++){
		if(puntero[i] % 2 == 0){
			cout<<"Numero par  :"<<puntero[i]<<"<-->"<<&puntero[i]<<endl;
		}else{
			cout<<"Numero impar:"<<puntero[i]<<"<-->"<<&puntero[i]<<endl;
		}
		
	}
	return 0;
}
