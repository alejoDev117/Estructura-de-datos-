# include <iostream>
# include <conio.h>
//probando probamndo
using namespace std;

struct NodoLista{
    string pedido;
    int valorPedido;
    NodoLista *siguiente;
};

struct NodoCola{
    int turno;
	NodoLista *listaPedidos;
	NodoCola *siguiente;
};
struct nodoPila{
  string dato;
  nodoPila *siguiente;
};

void insertarCola(NodoCola *&,NodoCola*&,NodoLista*,int);
bool cola_vacia(NodoCola *);
void eliminarCola(NodoCola *&,NodoCola *&,NodoLista*&,int & );
NodoCola* buscarCliente(NodoCola *&,int);
void insertarLista(NodoLista*&,string,int);
void mostrarLista(NodoLista *&);
void mostrarCola(NodoCola *&);
void menu();
void impresionEmpresa();
void agregarPila (nodoPila *&pila, string);
void mostrarPila(nodoPila *&pila);

int main (){
	menu();
	getch();
	return 0;
}

void menu(){
	NodoCola *frenteCola = NULL;
	NodoCola *finCola = NULL;
    NodoLista *lista = NULL;
    nodoPila *pila = NULL;
	int dato,op=0,turno=1;
	do{cout<<"\t ------RESTAURANTE_EL_FOGON-----"<<endl<<endl;
	cout<<" Ingrese el numero segun la opcion : "<<endl;
	cout<<" (1). Ingreso para turnos."<<endl;
	cout<<" (2). Atender cliente de cola."<<endl;
	cout<<" (3). Generar Factura."<<endl;
	cout<<" (4). Generar Factura de todos los turnos."<<endl;
	cout<<" (5). Mostrar Pedidos Generados."<<endl;
    cout<<" (6). Salir"<<endl;
	cin>>op;
	switch (op) {
        case 1 : {
            string pedir, pedido;
            int valor;
            do {
                cout << "Ingrese pedido\n";
                cin >> pedido;
                cout << "Ingrese su valor\n";
                cin >> valor;
                insertarLista(lista, pedido, valor);
                agregarPila (pila,pedido);
                cout << "Desea ingresar otro pedido?(Si,No)\n";
                cin >> pedir;
            } while (pedir == "si" || pedir == "Si");
            cout << "numero de turno " << turno << endl;
            insertarCola(frenteCola, finCola, lista, turno);
            turno++;
            lista = NULL;
            break;
        }
        case 2: {
            cout << "Se atiende a cliente con turno: " << frenteCola->turno << endl;
            eliminarCola(frenteCola, finCola, frenteCola->listaPedidos,turno);
            break;
    }
    case 3:{
        NodoCola *clienteAFacturar;
        NodoCola *busqueda = frenteCola;
        int turnoFacturacion;
        cout<<"ingrese turno que desea generar factura\n";
        cin>>turnoFacturacion;
        clienteAFacturar = buscarCliente(busqueda,turnoFacturacion);
        mostrarLista(clienteAFacturar->listaPedidos);
        
        break;
    }
    case 4:{
        NodoCola *auxMostrar = frenteCola;
        mostrarCola(auxMostrar);
        break;
    }
    case 5:{
    	nodoPila *auxMostrar= pila;
    	mostrarPila (auxMostrar);
		break;
	}

		}
	}while (op!=6);

}

void insertarCola(NodoCola *& frenteCola, NodoCola *& finCola , NodoLista *listaPedidosCliente,int turno){
	NodoCola *nuevo_nodo = new NodoCola();
	nuevo_nodo->listaPedidos  = listaPedidosCliente;
    nuevo_nodo->turno = turno;
	nuevo_nodo->siguiente=NULL;
	if(cola_vacia(frenteCola)){
		frenteCola = nuevo_nodo;
	}else{
        finCola->siguiente =nuevo_nodo;
	}
	finCola = nuevo_nodo;
}

void eliminarCola(NodoCola *& frenteCola, NodoCola *& finCola, NodoLista *&listaPedidoCliente,int & turno){
    turno= frenteCola -> turno;
	NodoCola *aux=frenteCola;
	if(frenteCola == finCola){
		frenteCola=NULL;
		finCola=NULL;	
	}
	else{
        frenteCola = frenteCola->siguiente;
	}
	delete aux;
}

bool cola_vacia(NodoCola *frenteCola){
	if(frenteCola == NULL){
        return true;
    }
    else{
        return false;
    }
}

void insertarLista(NodoLista *&lista, string pedido,int valor){
    NodoLista *nuevoNodo = new NodoLista();
    nuevoNodo->pedido = pedido;
    nuevoNodo->valorPedido = valor;
    NodoLista *aux1 = lista;
    NodoLista *aux2;
    while(aux1 != NULL){
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }
    if(lista == aux1){
        lista = nuevoNodo;
    }else{
        aux2->siguiente = nuevoNodo;
    }
    nuevoNodo->siguiente = aux1;
}

NodoCola* buscarCliente(NodoCola *&colaEspera, int turno){
    while(colaEspera != NULL){
        if(colaEspera->turno == turno){
            return colaEspera;
        }
       colaEspera = colaEspera->siguiente;
    }
    return NULL;
}

void mostrarCola(NodoCola *&ColaClientes){
    while(ColaClientes != NULL){
        cout<<"Turno:"<<ColaClientes->turno<<endl;
        mostrarLista(ColaClientes->listaPedidos);
        ColaClientes = ColaClientes->siguiente;
    }
}

void mostrarLista(NodoLista *&listaPedidos){
    NodoLista *auxMostrarLista = listaPedidos;
    int totalPago = 0;
    impresionEmpresa();
    cout<<"\t$$Factura$$\n";
    while(auxMostrarLista != NULL){
    cout<<"\t"<<auxMostrarLista->pedido<<"..."<<auxMostrarLista->valorPedido<<"$"<<endl;
    totalPago += auxMostrarLista->valorPedido;
    auxMostrarLista = auxMostrarLista->siguiente;
    }
    cout<<"\t-----------------------------------\n"<<"\t Total a pagar: "<<totalPago<<"$"<<endl;
    cout<<"\n";
}
void impresionEmpresa(){
	cout<<"\t ------RESTAURANTE_EL_FOGON-----"<<endl<<endl;
	cout<<"\t  Nit:  890984746-7"<<endl;
	cout<<"\t  Direccion: Cra 46 #40B-50."<<endl;
	cout<<"\t  PBX:_________________."<<endl;
	cout<<"\t-----------------------------------"<<endl;
}
void agregarPila(nodoPila *&pila,string pedido){
  nodoPila *nuevo_nodo = new nodoPila();
  nuevo_nodo -> dato = pedido;
  nuevo_nodo -> siguiente=pila;
  pila= nuevo_nodo ;
  cout<<" Su Pedido "<<pedido<<" agregado. "<<endl;
}
void mostrarPila(nodoPila *&pila){
	while(pila!=NULL){		
		cout<<"elemento "<<pila->dato<<" eliminado "<<endl;
		pila = pila -> siguiente;
	}
}
