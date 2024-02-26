// snowflakeProcessor.c
#include <stdlib.h>
#include "snowflakeProcessor.h"

int* calculateRowSums(int** snowflake, int n) {
    // Allocate memory for the result array
    int* rowSums = (int*)malloc(n * sizeof(int));

    // Calculate row sums
    for (int i = 0; i < n; i++) {
        rowSums[i] = 0;
        for (int j = 0; j < 6; j++) {
            rowSums[i] += snowflake[i][j];
        }
    }

    // Return the array of row sums
    return rowSums;
}

