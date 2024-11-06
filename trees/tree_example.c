#include <stdlib.h>
#include <stdio.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* new_node(int data) {
    TreeNode* n = malloc(sizeof(TreeNode));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

TreeNode * insertNode (*TreeNode T, int data) {
	if (T == NULL) {
		new_node(data);
	}
	else {
		if (data < T->data) insertNode(T->left, data);
		else insertNode(T->right, data);
	}
}

void printTree
//    0
//   / \
//  1  2
int main(int argc, char* argv[]) {
    TreeNode* root = new_node(0);
    root->left = new_node(1);
    root->right = new_node(2);

    printf("Root value is %d\n", root->data);
    printf("Left descendant of root is %d\n", root->left->data);
    printf("Right descendant of root is %d\n", root->right->data);
    return 0;
}
