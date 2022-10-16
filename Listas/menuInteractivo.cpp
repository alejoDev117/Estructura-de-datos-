#include <iostream>
#include <string>


using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};

void agregarLista(Nodo *&, int);
void mostrarLista(Nodo *&);
bool buscarDato(Nodo *&lista, int n);
void eliminarListaCompleta(Nodo *&, int&);
int main(){
    Nodo *lista = NULL;
    string menu = "\nMenu de Opciones\n1.agregar A lista\n2.Mostrar Lista\n3.Buscar dato\n4.Eliminarlista\n5.Salir\nR?->";
    int decision;
    bool seguir = true;
    while(seguir){
        cout<<menu;
        cin>>decision;
        switch (decision) {
            case 1: {
                int dato;
                cout << "Ingrese dato\n";
                cin>>dato;
                agregarLista(lista, dato);
                break;
            }
            case 2: {
                Nodo *aux = lista;
                mostrarLista(aux);
                break;
            }
            case 3: {
                Nodo *listaAux = lista;
                int datoBusqueda = 0;
                cout<<"Ingrese dato a buscar\n";
                cin>>datoBusqueda;
                if(buscarDato(listaAux,datoBusqueda)){
                    cout<<"El dato:["<<datoBusqueda<<"] si se encuentra en la lista\n";
                } else{
                    cout<<"El dato no fue encontrado\n";
                }
                break;
            }
            case 4: {
                int n;
                cout<<"Eliminando registros...\n";
                eliminarListaCompleta(lista, n);
                break;
            }
            case 5:{
                seguir = false;
                break;
            }
            default:
                cout<<"Opcion no valida, por favor vuelva a intentar\n";
        }
    }
    return 0;
}

void agregarLista(Nodo *&lista, int dato){
    Nodo *nuevoNodo = new Nodo();
    nuevoNodo->dato = dato;
    Nodo *aux1 = lista;
    Nodo *aux2;
    while(aux1 != NULL && aux1->dato < dato){
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }
    if(aux1 == lista){
        lista = nuevoNodo;
    } else{
        aux2->siguiente = nuevoNodo;
    }
    nuevoNodo->siguiente = aux1;
}
void mostrarLista(Nodo *&lista){
    string concateno;
    if(lista == NULL){
        cout<<"Lista vacia";
    }
    while(lista != NULL) {
       concateno += "["+to_string(lista->dato) + "]->";
        lista = lista->siguiente;
        if(lista == NULL){
            concateno += "NULL\n";
        }
    }
    cout<<concateno;
}

void eliminarListaCompleta(Nodo *&lista, int &n){
    while(lista != NULL){
        Nodo *aux = lista;
        n = aux->dato;
        lista = lista->siguiente;
        delete aux;
    }
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