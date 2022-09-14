#include <iostream>

using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};

void agregarLista(Nodo *&, int);

int main(){
    Nodo *lista = NULL;

    return 0;
}

void agregarLista(Nodo *&lista, int dato){
    Nodo *nuevoNodo = new Nodo();
    nuevoNodo->dato = dato;
    Nodo *aux1 = lista;
    Nodo *aux2;
    while(aux1 != NULL && aux1->dato < dato ){
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }
    if(lista == aux1){
        lista = nuevoNodo;
    } else{
        aux2->siguiente = nuevoNodo;
    }
    nuevoNodo->siguiente = aux1;
}