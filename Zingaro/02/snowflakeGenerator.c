// snowflakeGenerator.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random integer between min and max (inclusive)
int generateRandomInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int** generateSnowflake(int n) {
    // Allocate memory for the snowflake array
    int** snowflake = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        snowflake[i] = (int*)malloc(6 * sizeof(int));
    }

    // Seed the random number generator
    srand(time(NULL));

    // Generate the snowflake pattern
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            // Generate random integers between 1 and 100,000
            snowflake[i][j] = generateRandomInt(1, 100000);
        }
    }

    // Return the generated snowflake array
    return snowflake;
}

void freeSnowflake(int** snowflake, int n) {
    // Free the allocated memory for the snowflake array
    for (int i = 0; i < n; i++) {
        free(snowflake[i]);
    }
    free(snowflake);
}

