#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Include string.h for string functions

#define MAX_PART 5000
#define MIN_INSCR 50
#define CANT_CAT 5
#define MAX_NAME_LENGTH 64
#define TRUE 1
#define FALSE 0

typedef struct participante {
    int dni[8];
    char nombre[MAX_NAME_LENGTH]; // Fixed the syntax error here
    int categoria;
    int fecha;
} Participante;

typedef struct counter {
    int counter[CANT_CAT];
} Counter;

// Function to generate a random integer between min and max
int getRandomInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Function to generate a random name
void getRandomName(char *name) {
    static const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int nameLength = getRandomInt(5, 10);

    for (int i = 0; i < nameLength; ++i) {
        name[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    name[nameLength] = '\0'; // Null-terminate the string
}

// Function to generate a random participant
Participante generateParticipante() {
    Participante part;
    for (int i = 0; i < 8; i++) {
        part.dni[i] = getRandomInt(0, 9);
    }
    getRandomName(part.nombre);
    part.categoria = getRandomInt(1, 5);
    part.fecha = getRandomInt(0, 365);
    return part;
}

// Function to count participants in each category
Counter countParticipants(Participante arrInscripciones[], int n) {
    Counter counter = {{0}};
    for (int i = 0; i < n; i++) {
        counter.counter[arrInscripciones[i].categoria - 1]++; // Adjusting index to start from 0
    }
    return counter;
}

// Main function
int main() {
    Participante arrInscripciones[MAX_PART]; // Array to hold participants
    int n = 100; // Number of participants, change as needed
    srand(1); // Seed the random number generator for reproducibility

    // Generating random participants
    for (int i = 0; i < n; i++) {
        arrInscripciones[i] = generateParticipante();
    }

    // Counting participants in each category
    Counter counter = countParticipants(arrInscripciones, n);

    // Printing counts for each category
    for (int i = 0; i < CANT_CAT; i++) {
        printf("Category %d count: %d\n", i + 1, counter.counter[i]);
    }

    return 0;
}

