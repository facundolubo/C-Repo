<<<<<<< HEAD
/*
 * Creo que había dos listas o arrays correspondientes a facturas de dos meses distintos y había que juntarlas porque
 * hubo un error, supongamos que estaban ordenadas por numero de facte y que decian marzo/abril y tenian que volver
 * a ser ambas de marzo. Habría que encontrar el rango de n° de factes para ver en que pos insertar las de abril
 * en las de marzo. Voy a intentar hacerlo con BS.
 * Es clave entender que puede haber más de una factura por cliente, por ende, no alcanza con encontrar el facte que limita mar/apr debido a que habría que encontrar su primer factura además.
 * Digamos que hay max 3500 facturas y un total de 350 clientes. Hay que agarrar las facturas de abril de los clientes 
 * 150 a 350 e insertarlas en las de marzo.Supondremos que esos clientes de abril faltan en marzo.
 * Para crear las facturas voy a suponer que un cliente puede tener un random de 0 a 10 facturas.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CANT_FACT 350
#define CANT_CLIENTES 35
#define MARCH 3
#define APRIL 4
#define MIN_FACT 0
#define MAX_FACT 3
#define APRIL_MIN_COD 15 //random min
#define APRIL_MAX_COD 35 //random max

typedef struct fact {
	int id;
	int client;
	int month;
} Fact;

typedef struct factArr {
	Fact arr[CANT_FACT];
	int dimL;
} FactArr;

int getRandomInt(int min, int max) {
	int range = max - min;
	return min + rand() % (range + 1);
}

Fact createFact(int codClient, int month) {
	int static n = 1;
	Fact fact;
	fact.id = n;
	fact.client = codClient;
	fact.month = month;
	n++;
	return fact;
}

FactArr insertFact(FactArr arr, int codClient, int month) {
	arr.arr[arr.dimL] = createFact(codClient, month);
	arr.dimL++;
	return arr;
}

FactArr createSortedArray(int month) {
	FactArr arr; 
	arr.dimL = 0;
	if (month == MARCH) {
		//printf("Month: %d", month);
		for (int cli = 0; cli < APRIL_MIN_COD - 1; cli++) {
			int cantFact = getRandomInt(MIN_FACT, MAX_FACT);
			//printf("cantFact: %d", cantFact);
			for (int i = 0; i < cantFact; i++) {
				arr = insertFact(arr, cli, month);
			}
		}
	}
	if (month == APRIL) {
		//printf("Month: %d", month);
		for (int cli = 0; cli < APRIL_MAX_COD; cli++) {
			int cantFact = getRandomInt(MIN_FACT, MAX_FACT);
			//printf("cantFact: %d", cantFact);
			for (int i = 0; i < cantFact; i++) {
				arr = insertFact(arr, cli, month);
			//	printf("Factura insertada...");
			}
		}
	}
	return arr;
}

int binarySearch(FactArr arr, int cod) {
    int pos = -1;
    int left = 0;
    int right = arr.dimL - 1;

    while (left <= right && pos == -1) {
        int mid = left + (right - left) / 2;
        if (arr.arr[mid].client == cod) {
            pos = mid;
        } else if (arr.arr[mid].client < cod) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return pos;
}

int binarySearch2 (FactArr arr, int cod) {
	int pos = -1;
	int low = 0;
	int high = arr.dimL -1;
	while (low != high) {
        int mid = (low + high) / 2;
		if (cod < arr.arr[mid].client) {
			high = mid - 1;
		}
		else low = mid;
	}
	if (arr.arr[low].client == cod) {
		pos = low;
	}
	return pos;
}
int findInitPos(FactArr arr) {
	int pos = binarySearch2(arr, APRIL_MIN_COD);
	Fact actFact = arr.arr[pos];
	while (arr.arr[pos].client == actFact.client) {
		pos--;
	}
	int initPos = pos;
	printf("Init Pos: %d\n", initPos);
	return initPos;
}

int findEndPos(FactArr arr) {
	int endPos = arr.dimL;
	printf("End Pos: %d\n", endPos);
	return endPos;
}

FactArr merge(FactArr arrMar, FactArr arrApr){
	FactArr mergedArr;
	mergedArr.dimL = 0;
	printf("Dim Log of arrMar %d\n", arrMar.dimL);
	printf("Dim Log of arrApr %d\n", arrApr.dimL);
	for (int i = 0; i < arrMar.dimL; i++) {
		mergedArr.arr[i] = arrMar.arr[i];
		mergedArr.dimL++;
	}
	printf("Marzo copiado...\n");
	int endPos = findEndPos(arrApr);
	int initPos = findInitPos(arrApr);
	for (int i = initPos, j = mergedArr.dimL; i < endPos; i++, j++) {
		mergedArr.arr[j] = arrApr.arr[i];
		mergedArr.dimL++;
	}
	printf("Abril copiado...\n");
	printf("Dim Log of arrFinal %d\n", mergedArr.dimL);
	return mergedArr;
}

void printFact (Fact c) {
	printf("Id %d. Client %d. Mes: %d\n", c.id, c.client, c.month);
}

void printArray (FactArr arr) {
	printf("Print array of dimL: %d\n", arr.dimL);
	for (int i = 0; i < arr.dimL; i++) {
		printFact(arr.arr[i]);
	}
	printf("\n");
}
int main () {
    srand(time(NULL));
	FactArr vecFactMar = createSortedArray(MARCH);
	FactArr vecFactApr = createSortedArray(APRIL);
	printArray(vecFactMar);
	printf("\n");
	printf("\n");
	printArray(vecFactApr);
	printf("\n");
	printf("\n");
	FactArr vectFactFinal = merge(vecFactMar, vecFactApr);
	printf("\n");
	printf("\n");
	printArray(vectFactFinal);

	return 0;
}
=======
/*
 * Creo que había dos listas o arrays correspondientes a facturas de dos meses distintos y había que juntarlas porque
 * hubo un error, supongamos que estaban ordenadas por numero de facte y que decian marzo/abril y tenian que volver
 * a ser ambas de marzo. Habría que encontrar el rango de n° de factes para ver en que pos insertar las de abril
 * en las de marzo. Voy a intentar hacerlo con BS.
 * Es clave entender que puede haber más de una factura por cliente, por ende, no alcanza con encontrar el facte que limita mar/apr debido a que habría que encontrar su primer factura además.
 * Digamos que hay max 3500 facturas y un total de 350 clientes. Hay que agarrar las facturas de abril de los clientes 
 * 150 a 350 e insertarlas en las de marzo.Supondremos que esos clientes de abril faltan en marzo.
 * Para crear las facturas voy a suponer que un cliente puede tener un random de 0 a 10 facturas.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CANT_FACT 3500
#define CANT_CLIENTES 350
#define MARCH 3
#define APRIL 4
#define MIN_FACT 0
#define MAX_FACT 10
#define APRIL_MIN_COD 150 //random min
#define APRIL_MAX_COD 350 //random max

typedef struct fact {
	int client;
	int month;
} Fact;

typedef struct factArr {
	Fact arr[CANT_FACT];
	int dimL;
} FactArr;

int getRandomInt(int min, int max) {
	int range = max - min;
	return min + rand() % (range + 1);
}

Fact createFact(int codClient, int month) {
	Fact fact;
	fact.client = codClient;
	fact.month = month;
	return fact;
}

FactArr insertFact(FactArr arr, int codClient, int month) {
	arr.arr[arr.dimL] = createFact(codClient, month);
	arr.dimL++;
	return arr;
}

FactArr createSortedArray(int month) {
	FactArr arr; 
	arr.dimL = 0;
	if (month == MARCH) {
		//printf("Month: %d", month);
		for (int cli = 0; cli < APRIL_MIN_COD - 1; cli++) {
			int cantFact = getRandomInt(MIN_FACT, MAX_FACT);
			//printf("cantFact: %d", cantFact);
			for (int i = 0; i < cantFact; i++) {
				arr = insertFact(arr, cli, month);
			}
		}
	}
	if (month == APRIL) {
		//printf("Month: %d", month);
		for (int cli = 0; cli < APRIL_MAX_COD; cli++) {
			int cantFact = getRandomInt(MIN_FACT, MAX_FACT);
			//printf("cantFact: %d", cantFact);
			for (int i = 0; i < cantFact; i++) {
				arr = insertFact(arr, cli, month);
			//	printf("Factura insertada...");
			}
		}
	}
	return arr;
}

int binarySearch(FactArr arr, int cod) {
    int pos = -1;
    int left = 0;
    int right = arr.dimL - 1;

    while (left <= right && pos == -1) {
        int mid = left + (right - left) / 2;

        if (arr.arr[mid].client == cod) {
            pos = mid;
        } else if (arr.arr[mid].client < cod) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return pos;
}


int findInitPos(FactArr arr) {
	int pos = binarySearch(arr, APRIL_MIN_COD);
	Fact actFact = arr.arr[pos];
	while (arr.arr[pos].client == actFact.client) {
		pos--;
	}
	int initPos = pos;
	printf("Init Pos: %d\n", initPos);
	return initPos;
}

int findEndPos(FactArr arr) {
	int endPos = arr.dimL;
	printf("End Pos: %d\n", endPos);
	return endPos;
}

FactArr merge(FactArr arrMar, FactArr arrApr){
	FactArr mergedArr;
	mergedArr.dimL = 0;
	printf("Dim Log of arrMar %d\n", arrMar.dimL);
	printf("Dim Log of arrApr %d\n", arrApr.dimL);
	for (int i = 0; i < arrMar.dimL; i++) {
		mergedArr.arr[i] = arrMar.arr[i];
		mergedArr.dimL++;
	}
	printf("Marzo copiado...\n");
	int endPos = findEndPos(arrApr);
	int initPos = findInitPos(arrApr);
	for (int i = initPos, j = mergedArr.dimL; i < endPos; i++, j++) {
		mergedArr.arr[j] = arrApr.arr[i];
		mergedArr.dimL++;
	}
	printf("Abril copiado...\n");
	printf("Dim Log of arrFinal %d\n", mergedArr.dimL);
	return mergedArr;
}

void printFact (Fact c) {
	printf("Fact %d. Mes: %d ", c.client, c.month);
}

void printArray (FactArr arr) {
	printf("Print array of dimL: %d\n", arr.dimL);
	for (int i = 0; i < arr.dimL; i++) {
		printFact(arr.arr[i]);
	}
	printf("\n");
}
int main () {
    srand(time(NULL));
	FactArr vecFactMar = createSortedArray(MARCH);
	FactArr vecFactApr = createSortedArray(APRIL);
	printArray(vecFactMar);
	printf("\n");
	printf("\n");
	printArray(vecFactApr);
	printf("\n");
	printf("\n");
	FactArr vectFactFinal = merge(vecFactMar, vecFactApr);
	printf("\n");
	printf("\n");
	printArray(vectFactFinal);

	return 0;
}
>>>>>>> 2fa911f (final BS)
