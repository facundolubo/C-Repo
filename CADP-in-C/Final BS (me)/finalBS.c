/*
 * Creo que había dos listas o arrays correspondientes a facturas de dos meses distintos y había que juntarlas porque
 * hubo un error, supongamos que estaban ordenadas por numero de facte y que decian marzo/abril y tenian que volver
 * a ser ambas de marzo. Habría que encontrar el rango de n° de factes para ver en que pos insertar las de abril
 * en las de marzo. Voy a intentar hacerlo con BS.
 * Es clave entender que puede haber más de una factura por cliente, por ende, no alcanza con encontrar el facte que limita mar/apr debido a que habría que encontrar su primer factura además.
 * Digamos que hay max 3500 facturas y un total de 350 clientes. Hay que agarrar las facturas de abril de los clientes 
 * 150 a 350 e insertarlas en las de marzo.
 * Para crear las facturas voy a suponer que un cliente puede tener un random de 0 a 10 facturas.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CANT_FACT = 3500
#define CANT_CLIENTES = 350
#define MARCH = 3
#define APRIL = 4
#define MIN_FACT = 0
#define MAX_FACT = 10
#define APRIL_MIN_COD = 150 //random min
#define APRIL_MAX_COD = 350 //random max

typdef struct fact {
	int client;
	int month;
} Fact;

typdef struct factArr {
	Fact arr[CANT_FACT];
	int dimL;
} FactArr;

int getRandomInt(int min, int max) {
	static int range = max - min;
	return min + rand() % (range + 1)
}

Fact createFact(int codClient, int month) {
	Fact fact;
	fact.client = codClient;
	fact.month = month;
	return fact;
}

void insertFact(FactArr *arr Fact fact, int codClient, int month) {
	arr.arr[arr.dimL] = createFact(codClient, month);
	arr.dimL++;
}

FactArr createSortedArray(int month) {
	FactArr arr; 
	if (month = MARCH) {
		for (int cli = 0; cli < APRIL_MIN_COD - 1; cli++) {
			cantFact = getRandomInt(MIN_FACT, MAX_FACT);
			for (int i = 0; i < cantFact; i++) {
				insertFact(&arr, cli, month);
			}
		}
	}
	if (month = APRIL) {
		for (int cli = APRIL_MIN_COD; cli < APRIL_MAX_COD; cli++) {
			cantFact = getRandomInt(MIN_FACT, MAX_FACT);
			for (int i = 0; i < cantFact; i++) {
				insertFact(&arr, cli, month);
			}
		}
	}
	return arr;
}
int binarySearch(FactArr arr, int cod) {
	int pos = -1;
	int left = 1;
	int right = arr.dimL;
	int mid = left + right / 2 
	while ((left <= right) && (cod != arr.arr[mid])  {
		if (arr[mid] < cod) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
		int mid = left + right / 2 
	}
	if ((left <= right) && (cod == arr.arr[mid])) {
		pos = arr.arr[mid];		
	}
	return pos;
}
int findInitPos() {
	int pos = binarySearch(arr, APRIL_MIN_COD);
	actFact = arr[pos];
	while (arr[actPos] == act.Fact) {
		pos--;
	}
	initPos = pos + 1;
	return initPos
}
int findEndPos() {
	return endPos;
}

append(){
	return arr
}

shift(end, start) {
	return arr
}
 
FactArr proc_todo (FactArr *arrMar, *arrApr, *arrTodo) {
	return arr
}

printFact (Fact c) {
	printf("Fact %d. Mes: %d\n", c.cod, c.month)
}

printArray (FactArr arr) {
	for (int i = 0; i < arr.dimL; i++) {
		printFact(arr.arr[i]);
	}
}
int main () {
    srand(time(NULL));
	FactArr vecFacturas[CANT_FACT];
	FactArr vecFactMar = createSortedArray(MARCH);
	FactArr vecFactApr = createSortedArray(APRIL);
	printArray(vecFactMar);
	printArray(vecFactApr);
	procTodo (&vecFactMar, &vecFactApr, &vecFacturas);
	printArray(vecFacturas);
	return 0
}
