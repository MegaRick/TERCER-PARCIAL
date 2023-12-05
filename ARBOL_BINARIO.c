#include <stdio.h>
#include <stdlib.h>
#include "validacion_caracteres.h"

struct Nodo{
	int dato;
	struct Nodo *der;
	struct Nodo *izq;	
};

//funcion para crear nodo
struct Nodo *crearNodo(int n){
	struct Nodo *nuevo_nodo = (struct Nodo *)malloc(sizeof(struct Nodo));
	nuevo_nodo->dato = n;
	nuevo_nodo->izq = NULL;
	nuevo_nodo->der = NULL;
	
	return nuevo_nodo;
}

//funcion insertar elementos en el arbol
void insertarNodo(struct Nodo **arbol, int n){
	if(*arbol == NULL){	//si no tiene elementos 
		struct Nodo *nuevo_nodo = crearNodo(n);
		*arbol = nuevo_nodo;
	}
	else{ 	//si tiene elementos 
		int valorRaiz = (*arbol) ->dato; //obtener valor de la raiz del arbol
		if(n < valorRaiz){	 //elemento menor a raiz, izquierda
			insertarNodo(&((*arbol)) -> izq, n);
		}
		else if (n > valorRaiz){	 //elemento mayor a raiz, derecha
			insertarNodo(&(*arbol) -> der, n);
		}
		else{
			printf("El elemento %d ya existe en el arbol.\n", n);
		}
	}
}

void mostrarArbol(struct Nodo *arbol){
	if(arbol != NULL){ 
	
		mostrarArbol(arbol-> izq);
		printf("%d ", arbol->dato); //imprimir valor del nodo actual
		mostrarArbol(arbol -> der);
					
	}
	
}

//creamos el arbol vacio 
struct Nodo *arbol = NULL;

int main(){
	int opcion = 3, dato;
	
	while(opcion != 0){
		printf("\n ARBOL BINARIO \n");
		printf("\n 1. Insertar elemento al arbol \n");
		printf("\n 2. Mostrarr arbol completo \n");
		printf("\n 0. Salir \n");
		printf("\n Seleccione una opcion: ");
		scanf("%d", &opcion);
		
		switch(opcion){
			case 1:
				dato = getEntero("Ingrese un numero entero: ");
				insertarNodo(&arbol, dato);
				printf("\n");
				system("pause");
				break;	
			case 2: 
				mostrarArbol(arbol);
				printf("\n");
				system("pause");
				break;		
		}	
		system("cls");		
	}
		
	return 0;
}