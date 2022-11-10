//Facultad de Ciencias de la Computación BUAP
//EQUIPO 6
#include <iostream>
#include <cstdlib>

using namespace std;

struct nodo {
	int dato; //Valor del nodo (entero)
	struct nodo* izq, * der; //Hijos del nodo
};

typedef struct nodo* NDO;
/* es un puntero de tipo nodo que hemos llamado NDO, que ulitizaremos
   para mayor facilidad de creacion de variables */

   //Funcion que recibe como parametro un entero, el cual sera el valor del nuevo nodo
NDO crearNodo(int x) {
	NDO nuevoNodo = new(struct nodo); //Creamos el espacio para el nodo nuevo
	nuevoNodo->dato = x; //En el nodo actual, asignamos el valor
	//En el nodo actual, creamos dos hijos para cada lado del nodo
	nuevoNodo->izq = NULL;
	nuevoNodo->der = NULL;
	return nuevoNodo; //Devolvemos el nodo
}

//Insertar nodos
void insertar(NDO& arbol, int x) {
	if (arbol == NULL) { //Verificamos si el arbol esta vacio
		arbol = crearNodo(x); //Si lo está, creamos un nodo
	}
	//si no lo esta...
	else if (x < arbol->dato) // Si el dato es menor que la raiz
		insertar(arbol->izq, x); //Nos dirigimos a la IZQUIERDA y guardamos el dato cuando arbol->izq == NULL
	else if (x > arbol->dato) // Si el dato es mayor que la raiz
		insertar(arbol->der, x); //Nos dirigimos a la DERECHA y guardamos el dato cuando arbol->der == NULL
}

//Recorrido a lo ancho (Breadth First Search)
void preOrden(NDO arbol) {
	if (arbol != NULL) { //Si el nodo actual no es NULL...
		cout << arbol->dato << "  "; //Imprimimos el nodo actual
		preOrden(arbol->izq); //Recursivamente nos dirigimos al lado IZQUIERDO del nodo e imprimimos los valores
		//							 se encuentren hasta que arbol->izq == NULL, despues, terminamos todas las funciones
		//							 recursivas actuales hasta regresar a la primera función.
		preOrden(arbol->der); //Recursivamente nos dirigimos al lado DERECHO del nodo e imprimimos los valores
		//							 se encuentren hasta que arbol->der == NULL, despues, terminamos todas las funciones
		//							 recursivas actuales hasta regresar a la primera función.		
	}
}

//Recorrido EnOrden
void enOrden(NDO arbol) {
	if (arbol != NULL) { //Si el nodo actual no es NULL...
		enOrden(arbol->izq); //Recursivamente nos dirigimos al lado IZQUIERDO del nodo e imprimimos los valores
		//							 se encuentren hasta que arbol->izq == NULL, despues, terminamos todas las funciones
		//							 recursivas actuales hasta regresar a la primera función.
		cout << arbol->dato << "  "; //Imprimimos el nodo actual
		enOrden(arbol->der); //Recursivamente nos dirigimos al lado DERECHO del nodo e imprimimos los valores
		//							 se encuentren hasta que arbol->der == NULL, despues, terminamos todas las funciones
		//							 recursivas actuales hasta regresar a la primera función.		
	}
}

//Recorrido postOrden
void postOrden(NDO arbol) {
	if (arbol != NULL) { //Si el nodo actual no es NULL...
		postOrden(arbol->izq); //Recursivamente nos dirigimos al lado IZQUIERDO del nodo e imprimimos los valores
		//							 se encuentren hasta que arbol->izq == NULL, despues, terminamos todas las funciones
		//							 recursivas actuales hasta regresar a la primera función.
		postOrden(arbol->der); //Recursivamente nos dirigimos al lado DERECHO del nodo e imprimimos los valores
		//							 se encuentren hasta que arbol->der == NULL, despues, terminamos todas las funciones
		//							 recursivas actuales hasta regresar a la primera función.		
		cout << arbol->dato << "  "; //Imprimimos el nodo actual
	}
}

//Funcion para mostrar el arbol
void verArbol(NDO arbol, int n) {
	if (arbol == NULL) {
		return;
	}
	verArbol(arbol->der, n + 1);
	for (int i = 0; i < n; i++) {
		cout << "\t";
	}
	cout << " " << arbol->dato << endl;
	verArbol(arbol->izq, n + 1);
}

int main() {
	NDO arbol = NULL;   //Creación del arbolungo

	int n; //Numero de nodos del arbol
	int x; //Elemento a insertar en cada nodo

	cout << "\n\t - - - - - GRAFUNGO BINARIO - - - - - \n\n";
	cout << " NUMERO DE NODOS: ";
	cin >> n;
	cout << endl;

	//Tabla de ingreso de nodos
	cout << "\t NODO " << "| VAL " << endl;
	for (int i = 0; i < n; i++) {
		cout << "\t  #" << i + 1 << "  | "; //Indicador en que nodo estamos
		cin >> x; //Valor de entrada
		insertar(arbol, x);
	}

	//Mostrando el arbol...
	cout << "\n ARBOL GENERADO \n\n";
	verArbol(arbol, 0);

	//Recorrido preOrden
	cout << "\n\n PreOrden: ";
	preOrden(arbol);
	cout << endl << endl;

	//Recorrido enOrden
	cout << "\n\n enOrden: ";
	enOrden(arbol);
	cout << endl << endl;

	//Recorrido postOrden
	cout << "\n\n postOrden: ";
	postOrden(arbol);
	cout << endl << endl;

	system("pause");
	return 0;
}