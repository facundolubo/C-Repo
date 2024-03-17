#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Include string.h for string functions

#define MAX_PART 5000
#define MIN_INSCR 1000
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
    int len[CANT_CAT];
	int index[CANT_CAT][MAX_PART];
} Counter;

typedef Participante ArrFinalType[CANT_CAT][MAX_PART]; // Typedef for arrFinal

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
Counter countParticipants(Participante arrInscripciones[]) {
    Counter counter = {{0}};
    for (int i = 0; i < MAX_PART; i++) {
        counter.len[arrInscripciones[i].categoria - 1]++; // Adjusting index to start from 0
    }
    return counter;
}

void procInfo(Participante arrInsc[], Counter counter, Participante arrFinal[CANT_CAT][MAX_PART]) {
    // Iterate over each participant
	int indexFinal = 0;
    for (int cat = 0; cat < CANT_CAT; cat++) {
		int lenCat = counter.len[cat];
		if (lenCat >= MIN_INSCR) {
			for (int part = 0; part < lenCat; part++) {
				arrFinal[indexFinal][part] = arrInsc[counter.index[cat][part]];
			}
			indexFinal++;
		}
	}
}
void printFinalArraySizes(Participante arrFinal[CANT_CAT][MAX_PART]) {
    for (int cat = 0; cat < CANT_CAT; cat++) {
        int size = 0;
        // Count the number of valid elements in the current category
        for (int i = 0; i < MAX_PART; i++) {
            if (arrFinal[cat][i].categoria != 0) { // Check if the element is valid
                size++;
            } else {
                break; // No need to continue counting if we encounter an invalid element
            }
        }
        printf("Category %d final array size: %d\n", cat + 1, size);
    }
}


// Main function
int main() {
    Participante arrInscripciones[MAX_PART]; // Array to hold participants
	Participante arrFinal[CANT_CAT][MAX_PART];
    srand(1); // Seed the random number generator for reproducibility

    // Generating random participants
    for (int i = 0; i < MAX_PART; i++) {
        arrInscripciones[i] = generateParticipante();
    }

    // Counting participants in each category
    Counter counter = countParticipants(arrInscripciones);

    // Printing counts for each category
    for (int i = 0; i < CANT_CAT; i++) {
        printf("Category %d count: %d\n", i + 1, counter.len[i]);
    }
    procInfo(arrInscripciones, counter, arrFinal);
    printFinalArraySizes(arrFinal);
	return 0;
}

