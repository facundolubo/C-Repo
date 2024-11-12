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

    // 2D array for temperatures and probabilities (weights)
    double temperatures_weights[N][2];

    // Generate random temperatures between -10 and 40 degrees Celsius
    for (int i = 0; i < N; i++) {
        temperatures_weights[i][0] = (rand() % 51) - 10;  // Random temperature between -10 and 40
    }

    // Generate random probabilities that sum to 1
    double sum = 0.0;
    for (int i = 0; i < N; i++) {
        temperatures_weights[i][1] = (double)rand() / RAND_MAX;
        sum += temperatures_weights[i][1];
    }

    // Normalize the probabilities to sum to 1
    for (int i = 0; i < N; i++) {
        temperatures_weights[i][1] /= sum;
    }

    // Print the temperatures and probabilities
    printf("Temperatures and corresponding probabilities:\n");
    printArray(temperatures_weights, N);

    // Calculate covariance (using the same array for X and Y)
    double result = cov(temperatures_weights, temperatures_weights, N, N);
    printf("Covariance: %lf\n", result);
    return 0;
}

