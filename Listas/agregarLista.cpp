#include <iostream>

using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};

void agregarLista(Nodo *&, int);
void mostrarLista(Nodo *&);
bool buscarDato(Nodo *&, int);
void popLista(Nodo *&, int);

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

void mostrarLista(Nodo *&lista){
    cout<<"Dato: "<<lista->dato;
    lista = lista->siguiente;
}
bool buscarDato(Nodo *&lista, int n){
    while(lista !=NULL){
        if(lista->dato == n){
            return true;
        }
        lista = lista->siguiente;
    }
    return false;
}

void popLista(Nodo *&lista, int dato){
    if(lista != NULL){
        Nodo *auxBorrar;
        Nodo *anterior = NULL;
        auxBorrar = lista;
        while(auxBorrar != NULL && auxBorrar->dato != dato){
            anterior = auxBorrar;
            auxBorrar = auxBorrar->siguiente;
        }
        if(auxBorrar == NULL){
            cout<<"No existe en la lista\n";
        }
        if(anterior == NULL){// esto quiere decir que el elemento a eliminar es el primero
            lista = lista->siguiente;
            delete auxBorrar;
        }else{
            anterior->siguiente = auxBorrar->siguiente;
            delete auxBorrar;
        }
    }
}

void eliminarListaCompleta(Nodo *&lista, int &n){
    Nodo *aux = lista;
    n = aux->dato;
    lista = aux->siguiente;
    delete aux;
}