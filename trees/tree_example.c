#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NL printf("\n")

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* newNode(int data) {
    TreeNode* n = malloc(sizeof(TreeNode));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

TreeNode * insertNode (TreeNode * T, int data) {
	printf("Call to insertNode");
	NL;
	printf("Data to insert: %d", data);
	NL;
	if (T == NULL) {
		return newNode(data);
	}
	else {
		if (data < T->data) T->left = insertNode(T->left, data);
		else T->right = insertNode(T->right, data);
	}
	return T;
}

void printTree (TreeNode * T) {
	if (T != NULL) {
		printTree(T->left);
		printf("%d", T->data);
		NL;
		printTree(T->right);
	}
}

int main(int argc, char* argv[]) {
	/* The program receives an integer as the only parameter, otherwise it doesn't work properly */
	srand(time(NULL));
	int i = 0;
	int num = atoi(*++argv) % 64;
	TreeNode * tree = NULL;
	printf("Random number: %d", num);
	NL;
	for (;i < num; i++) {
		tree = insertNode(tree, rand()% 64);
	}
	NL;
	printTree(tree);
	NL;
    return 0;
}
