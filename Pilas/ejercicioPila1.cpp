#include <iostream>
#include <string.h>

using namespace std;

struct NodoMinuscula{
    string pais;
    NodoMinuscula *siguiente;
};
struct NodoMayuscula{
    string paisMayus;
    NodoMayuscula *next;
};

void agregarPila(NodoMinuscula *&, string);
string mostrarPila(NodoMinuscula *&);
void agregarPilaMayus(NodoMayuscula *&, string);
void mostrarPilaMayus(NodoMayuscula *&);
string mayuscula(string);

int main(){
    system("cls");
    system("color 0A");
    NodoMinuscula *puntero = NULL;
    string nombrePais,paisM;
    string decision = "si";

    while(decision == "si" || decision == "Si"){
        cout<<"Ingrese nombre del pais\n";
        cin>>nombrePais;
        agregarPila(puntero,nombrePais);
        cout<<"Desea ingresar otro nombre?(si,no)\n";
        cin>>decision;
    }

    NodoMayuscula *punteroMayus = NULL;
    while(puntero != NULL){
        paisM = mostrarPila(puntero);
        paisM = mayuscula(paisM);
        agregarPilaMayus(punteroMayus,paisM);
        puntero = puntero->siguiente;
    }
    cout<<"\n-------------Pila2 con mayusculas---------------\n";
    while(punteroMayus != NULL){
        mostrarPilaMayus(punteroMayus);
    }

    return 0;
}

void agregarPila(NodoMinuscula *&puntero, string nombre){
    NodoMinuscula *nuevoNodo = new NodoMinuscula();
    nuevoNodo->pais = nombre;
    nuevoNodo->siguiente = puntero;
    puntero = nuevoNodo;

}

string mostrarPila(NodoMinuscula *&puntero){//aprovech� la funcion mostrar para sacar de una vez el pais
    cout<<"El pais :"<<puntero->pais<<"\n\t|\n\tY\n";
    return puntero->pais;
}

void agregarPilaMayus(NodoMayuscula*&puntero, string nombre){// es para el nodo en mayusculas
    NodoMayuscula *nuevoNodo = new NodoMayuscula();
    nuevoNodo->paisMayus = nombre;
    nuevoNodo->next = puntero;
    puntero = nuevoNodo;

}

void mostrarPilaMayus(NodoMayuscula *&puntero){// es para el nodo en mayusculas
    cout<<"El pais :"<<puntero->paisMayus<<"\n\t|\n\tY\n";
    puntero = puntero->next;
}


string mayuscula(string pais){
    for(int i = 0 ; i<pais.length(); i++){
        pais[i] = toupper(pais[i]);
    }
    return pais;
}

