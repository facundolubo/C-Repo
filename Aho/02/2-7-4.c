#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define MIN 0
#define CANT_LIST 10


typedef struct Node* List;

typedef struct Node {
    int num;
    List next;
} Node;

int randomInt(int max, int min) {
    int range = max - min;
    return min + rand() % range;
}

Node* createNode() {
    Node *newNode = (Node*)malloc(sizeof(Node)); // Allocate memory for the new node
	newNode->num = randomInt(MAX, MIN);
	newNode->next = NULL; // Assuming 'next' is a pointer in Node struct
    return newNode;
}

List initList() {
	List list = NULL;
    return list;
}

void insertBeginning(List *list) {
    Node *newNode = createNode(); // Allocate memory for a new node
    newNode->next = *list; // Link the new node to the current head of the list
    *list = newNode; // Update the list pointer to point to the new node
}

List createList(int n) {
    List list = initList();
    for (int i = 0; i < n; i++) {
        insertBeginning(&list); // Insert random numbers
    }
    return list;
}

void printList(List l) {
    while (l != NULL) {
        printf("%d\n", l->num);
        l = l->next;
    }
}

int add(List l) {
    int res = 0;
    while (l != NULL) {
        res += l->num;
        l = l->next;
    }
    return res;
}

int main() {
	srand(time(NULL)); // Seed for random number generation
    List list = createList(CANT_LIST);
    printf("Original list:\n");
    printList(list);
    printf("Sum of numbers: %d\n", add(list));
    return 0;
}

