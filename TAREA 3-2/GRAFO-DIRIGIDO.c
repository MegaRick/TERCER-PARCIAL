//BETANZOS VAZQUEZ RICARDO
#include <stdio.h>
#include <stdlib.h>

//definicio de la estructura del nodo
struct Nodo{
	int dato;
	//struct Nodo* siguiente;
	//struct Nodo* anterior;	
	// Puntero a un array de punteros a nodos (para representar conexiones)
    struct Nodo** conexiones;
    int numConexiones;
};

////funcion para imprimir la lista en orden ascendente 
//void imprimirAscendente(struct Nodo* cabeza){
//	struct Nodo* actual = cabeza;
//	while (actual != NULL){
//		printf("%d ", actual -> dato);
//		actual = actual -> siguiente;
//	}
//	printf("\n");
//}
//
////funcion para imprimir la lista en orden descendente
//void imprimirDescendente(struct Nodo* cola){
//	struct Nodo* actual = cola;
//	while (actual != NULL){
//		printf("%d ", actual -> dato);
//		actual = actual -> anterior;
//	}
//	printf("\n");
//}

// Función para imprimir los vertices de un nodo
void imprimirConexiones(struct Nodo* nodo) {
    printf("Nodo %d se conecta con: ", nodo->dato);
    for (int i = 0; i < nodo->numConexiones; ++i) {
        printf("%d ", nodo->conexiones[i]->dato);
    }
    printf("\n");
}

int main(){
	//crear nodos
	struct Nodo* nodo1 = (struct Nodo*)malloc(sizeof(struct Nodo));
	struct Nodo* nodo2 = (struct Nodo*)malloc(sizeof(struct Nodo));
	struct Nodo* nodo3 = (struct Nodo*)malloc(sizeof(struct Nodo));
	struct Nodo* nodo4 = (struct Nodo*)malloc(sizeof(struct Nodo));
	struct Nodo* nodo5 = (struct Nodo*)malloc(sizeof(struct Nodo));
	//asignar valore s a los nodos 
	nodo1 -> dato = 2;
	nodo2 -> dato = 3;
	nodo3 -> dato = 5;
	nodo4 -> dato = 7;
	nodo5 -> dato = 11;
	
	//inicializar conexiones 
	nodo1->conexiones = (struct Nodo**)malloc(sizeof(struct Nodo*) * 2);
    nodo1->numConexiones = 2;
    nodo1->conexiones[0] = nodo2;
    nodo1->conexiones[1] = nodo5;
    
    nodo2->conexiones = (struct Nodo**)malloc(sizeof(struct Nodo*) * 2);
    nodo2->numConexiones = 2;
    nodo2->conexiones[0] = nodo3;
    nodo2->conexiones[1] = nodo1;
    
    nodo3->conexiones = (struct Nodo**)malloc(sizeof(struct Nodo*) * 2);
    nodo3->numConexiones = 2;
    nodo3->conexiones[0] = nodo4;
    nodo3->conexiones[1] = nodo2;
    
    nodo4->conexiones = (struct Nodo**)malloc(sizeof(struct Nodo*) * 2);
    nodo4->numConexiones = 2;
    nodo4->conexiones[0] = nodo5;
    nodo4->conexiones[1] = nodo3;
    
    nodo5->conexiones = (struct Nodo**)malloc(sizeof(struct Nodo*) * 2);
    nodo5->numConexiones = 2;
    nodo5->conexiones[0] = nodo1;
    nodo5->conexiones[1] = nodo4;
    
    // Imprimir conexiones
    printf("CONEXIONES DEL GRAFO \n");
    imprimirConexiones(nodo1);
    imprimirConexiones(nodo2);
    imprimirConexiones(nodo3);
    imprimirConexiones(nodo4);
    imprimirConexiones(nodo5);

	//liberar memoria
	free(nodo5->conexiones);
    free(nodo4->conexiones);
    free(nodo3->conexiones);
    free(nodo2->conexiones);
    free(nodo1->conexiones); 
	free(nodo5);
	free(nodo4);
	free(nodo3);
	free(nodo2);
	free(nodo1);
	
	return 0;
}
