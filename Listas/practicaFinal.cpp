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
void menu();



int main(){
    system("cls");
    system("color 0A");
    menu();
    return 0;
}

void menu(){
    int op;
    Nodo *lista = NULL;
    do{
        cout<<"\t.: MENU :."<<endl;
        cout<<"1.Insertar dias en la lista."<<endl;
        cout<<"2.Mostrar temperatura promedio por dia."<<endl;
        cout<<"3.Mostrar dias de la lista."<<endl;
        cout<<"4.Buscar dia por temperatura."<<endl;
        cout<<"5.Dia mas frio."<<endl;
        cout<<"6.Salir."<<endl;
        cout<<"Opcion: ";
        cin>>op;
        cout<<"\n";

        switch(op) {
            case 1: {
                string dia;
                string seguir = "si";
                float min, max;
                do {
                    cout << "Ingrese un dia: \n";
                    cin >> dia;
                    cout << "\n";
                    cout << "Ingrese la temperatura minima del " << dia << ":\n";
                    cin >> min;
                    cout << "\n";
                    cout << "Ingrese la temperatura maxima del " << dia << ":\n";
                    cin >> max;
                    cout << "\n";
                    if (min <= max) {
                        agregarRegistro(lista, min, max, dia);
                        cout << "¿Desea añadir mas dias? (Opciones: Si --- No):\n";
                        cin >> seguir;
                        cout << "\n";
                    } else {
                        cout << "\t¡ERROR: La temperatura maxima no puede ser inferior a la minima!\n";
                        cout << "\tVuelve a intentar.\n\n";
                    }
                } while (seguir == "si" || seguir == "Si");
                while (getchar() != '\n');
                getchar();
                break;
            }
            case 2:{
                Nodo *auxPromedio = lista;
                promedioTempDia(auxPromedio);
                break;
            }
            case 3: {
                Nodo *auxMostrar = lista;
                mostrarLista(auxMostrar);
                while (getchar() != '\n');
                getchar();
                break;
            }
            case 4: {
                Nodo *auxBusqueda = lista;
                float tempAbuscar;
                cout << "\nIngresa la temperatura que desea buscar:\n";
                cin >> tempAbuscar;
                busquedaPorTemp(tempAbuscar, auxBusqueda);
                while (getchar() != '\n');
                getchar();
                break;
        }
        case 5: {
            Nodo *auxDiaFrio = lista;
            diaMasFrio(auxDiaFrio);
            break;
        }
        case 6:{
            op = 6;
            break;
            }
        }
    }while(op!=6);
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
        cout<<lista->dia<<" temperatura promedio:"<<fixed<<setprecision(1)<<promedio<<" C."<<endl;
        lista = lista->siguiente;
    }
}

void busquedaPorTemp(float tempAbuscar,Nodo *&lista){
    int conteo =0;
    Nodo *aux = lista;
    while(aux != NULL){
       if(tempAbuscar >=aux->tempMin && tempAbuscar <=aux->tempMax){
           cout<<"#"<<aux->dia<<"#"<<"\nMinima:"<<aux->tempMin<<"\nMaxima:"<<aux->tempMax<<endl;
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
    cout <<"#"<<lista->dia<<"#"<< "\nTemp Minima: " << lista->tempMin <<" C."<<"\nTemp Maxima: " << lista->tempMax<<" C.\n"<<endl;
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
           cout<<aux->dia<<" es el día con la temperatura mas baja registrada: "<<aux->tempMin<<" C."<<endl;
       }
       aux = aux->siguiente;
   }
}
int ordenDia(string dia){
    string primerasLetras = "";
    int asignacion;
   primerasLetras = dia.substr(0,2);
    if(primerasLetras == "lu"){
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
