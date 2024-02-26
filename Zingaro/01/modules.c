
#include "modules.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void populateLine(int arr[], int n, int *k) {
    for (int i = 0; i < n; i++) {
        int num = rand() % (*k + 1);
        arr[i] = num;
        printf("Adding %d to line[%d]\n", num, i); // Print the number being added to the line
        *k -= num;
    }
    int i = 0;
    while (*k > 0 && i < n) {
        int additional_people = ((*k % n) + 1);
        printf("Remaining people to add: %d\n", additional_people);
        for (int j = 0; j < additional_people && *k > 0; j++) {
            arr[i]++;
            (*k)--;
            printf("Adding 1 person to line[%d]\n", i); // Print the addition of one person to the line
            i = (i + 1) % n; // Move to the next position in a circular manner
        }
    }
}


void calculateNewPeople(int arr[], int n, int *m, int *min) {
    while (*m > 0) {
        int min_index = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] < *min) {
                *min = arr[i];
                min_index = i;
            }
        }
        while (*m > 0 && *min == arr[min_index]) {
            arr[min_index]++;
            (*m)--;
            for (int i = min_index + 1; i < n && *m > 0; i++) {
                if (arr[i] == *min) {
                    arr[i]++;
                    (*m)--;
                }
            }
        }
        (*min)++;
    }
}

