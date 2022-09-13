#include <iostream>
#include <stdlib.h>
using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};
void agregarCola(Nodo *&, Nodo *& , int);
int recorrerCola(Nodo *&,int);
bool validarExistenciaDato(Nodo *&,int);
int main(){
    Nodo *frente = NULL;
    Nodo *fin = NULL;
    int dato;
    string decisionAgregar = "si";
    while(decisionAgregar == "si" || decisionAgregar == "Si"){
        cout<<"Ingrese dato\n";
        cin>>dato;
        agregarCola(frente,fin,dato);
        cout<<"Desea ingresar otro numero?(si,no)\n";
        cin>>decisionAgregar;
    }
    int numeroBusqueda;
    cout<<"Ingrese el numero a buscar\n";
    cin>>numeroBusqueda;
    cout<<"suma: "<<recorrerCola(frente,numeroBusqueda);
    return 0;
}

void agregarCola(Nodo *&frente , Nodo *&fin, int dato){
    Nodo *nuevoNodo = new Nodo();
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;
    if(frente == NULL){
        frente = nuevoNodo;
    } else{
        fin->siguiente = nuevoNodo;
    }
    fin = nuevoNodo;
}
int recorrerCola(Nodo *&frente, int dato){
    int suma = 0;
    Nodo *auxFrente = frente;
    if(validarExistenciaDato(auxFrente,dato)){
        while(frente->dato != dato){
            suma += frente->dato;
            frente = frente->siguiente;
        }
        return suma;
    }
    return 0;
}
bool validarExistenciaDato(Nodo *& frente,int dato){
    while(frente != NULL){
        if(frente->dato == dato){
            return true;
        }
        frente = frente->siguiente;
    }
    return false;
}