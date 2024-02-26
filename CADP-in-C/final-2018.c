#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CHAR 100
#define ASCII_A 65
#define ASCII_Z 90
#define ASCII_a 97
#define ASCII_z 122

typedef struct vectorChar {
    char arrChar[MAX_CHAR];
    int len;
} VectorChar;

typedef struct charCounter {
    char c[(ASCII_z - ASCII_A) - (ASCII_a - ASCII_Z)];
    int len[MAX_CHAR];
} CharCounter;

// Function to generate a random character between 'A' and 'z'
char getRandomChar() {
    char c;
	int randInt = rand() % (ASCII_z + 1);
    if ((randInt >= ASCII_A && randInt <= ASCII_Z) || (randInt >= ASCII_a && randInt <= ASCII_z)) {
        c = (char)randInt;
    } else {
        // If the generated character is not within the range, call getRandomChar recursively
        c = getRandomChar();
    }
    return c;
}

// Function to generate a random array of characters
VectorChar createArray() {
    VectorChar vChar;
    vChar.len = MAX_CHAR; // Assuming array length is fixed

    srand(time(NULL)); // Seed the random number generator

    // Generate random characters and store them in the array
    for (int i = 0; i < MAX_CHAR; i++) {
        vChar.arrChar[i] = getRandomChar();
    }

    return vChar;
}

// Function to print the array of characters
void printArr(VectorChar vChar) {
    printf("Array of characters:\n");
    for (int i = 0; i < MAX_CHAR; i++) {
        printf("%c ", vChar.arrChar[i]);
    }
    printf("\n");
}

int main() {
    VectorChar vChar = createArray();
    printArr(vChar);
    return 0;
}
