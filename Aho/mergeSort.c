#include <stdio.h>
#include <stdlib.h>

#define DIML 20
// Define the DefCell macro
#define DefCell(EltType, CellType, ListType) \
typedef struct CellType *ListType; \
struct CellType { \
    EltType data; \
    ListType next; \
}

// Use the DefCell macro to define IntCell and IntList
DefCell(int, IntCell, IntList);

int getRandomInt(int min, int max) {
	int range = max-min;
	int rnum = min + rand() % (range + 1);
	return rnum;
}

void createList(int diml) {
    IntList node = malloc(sizeof(struct IntCell)); // Use struct IntCell instead of IntCell
    node->element = 10;
    node->next = NULL;
}


int main() {
    // Create a linked list node
    createList(DIML)
    // Print the element of the node
    printf("Element of node1: %d\n", node->element);

    // Free the allocated memory
    free(node);

    return 0;
}
