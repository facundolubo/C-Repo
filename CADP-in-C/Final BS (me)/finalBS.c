/*
 * Creo que había dos listas o arrays correspondientes a facturas de dos meses distintos y había que juntarlas porque
 * hubo un error, supongamos que estaban ordenadas por numero de cliente y que decian marzo/abril y tenian que volver
 * a ser ambas de marzo. Habría que encontrar el rango de n° de clientes para ver en que pos insertar las de abril
 * en las de marzo. Voy a intentar hacerlo con BS
 * */

#include <stdio.h>

#define CANT_CLIENTES = 2500
#define MARCH = 3
#define APRIL = 4
#define APRIL_MIN_COD = 788 //random min
#define APRIL_MIN_COD = 1492 //random max

typdef struct client {
	int cod;
	int month;
} Client;

typdef struct clientArr {
	Client arr[CANT_CLIENTES];
	int dimL;
} ClientArr;

Client createClient() {
	Client client;
	return client;
}

void insertClient(ClientArr *arr Client client) {
	arr.arr 
	arr.dimL++;

}

ClientArr createSortedArray(int month) {
	ClientArr arr; 
	Client client = createClient();

	if month = MARCH {
	for (int i = 0; i < CANT_CLIENTES; i++) {
		insertClient(&arr &client);
	}
	}
	if month = APRIL {
	}

	return arr;
}
int binarySearch() {
	return pos;
}
findInitPos() {
	int pos = binarySearch();
	return initPos;
}
findEndPos() {
	return endPos;
}

append(){
	return arr
}
shift(end, start) {
	return arr
}

printArray
int main () {
	ClientArr vecFacturas[CANT_CLIENTES];
	ClientArr vecFactMar = createSortedArray();
	ClientArr vecFactApr = createSortedArray();
		
	return 0
}
