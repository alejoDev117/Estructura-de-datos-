#include <iostream>
#include <stdlib.h>

using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};
void agregarPila(Nodo *&, int);
void mostrarPila(Nodo *&);
void menuOpciones();
char minuscula(char);

int main(){
    Nodo *pila = NULL;
    char decisionMenu = 'n';
    int dato;
    while(decisionMenu != 'c'){
        menuOpciones();
        cin>>decisionMenu;
        decisionMenu = minuscula(decisionMenu);
        switch (decisionMenu) {
            case 'a': {
                string decisionInsertar = "si";
                while (decisionInsertar == "si" || decisionInsertar == "Si") {
                    cout << "Ingrese elemento\n";
                    cin >> dato;
                    agregarPila(pila, dato);
                    cout << "desea ingresar otro?(si,no)\n";
                    cin >> decisionInsertar;
                }
                break;
            }
            case 'b': {
                Nodo *auxMostrar = pila;
                while (auxMostrar != NULL) {
                    mostrarPila(auxMostrar);
                }
                break;
            }
            case 'c': {
                decisionMenu = 'c';
                break;
            }
            default:
                cout<<"Error opcion no valida\n";
        }
    }
    return 0;
}

void agregarPila(Nodo *&pila, int dato){
    Nodo *nuevoNodo = new Nodo();
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = pila;
    pila = nuevoNodo;
}
void mostrarPila(Nodo *&pila){
    cout<<"Dato: "<<pila->dato<<endl<<"\t|\n\tV"<<endl;
    pila = pila->siguiente;
    if(pila == NULL){
        cout<<"\tNULL\n";
    }
}
void menuOpciones(){
    cout<<"Menu de opciones\n"<<"a.Insertar Nuevo Elemento\n"<<"b.visualizar Pila\nc.Salir\n";
}
char minuscula(char decision){
     return decision = tolower(decision);
}