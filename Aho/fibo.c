#include <stdio.h>
#include <stdlib.h>

#define MAX_SEQUENCE 100

/*
int getRandomInt(int min, int max) {
    int range = max - min;
    int rnum = min + rand() % (range + 1);
    return rnum;
}
*/
int fibonacci(const int arr[], int num) {
	int res;
	if (num == 0) {
		res = 1;
	}
	else 
		if (num == 1) {
			res = 2;
		}
		else {
			res = arr[num-1] + arr[num-2];
		}
	return res;
}

void createFiboArray (int arr[], int n) {
	for (int i = 0; i < n; i++) {
		arr[i] = fibonacci(arr, i);
	}
}

void printArr(const int arr[], int dimL) {
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
    int arr[MAX_SEQUENCE];
    int n;
    printf("Enter the number of Fibonacci numbers to generate (up to %d): ", MAX_SEQUENCE);
    scanf("%d", &n);
    if (n > MAX_SEQUENCE || n <= 0) {
        printf("Invalid input. Please enter a number between 1 and %d\n", MAX_SEQUENCE);
        return 1;
    }

    createFiboArray(arr, n);

    printf("Fibonacci sequence of length %d:\n", n);
    printArr(arr, n);

    return 0;
}
