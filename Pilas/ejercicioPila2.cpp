#include <iostream>

using namespace std;

struct Nodo{
	int facturaPagada;
	Nodo *siguiente;
};
void mostrarPila(Nodo *&);
void agregarPila(Nodo*&,int);
void quitarPila(Nodo*&,int &);
int operacionPila(Nodo*&);
int main(){
	system("cls");
	system("color 0B");
	Nodo *puntero = NULL;
	int decision = 0;
	while(decision !=6){
		cout<<"Menu de opciones\n1.Agregar factura pagada\n2.Eliminar Ultimo regisro\n3.mostrar pila de pagos\n";
		cout<<"4.Total pagos del mes\n5.Promedio\n6.salir\n";
		cin>>decision;
		switch (decision){
			case 1:{
				int pago;
				cout<<"Ingrese monto pagado\n";
				cin>>pago;
				agregarPila(puntero,pago);
				break;
			}
			case 2:{
				int n;
				quitarPila(puntero,n);
				break;
			}
			case 3:{
				Nodo *aux = puntero;
				while(aux != NULL){
					mostrarPila(aux);
			    }
			    if(puntero == NULL){
			    	cout<<"NULL\n";
				}
				break;
			}
			case 4:{
				int suma = 0;
				Nodo *auxSuma = puntero;
				while(auxSuma != NULL){
					suma += operacionPila(auxSuma);
					auxSuma = auxSuma->siguiente;
				}
				cout<<"El total es:"<<suma<<" $"<<endl;
				break;
			}
			case 5:{
				int suma = 0;
				int cantidadDato = 0;
				Nodo *auxSuma = puntero;
				while(auxSuma != NULL){
					suma += operacionPila(auxSuma);
					auxSuma = auxSuma->siguiente;
					cantidadDato++;
				}
				if(cantidadDato != 0){
					float promedio = suma/cantidadDato;
					cout<<"Promedio es:"<<promedio<<" $"<<endl;
				}else{
					cout<<"Error no hay datos\n";
				}
				break;
			}
			case 6:{
				decision = 6;
				break;
			}
			default:
				cout<<"Error opcion no valida\n";
		}
		
	}
	
	return 0;
}

void agregarPila(Nodo *&puntero, int numero){
	Nodo *nuevoNodo = new Nodo();
	nuevoNodo->facturaPagada = numero;
	nuevoNodo->siguiente = puntero;
	puntero = nuevoNodo;
	
}
void mostrarPila(Nodo *&puntero){
	cout<<"Monto :"<<puntero->facturaPagada<<" $"<<"\n\t|\n\tY"<<endl;
	puntero = puntero->siguiente;
}
void quitarPila(Nodo *&puntero, int &n){
    Nodo *aux = puntero;
    n = aux->facturaPagada;
    puntero = aux->siguiente;
    delete aux;
}

int operacionPila(Nodo *&puntero){
	return puntero->facturaPagada;
}
