#include <iostream>
#include <stdlib.h>
using namespace std;

struct Nodo{
	int dato;
	Nodo * punteroSiguiente;
};

void insertarCola(Nodo *&,Nodo *&,int);
bool validarColaVacia(Nodo *);

int main(){
	
	Nodo *frente = NULL;
	Nodo *final = NULL;
	int dato;
	
	cout<<"Digite un numero"<<endl;
	cin>>dato;
	insertarCola(frente,final,dato);
	
	return 0;
	
}

void insertarCola(Nodo *&frente,Nodo *&final,int n){
	Nodo * nuevoNodo = new Nodo();
	nuevoNodo->dato = n;
	nuevoNodo->punteroSiguiente = NULL;
	
	if(validarColaVacia(frente)){
		frente = nuevoNodo;
	}else{
		final->punteroSiguiente  = nuevoNodo;
	}
	final = nuevoNodo;
}
bool validarColaVacia(Nodo *frente){
	if(frente == NULL){
		return true;
	}else{
		return false;
	}
}
