/*
 * Write a version of recursion selectionSort that takes as argument a list of integers
 */
 
#include <stdio.h>
#include <stdlib.h>

#define CANT 5
#define MAX 10
#define MIN 0

typedef struct Node *List;

typedef struct Node {
	int num;
	List next;
} Node;

int randInt(int max, int min) {
	int range = max - min;
	return min + rand() % range;
}

Node* newNode() {
	Node* node = (Node*)malloc(sizeof(Node));
	return node;
}

void insertBeginning(List *list, int num) {
	Node* new = newNode();
	new->num = num;
	new->next = *list;
	*list = new;
}

List createList() {
	List list;
	for (int i = 0; i < CANT; i++) {
		int num;
		printf("Enter an integer: ");
		scanf("%d", &num);
		insertBeginning(&list, num);
	}
	return list;
}

void swap(Node* node1, Node* node2) {
	int auxData = node1->num;
	node1->num = node2->num;
	node2->num = auxData;
}


void selSortRec(List *list) {
	List pre, curr, small;
	pre = *list;
	if (pre != NULL) {
		small = pre;
		curr = pre->next;
		while (curr != NULL) {
			if (curr->num < small->num) {
				small = curr;
			}
			curr = curr->next;
		}
		swap(small, pre);
		selSortRec(&pre->next);
	}
}
void printList(List l) {
    while (l != NULL) {
        printf("%d\n", l->num);
        l = l->next;
    }
}

int main() {
	List list = createList();
	printList(list);
	selSortRec(&list);
	printList(list);
	return 0;
}
