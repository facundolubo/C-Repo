#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIML 20
/*
 * typedef struct NODE *LIST;
struct NODE {
int data;
NODE next;
};
* 
* 	listaProductos = ^nodoProducto;
	
	nodoProducto = record
		dato: producto;
		sig: listaProductos;
	end;
	* 
	* */
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

    for (int i = 0; i < diml; i++) {
        insert(&list, getRandomInt(0, 50));
    }
    return list;
}

void printList(IntList list) {
    printf("Printing list ...\n");
    IntNode *auxNode = list.head;
    while (auxNode != NULL) {
        printf("Value: %d  ", auxNode->data);
        auxNode = auxNode->next;
    }
    printf("\n");
}

void swapData(IntNode *node1, IntNode *node2) {
    int temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;
}

// Function to perform selection sort on a linked list
void selectionSort(IntList *list) {
    IntNode *ant, *act, *small;
    ant = list->head;
    while (ant != NULL) {
        small = ant;
        act = ant->next;
        while (act != NULL) {
            if (small->data > act->data) {
                small = act;
            }
            act = act->next;
        }
        swapData(ant, small);
        ant = ant->next;
    }
}

IntList merge(IntList list1, IntList list2) {
    IntList mergedList;
	//printf("Merge invokation with list1 = %d and list2 = %d\n", list1.head->data, list2.head->data); //ESTO ME ROMPIA EL COD
	if (list1.head == NULL) {
		mergedList = list2;
	}
	else if (list2.head == NULL) {
		mergedList = list1;
	}
	else {
		if (list1.head->data <= list2.head->data) {
			mergedList.head = list1.head;
			mergedList.head->next = merge((IntList){list1.head->next, list1.len - 1}, list2).head;
		}
		else {
			mergedList.head = list2.head;
			mergedList.head->next = merge(list1, (IntList){list2.head->next, list2.len - 1}).head;
		}
	}
	return mergedList;
}


IntList mergeRecursive2(IntList list1, IntList list2) {
    IntList mergedList;

    // Base cases
    if (list1.head == NULL) {
        mergedList = list2;
    } else if (list2.head == NULL) {
        mergedList = list1;
    } else {
        // Determine which list's head should be the mergedList's head
        if (list1.head->data <= list2.head->data) {
            mergedList.head = list1.head;
            mergedList.head->next = mergeRecursive2((IntList){list1.head->next, list1.len - 1}, list2).head;
        } else {
            mergedList.head = list2.head;
            mergedList.head->next = mergeRecursive2(list1, (IntList){list2.head->next, list2.len - 1}).head;
        }
    }

    return mergedList;
}
IntList mergeRecursive(IntList list1, IntList list2) {
    IntList mergedList;
    if (list1.head == NULL) {
        mergedList = list2;
        return mergedList;
    }
    if (list2.head == NULL) {
        mergedList = list1;
        return mergedList;
    }
    if (list1.head->data <= list2.head->data) {
        mergedList.head = list1.head;
        mergedList.head->next = mergeRecursive((IntList){list1.head->next, list1.len - 1}, list2).head;
    } else {
        mergedList.head = list2.head;
        mergedList.head->next = mergeRecursive(list1, (IntList){list2.head->next, list2.len - 1}).head;
    }
    return mergedList;
}

int main() {
	srand(time(NULL));

    // Create a linked list
    IntList list1 = createList(DIML);
    IntList list2 = createList(DIML);
    // Print the list
    printf("List 1: \n");
    printList(list1);
    printf("List 2: \n");
    printList(list2);
    printf("Sorting ...\n");
    selectionSort(&list1);
    selectionSort(&list2);
	printf("List 1: \n");
    printList(list1);
    printf("List 2: \n");
    printList(list2);
    printf("Merge ... \n");
    printf("\n");
    IntList list3 = merge(list1,list2);
    printf("List 3: \n");
    printList(list3);    
    return 0;
}
