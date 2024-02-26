// repetitionChecker.c
#include "repetitionChecker.h"
#include <stdio.h>
#include <stdlib.h>

// Define a structure representing a node in the linked list
typedef struct Node {
    int element;
    struct Node* next;
} Node;

// Define a structure representing a list of nodes
typedef struct List {
    Node* head; // Pointer to the first node in the list
    int nDim;   // Number of nodes in the list
} List;

// Function to create a new node for the linked list
Node* createNode(int element) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->element = element;
        newNode->next = NULL;
    }
    return newNode;
}

IndexList* findRepetitions(int* rowSums, int n) {
    // Create an array of Lists, one for each possible index
    List* hashTable = (List*)malloc(n * sizeof(List));
    for (int i = 0; i < n; i++) {
        hashTable[i].head = NULL;
        hashTable[i].nDim = 0;
    }

    // Iterate through the row sums and create linked lists for equal sums
    for (int i = 0; i < n; i++) {
        int sum = rowSums[i];
        // Calculate the hash value to determine the index in the hash table
        int index = sum % n;
        // Create a new node with the index as the element
        Node* newNode = createNode(i);
        // Insert the new node at the beginning of the linked list
        newNode->next = hashTable[index].head;
        hashTable[index].head = newNode;
        // Increment the number of nodes in the list
        hashTable[index].nDim++;
    }

    // Create and initialize the IndexList structure
    IndexList* repetitionIndices = (IndexList*)malloc(sizeof(IndexList));
    repetitionIndices->indices = NULL;
    repetitionIndices->count = 0;

    // Iterate through the hash table and add indices to the repetition list
    for (int i = 0; i < n; i++) {
        Node* current = hashTable[i].head;
        while (current != NULL) {
            // Add the index to the repetition list
            repetitionIndices->indices = realloc(repetitionIndices->indices, (repetitionIndices->count + 1) * sizeof(int));
            repetitionIndices->indices[repetitionIndices->count] = current->element;
            repetitionIndices->count++;
            // Move to the next node
            current = current->next;
        }
    }

    // Free the memory allocated for the hash table
    for (int i = 0; i < n; i++) {
        Node* current = hashTable[i].head;
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(hashTable);

    return repetitionIndices;
}

void freeIndexList(IndexList* list) {
    free(list->indices);
    free(list);
}

