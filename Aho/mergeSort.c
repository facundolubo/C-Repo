#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIML 20

// Define the node structure
typedef struct IntNode {
    int data;
    struct IntNode *next;
} IntNode;

typedef struct IntList { 
    IntNode *head;
    int len; 
} IntList;

// Function to generate a random integer between min and max
int getRandomInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

IntNode *insert(IntList *list, int num) {
    IntNode *node = malloc(sizeof(IntNode));
    if (node == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    node->data = num;
    node->next = list->head;
    list->head = node;
    list->len++;
    return node;
}

IntList createList(int diml) {
    IntList list;
    list.head = NULL;
    list.len = 0;
    srand(time(NULL)); // Seed the random number generator

    for (int i = 0; i < diml; i++) {
        insert(&list, getRandomInt(0, 50));
    }
    return list;
}

void printList(IntList list) {
    printf("Printing list ...\n");
    IntNode *auxNode = list.head;
    while (auxNode != NULL) {
        printf("Value: %d\n", auxNode->data);
        auxNode = auxNode->next;
    }
}

IntList merge(IntList list1, IntList, list2) {
	IntList list;
	if (list1 == NULL) {
		list = list2;
	}
	else if (list2 == NULL) {
		list = list1;
	}
	else if (list1->data <= list2->data) {
		list1->next = merge(list1->next, list2);
		list = list1;
	}
	else {
		list2->next = merge(list1, list2->next);
		list =list2;
	}
	return list;
}

int main() {
    // Create a linked list
    IntList list = createList(DIML);
    // Print the list
    printList(list);
    return 0;
}
