#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cov.h"

#define N 10  // Number of temperature readings

// Function to print a 2D array
void printArray(double arr[][2], int size) {
    for (int i = 0; i < size; i++) {
        printf("Value: %lf, Weight: %lf\n", arr[i][0], arr[i][1]);
    }
}

int main() {
    srand(time(NULL));  // Seed the random number generator
	// Array arrA (10x2)
    double arrA[10][2] = {
        {5.0, 0.10}, {3.2, 0.15}, {7.1, 0.05}, {8.3, 0.12},
        {2.9, 0.08}, {4.4, 0.10}, {6.8, 0.07}, {9.0, 0.09},
        {1.5, 0.13}, {7.2, 0.11}
    };

    // Array arrB (10x2)
    double arrB[10][2] = {
        {10.0, 0.10}, {5.3, 0.15}, {7.6, 0.05}, {9.4, 0.12},
        {3.1, 0.08}, {5.9, 0.10}, {8.2, 0.07}, {9.7, 0.09},
        {2.1, 0.13}, {6.5, 0.11}
    };

    // Array arrC (12x2)
    double arrC[12][2] = {
        {12.0, 0.05}, {10.3, 0.10}, {14.1, 0.12}, {9.6, 0.08},
        {11.5, 0.07}, {13.3, 0.09}, {8.8, 0.11}, {15.0, 0.06},
        {7.2, 0.13}, {10.0, 0.09}, {6.7, 0.06}, {9.9, 0.04}
    };

    // Calculate covariance (using the same array for X and Y)
    double result = cov(arrA, arrB, 10,10);
    printf("Covariance: %lf\n", result);

	// Calculate when nx != ny
	result = cov(arrA, arrC, 10,12);
    printf("Covariance: %lf\n", result);
    return 0;
}

