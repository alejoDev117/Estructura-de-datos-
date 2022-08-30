#include <iostream>

using namespace std;

struct Nodo{ // creacion de un nodo
    int dato;
    Nodo *next;
};

void agregarPila(Nodo *&, int);//prototipar es decirle a c++ espeficiamente que funcion y que parametros va a tener en el main
void sacarPila(Nodo *&pila , int&);
void mostrarPila(Nodo *&);
int main(){

    system("cls");
    system("color 0A");


    Nodo *pila = NULL;
    Nodo *pilaMostrar;
    int n1;


    string decision = "si";

    while(decision == "si"){
        cout<<"Digite Numero\n";
        cin>>n1;
        agregarPila(pila,n1);
        cout<<"desea ingresar dato nuevo?\n(si-no)\n";
        cin>>decision;
    }


    pilaMostrar = pila;

    while(pilaMostrar != NULL){
        mostrarPila(pilaMostrar);
    }



    cout<<"Aqui sacamos nodos "<<endl;

    while(pila != NULL){
        sacarPila(pila,n1);
    }


    cout<<"\nFin\n";

    return 0;
}

void agregarPila(Nodo *&pila, int n){
    Nodo * nuevoNodo = new Nodo();// declaracion del nuevo nodo
    nuevoNodo -> dato = n;//al nodo le ingresamos el dato
    nuevoNodo -> next = pila;//a la parte siguiente del noto le asigno a donde va a apuntar(la primer vez va a null)
    pila = nuevoNodo;//por ultimo pila apuntara a mi nodo actual, asi el nuevo nodo apuntara a esta sucesivamente
}


void sacarPila(Nodo *&pila , int &n){
    Nodo * aux = pila;
    n = aux -> dato;
    pila = aux ->next;
    delete aux;
    cout<<" elemento sacado :"<<n<<" Siguiente nodo :"<<pila<<endl;


}
void mostrarPila(Nodo *&pila){
    cout<<" elemento :"<<pila->dato<<" en el nodo : "<<pila->next<<endl;
    pila = pila->next;
}
