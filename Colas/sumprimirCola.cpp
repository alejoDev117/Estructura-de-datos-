#include <iostream>
using namespace std;
struct Nodo{
    int dato;
    Nodo *siguiente;
};
void suprimirCola(Nodo *&, Nodo *&, int &);
void agregarCola(Nodo *&,Nodo *&,int );
bool validarColaVacia(Nodo *&);

int main(){
    Nodo *final = NULL;
    Nodo *frente = NULL;
    int dato;
    string decision = "si";
    while(decision == "Si" || decision == "si"){
        cout<<"Ingrese dato\n";
        cin>>dato;
        agregarCola(frente,final,dato);
        cout<<"desea ingresar otro dato?\n";
        cin>>decision;
    }
    while(frente != NULL){
        suprimirCola(frente,final,dato);
    }
    return 0;
}

void agregarCola(Nodo *&frente, Nodo *&fin ,int dato){
    Nodo *nuevoNodo = new Nodo();
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;
    if(validarColaVacia(frente)){
        frente = nuevoNodo;
    } else{
        fin->siguiente = nuevoNodo;
    }
    fin = nuevoNodo;
}
bool validarColaVacia(Nodo *&frente){
    if(frente == NULL) {
        return true;
    }
    return false;
}
void suprimirCola(Nodo *&frente, Nodo *&fin,int &dato){
    Nodo *aux = frente;
    dato = aux->dato;
    if(frente == fin){
        frente = NULL;
        fin = NULL;
    }else{
        frente = frente->siguiente;
    }
    delete aux;
}