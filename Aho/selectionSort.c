#include <stdio.h>
#include <stdlib.h>

#define MAXVALUE 100
#define MINVALUE 0
#define DIML 200

typedef int IntArray[DIML];

int getRandomInt(int min, int max) {
    int range = max - min;
    int rnum = min + rand() % (range + 1);
    return rnum;
}

void createArray(IntArray arr, int dimL) {
    for (int i = 0; i < dimL; i++) {
        arr[i] = getRandomInt(MINVALUE, MAXVALUE);
    }
}

void selectionSort (IntArray arr) {
	//three index: first, next, small. u also need dimL
	int fst, next, small;
	//first iter, select first
	for (fst = 0; fst < DIML; fst++) {
		//second iter, select smallest
		small = fst;
		for (next = fst + 1; next < DIML; next++) {
			if (arr[next] < arr[small]) {
				small = next;
			}
		}
		//swap
		int temp = arr[fst];
		arr[fst] = arr[small];
		arr[small] = temp;
	}
}
void printArr(const IntArray arr, int dimL) {
    enum bool {FALSE, TRUE};
    enum bool jump = FALSE;
    for (int i = 0; i < dimL; i++) {
        printf("Value: %03d  ", arr[i]);
        if ((i % 10) == 0) {
			if (jump) {
				printf("\n");
			}
			jump = TRUE;
		}
    }
    printf("\n");
}

int main () {
    IntArray arr;
    createArray(arr, DIML);
    printf("Array before sorting:\n");
    printArr(arr, DIML);
    //SelectionSort(arr, DIML);
    selectionSort(arr);
    printf("Array after sorting:\n");
    printArr(arr, DIML);
    return 0;
}
