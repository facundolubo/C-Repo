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
    int len[(ASCII_z - ASCII_A) - (ASCII_a - ASCII_Z) + 2]; //this +2 solve the code, don't know why
    int totalLen;
} CharCounter;

char getRandomChar() {
    char c;
    int randInt = rand() % (ASCII_z + 1);
    if ((randInt >= ASCII_A && randInt <= ASCII_Z) || (randInt >= ASCII_a && randInt <= ASCII_z)) {
        c = (char)randInt;
    } else {
        c = getRandomChar();
    }
    return c;
}

VectorChar createArray() {
    printf("\n");
    VectorChar vChar;
    vChar.len = 0;

    srand(time(NULL));

    int randLen = rand() % MAX_CHAR;
    int nullLen = MAX_CHAR - randLen;
    printf("randLen: %d\nnullLen: %d\n", randLen, nullLen);
    while (vChar.len < randLen) {
        char randChar = getRandomChar();
        int insertPos = 0;
        while (insertPos < vChar.len && randChar > vChar.arrChar[insertPos]) {
            insertPos++;
        }
        for (int i = vChar.len; i > insertPos; i--) {
            vChar.arrChar[i] = vChar.arrChar[i - 1];
        }
        vChar.arrChar[insertPos] = randChar;
        vChar.len++;
    }
    for (int i = vChar.len; i < MAX_CHAR; i++) {
        vChar.arrChar[i] = NULL_CHAR;
    }
    return vChar;
}

CharCounter initCounter() {
    CharCounter counter = {
        .c = {0},
        .len = {0},
        .totalLen = 0
    };
    for (int i = 0; i <= (ASCII_Z - ASCII_A); i++) {
        counter.c[i] = ASCII_A + i;
        counter.totalLen++;
    }

    for (int i = 0; i <= (ASCII_z - ASCII_a); i++) {
        counter.c[counter.totalLen] = ASCII_a + i;
        counter.totalLen++;
    }
    printf("Counter total len: %d\n", counter.totalLen);
    return counter;
}

void printArr(VectorChar *vChar) {
	printf("\n");
    printf("Array of characters: \n");
    for (int i = 0; i < vChar->len; i++) {
        printf("%c ", vChar->arrChar[i]);
    }
    printf("\n");
}

void printCounter(CharCounter *counter) {
    printf("\n");
    printf("Counter len: %d\n", counter->totalLen);
    for (int i = 0; i < counter->totalLen; i++) {
        printf("%c ", counter->c[i]);
    }
	printf("\n");
	for (int i = 0; i < counter->totalLen; i++) {
        printf("%d ", counter->len[i]);
    }
}

void proc_info(VectorChar vChar, CharCounter *counter) {
    int posVec = 0;
    while (posVec < vChar.len) {
        char actChar = vChar.arrChar[posVec];
        int posCt = 0;
        while (counter->c[posCt] != actChar) {
            posCt++;
        }
        while (vChar.arrChar[posVec] != NULL_CHAR && actChar == vChar.arrChar[posVec]) {
            counter->len[posCt]++;
            posVec++;
        }
    }
}

int main() {
	printf("Magic number: %d", (ASCII_z - ASCII_A) - (ASCII_a - ASCII_Z));
    VectorChar vChar = createArray();
    CharCounter counter = initCounter();
    printArr(&vChar);
    proc_info(vChar, &counter);
    printCounter(&counter);
    return 0;
}
