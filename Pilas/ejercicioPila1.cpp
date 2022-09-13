#include <iostream>
#include <string.h>

using namespace std;

struct Nodo{
    string pais;
    Nodo *siguiente;
};


void agregarPila(Nodo *&, string);
string mostrarPila(Nodo *&);
string mayuscula(string);

int main(){
    Nodo *punteroMinuscula = NULL;
    string nombrePais,paisM;
    string decision = "si";

    while(decision == "si" || decision == "Si"){
        cout<<"Ingrese nombre del pais\n";
        cin>>nombrePais;
        agregarPila(punteroMinuscula,nombrePais);
        cout<<"Desea ingresar otro nombre?(si,no)\n";
        cin>>decision;
    }

    Nodo *punteroMayuscula = NULL;
    while(punteroMinuscula != NULL){
        paisM = mostrarPila(punteroMinuscula);
        paisM = mayuscula(paisM);
        agregarPila(punteroMayuscula , paisM);
        punteroMinuscula = punteroMinuscula->siguiente;
    }
    cout<<"\n-------------Pila2 con mayusculas---------------\n";
    while(punteroMayuscula != NULL){
        mostrarPila(punteroMayuscula);
        punteroMayuscula = punteroMayuscula->siguiente;
    }

    return 0;
}

void agregarPila(Nodo *&puntero, string nombre){
    Nodo *nuevoNodo = new Nodo();
    nuevoNodo->pais = nombre;
    nuevoNodo->siguiente = puntero;
    puntero = nuevoNodo;

}

string mostrarPila(Nodo *&puntero){//aprovech� la funcion mostrar para sacar de una vez el pais
    cout<<"El pais :"<<puntero->pais<<"\n\t|\n\tY\n";
    return puntero->pais;
}

string mayuscula(string pais){
    for(int i = 0 ; i<pais.length(); i++){
        pais[i] = toupper(pais[i]);
    }
    return pais;
}

