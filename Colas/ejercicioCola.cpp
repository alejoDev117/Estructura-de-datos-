/*Ejercicio 2: Hacer un programa que guarde datos de clientes de un banco, los almacene
en cola, y por ultimo muestre los clientes en el orden correcto.*/

#include<iostream>
#include<stdlib.h>
using namespace std;

struct Nodo{
	string nombre;
	string clave;
	string edad;
	Nodo *siguiente;
};

//Prototipos de Funciones
void insertarCola(Nodo *&,Nodo *&,string,string,string);
bool colaVacia(Nodo *);
void suprimirCola(Nodo *&,Nodo *&,string &,string &,string &);
void recorrerCola(Nodo *&);

int main(){
	Nodo *frente = NULL;
	Nodo *fin = NULL;	
	string decision = "si";
	string decision2= "si";
	string nombre , clave , edad;
	system("cls");
	system("color 0A");
	cout<<"\tAgregando un Nuevo Cliente"<<endl;
	do{
		cout<<"Nombre: "; 
		cin>>nombre;
		cout<<"Clave: ";
		cin>>clave;
		cout<<"Edad: ";
		cin>>edad;
		cout<<"\n";
		insertarCola(frente,fin,nombre,clave,edad); //y luego lo agregamos a cola
		cout<<"Desea agregar mas clientes(si/no): ";
		cin>>decision;
		cout<<"\n";
	}while(decision == "si" || decision == "Si");

	
	cout<<"\n\n=== Carga de Clientes Exitosa ===\n\n";

	cout<<"Mostrando clientes:\n\n";
	Nodo *punteroRecorridoAux = frente;
	while(punteroRecorridoAux != NULL){
		recorrerCola(punteroRecorridoAux);
	}

	return 0;
}

void insertarCola(Nodo *&frente,Nodo *&fin,string nombre, string clave, string edad){
	Nodo *nuevoNodo = new Nodo();
	nuevoNodo->nombre = nombre;
	nuevoNodo->clave = clave;
	nuevoNodo->edad = edad;
	nuevoNodo->siguiente = NULL;
	if(colaVacia(frente)){
		frente = nuevoNodo;
	}
	else{
		fin->siguiente = nuevoNodo;
	}

	fin = nuevoNodo;
}

bool colaVacia(Nodo *frente){
	return (frente == NULL)? true : false;
}

void suprimirCola(Nodo *&frente,Nodo *&fin,string &nombre , string &clave , string &edad){
	nombre = frente->nombre;
	clave = frente->clave;
	edad = frente->edad;
	Nodo *aux = frente;
	if(frente == fin){
		frente = NULL;
		fin = NULL;
	}
	else{
		frente = frente->siguiente;
	}

	delete aux;
}
void recorrerCola(Nodo *&frente){
	cout<<"Nombre: "<<frente->nombre<<endl<<"Clave:"<<frente->clave<<endl<<"Edad: "<<frente->edad<<endl<<"----"<<endl;
	frente = frente->siguiente;
}
