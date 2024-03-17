#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "modules.h"


int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    // Generate a random value for n (between 1 and 5 in this example)
    int n = rand() % 5 + 1;
    printf("Number of lines: %d\n", n);

    // Generate a random value for k (between 0 and 30 in this example)
    int k = rand() % 31; // 31 to include 30
    printf("Number of people in the lines: %d\n", k);

    // Generate a random value for m (between 1 and 10 in this example)
    int m = rand() % 10 + 1;
    printf("Number of new people: %d\n", m);

    // Declare an array of integers of n dimensions
    int arr[n];

    // Fulfill the array with random proportions of k
    populateLine(arr, n, &k);

    // Print the elements of the array
    printf("Initial number of people in each line:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Calculate new people entering each line
    int min = 9999;
    calculateNewPeople(arr, n, &m, &min);

    // Print the updated elements of the array
    printf("Final number of people in each line after new arrivals:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

