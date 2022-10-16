#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
struct  Nodo{
    float tempMin;
    float tempMax;
    string dia;
    Nodo *siguiente;
};
void agregarRegistro(Nodo  *&,float,float,string);
void promedioTempDia(Nodo *&);
int ordenDia(string);
string minuscula(string);
void busquedaPorTemp(float,Nodo *&);
void mostrarLista(Nodo *&);
void diaMasFrio(Nodo *&);

int main(){
    Nodo *lista = NULL;
    string dia;
    string seguir = "si";
    float min, max;
    do {
        cout<<"Ingrese dia\n";
        cin>>dia;
        cout<<"Ingrese temperatura minima\n";
        cin>>min;
        cout<<"Ingrese temperatura maxima\n";
        cin>>max;
        if(min<=max){
            agregarRegistro(lista, min, max, dia);
            cout<<"Mas?(si--no)\n";
            cin>>seguir;
        } else{
            cout<<"Error al ingresar las temperaturas,pruebe nuevamente\n";
        }
    }while(seguir == "si" || seguir == "Si");
    Nodo *uax = lista;
    promedioTempDia(uax);
    diaMasFrio(lista);
    return 0;
}
void agregarRegistro(Nodo *&lista, float minimo, float  maximo, string dia){
    Nodo *nuevoNodo = new Nodo();
    nuevoNodo->tempMin = minimo;
    nuevoNodo->tempMax = maximo;
    nuevoNodo->dia = minuscula(dia);
    Nodo *aux1 = lista;
    Nodo *aux2;
    while(aux1 != NULL && ordenDia(aux1->dia) < ordenDia(minuscula(dia)) ){
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

void promedioTempDia(Nodo *&lista){
    while(lista != NULL) {
        float promedio = (lista->tempMin + lista->tempMax)/2;
        cout<<lista->dia<<"Temperatura promedio:"<<fixed<<setprecision(1)<<promedio<<"Centigrados"<<endl;
        lista = lista->siguiente;
    }
}
void busquedaPorTemp(float tempAbuscar,Nodo *&lista){
    int conteo =0;
    Nodo *aux = lista;
    while(aux != NULL){
       if(tempAbuscar >=aux->tempMin && tempAbuscar <=aux->tempMax){
           cout<<aux->dia<<"\nminima:"<<aux->tempMin<<"\nmaxima:"<<aux->tempMax<<endl;
           conteo ++;
       }
       aux  =aux->siguiente;
    }
    if(conteo == 0){
        cout<<"Registros no encontrados\n";
        mostrarLista(lista);
    }
}
void mostrarLista(Nodo *&lista){
while(lista != NULL) {
    cout << lista->dia << "\nminimo:" << lista->tempMin << "\nmaxima:" << lista->tempMax << endl;
    lista = lista->siguiente;
    }
}
void diaMasFrio(Nodo *&lista){
   float menor = 999.9;
   Nodo *aux = lista;
   while(lista != NULL){
       if(lista->tempMin < menor){
           menor = lista->tempMin;
       }
       lista = lista->siguiente;
   }
   while(aux != NULL){
       if(aux->tempMin == menor){
           cout<<"El dia: "<<aux->dia<<" Hace mucho frio:"<<aux->tempMin<<endl;
       }
       aux = aux->siguiente;
   }
}
int ordenDia(string dia){
    string primerasLetras = "";
    int asignacion;
   primerasLetras = dia.substr(0,2); // las dos primeras letras
    if(primerasLetras == "lu"){// toco asi porque el switch puso error
        return asignacion = 1;
    } else if(primerasLetras == "ma"){
        return asignacion = 2;
    }else if(primerasLetras == "mi"){
        return asignacion = 3;
    }else if(primerasLetras == "ju"){
        return asignacion = 4;
    }else if(primerasLetras == "vi"){
        return asignacion = 5;
    }else if(primerasLetras == "sa"){
        return asignacion = 6;
    }else if(primerasLetras == "do"){
        return asignacion = 7;
    } else{
        return 0;
    }
}


string minuscula(string diaAMinuscula){
    for(int i = 0; i< diaAMinuscula.size() ; i ++){
        diaAMinuscula[i] = tolower(diaAMinuscula[i]);
    }
    return diaAMinuscula;
}