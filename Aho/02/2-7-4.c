#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define MIN 0
#define CANT_LIST 10

typedef struct Node {
    int num;
    struct Node *next;
} Node;

typedef Node *List;

int randomInt(int max, int min) {
    int range = max - min;
    return min + rand() % range;
}

Node *createNode() {
    Node *newNode = malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->num = randomInt(MAX, MIN);
        newNode->next = NULL;
    }
    return newNode;
}

List initList() {
    return NULL;
}

void insertBeginning(List *list) {
    Node *newNode = createNode();
    if (newNode != NULL) {
        newNode->next = *list;
        *list = newNode;
    }
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

