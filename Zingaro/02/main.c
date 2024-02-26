#include <stdio.h>
#include <stdlib.h>
#include "snowflakeGenerator.h"
#include "snowflakeProcessor.h"
#include "repetitionChecker.h"

int main() {
    int n = 10; // Number of rows
    int** snowflake = generateSnowflake(n);

    // Print the generated snowflake array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            printf("%8d ", snowflake[i][j]);
        }
        printf("\n");
    }

    // Calculate row sums
    int* rowSums = calculateRowSums(snowflake, n);

    // Print row sums
    printf("Row sums:\n");
    for (int i = 0; i < n; i++) {
        printf("%8d\n", rowSums[i]);
    }

    // Find repetitions in row sums
    IndexList* repetitions = findRepetitions(rowSums, n);

    // Print repetition indices
    printf("Repetition indices:\n");
    for (int i = 0; i < repetitions->count; i++) {
        printf("%d ", repetitions->indices[i]);
    }
    printf("\n");

    // Free allocated memory
    freeSnowflake(snowflake, n);
    free(rowSums);
    freeIndexList(repetitions);

    return 0;
}

