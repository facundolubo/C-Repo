#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CHAR 100
#define ASCII_A 65
#define ASCII_Z 90
#define ASCII_a 97
#define ASCII_z 122
#define NULL_CHAR ' '

typedef struct vectorChar {
    char arrChar[MAX_CHAR];
    int len;
} VectorChar;

typedef struct charCounter {
    char c[(ASCII_z - ASCII_A) - (ASCII_a - ASCII_Z)];
    int len[(ASCII_z - ASCII_A) - (ASCII_a - ASCII_Z)];
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

// Function to generate a random sorted array of characters
VectorChar createArray() {
    VectorChar vChar;

    srand(time(NULL)); // Seed the random number generator

    // Generate random characters and store them in the array
    int randLen = rand() % MAX_CHAR; // random length of the array
    int nullLen = MAX_CHAR -  randLen;
    printf("randLen: %d\nnullLen: %d\n", randLen, nullLen);
    while (vChar.len < randLen) {
		char randChar = getRandomChar();
		int insertPos = 0;

		if (randChar < vChar.arrChar[insertPos]) {
			vChar.len++;
			for (int i = vChar.len; i > insertPos; i--) {
				vChar.arrChar[i-1] = vChar.arrChar[i];
			}
			vChar.arrChar[insertPos] = randChar;
		}
		insertPos++;
		printf("actPos: %d\n", insertPos);
	}
    for (int i = vChar.len; i < nullLen; i++) {
        vChar.arrChar[i] = NULL_CHAR;
    }

    return vChar;
}

// Function to initialize the counter structure
CharCounter initCounter() {
    CharCounter counter = {
        .c = {0}, // Initialize all elements of c array to 0 initially
        .len = {0} // Initialize all elements of len array to 0
    };

    // Initialize characters from 'A' to 'Z'
    for (int i = 0; i <= (ASCII_Z - ASCII_A); i++) {
        counter.c[i] = 'A' + i;
    }

    // Initialize characters from 'a' to 'z'
    for (int i = 0; i <= (ASCII_z - ASCII_a); i++) {
        counter.c[i + (ASCII_Z - ASCII_A + 1)] = 'a' + i;
    }

    return counter;
}

// Function to print the array of characters
void printArr(VectorChar vChar) {
    printf("Array of characters:\n");
    for (int i = 0; i < vChar.len; i++) {
        printf("%c ", vChar.arrChar[i]);
    }
    printf("\n");
}

// Function to print the counter array
void printCounter(CharCounter counter) {
    printf("Counter array:\n");
    for (int i = 0; i < (ASCII_z - ASCII_A) - (ASCII_a - ASCII_Z); i++) {
        printf("%c: %d\n", counter.c[i], counter.len[i]);
    }
}

// Function to process the information and update the counter
void proc_info(VectorChar vChar, CharCounter *counter) {
    int posVec = 0;

    while (vChar.arrChar[posVec] != NULL_CHAR) {
        char actChar = vChar.arrChar[posVec];
        int posCt = 0;
        while (counter->c[posCt] != actChar) {
            posCt++;
        }
        while ((vChar.arrChar[posVec] != NULL_CHAR) && (actChar == vChar.arrChar[posVec])) {
            counter->len[posCt]++;
            posVec++;
        }
    }
}

int main() {
    VectorChar vChar = createArray();
    CharCounter counter = initCounter();
    printArr(vChar);
    proc_info(vChar, &counter);
    printCounter(counter);
    return 0;
}

