#include <stdio.h>
#include <stdlib.h>

struct lnode {
    int value;
    struct lnode *next;
};

struct list {
    struct lnode *head;
    struct lnode *tail;
};

void list_add(struct list *lst, int value)
{
    /* Append the value to the end of the linked list. */
    struct lnode *newNode = (struct lnode *)malloc(sizeof(struct lnode));
    newNode->value = value;
    newNode->next = NULL;

    if (lst->head == NULL) {  // If the list is empty
        lst->head = newNode;
        lst->tail = newNode;
    } else {
        lst->tail->next = newNode;
        lst->tail = newNode;
    }
}

void list_remove(struct list *lst, int value)
{
    /* Remove the node with the specified value from the linked list. */
    struct lnode *actNode = lst->head;
    struct lnode *preNode = NULL;

    while (actNode != NULL && actNode->value != value) {
        preNode = actNode;
        actNode = actNode->next;
    }

    if (actNode == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }

    if (preNode == NULL) {
        // Removing the head node
        lst->head = actNode->next;
    } else {
        // Removing a node that's not the head
        preNode->next = actNode->next;
    }

    // Update tail if we removed the last node
    if (actNode == lst->tail) {
        lst->tail = preNode;
    }

    free(actNode);  // Free the memory of the removed node
}

void list_dump(struct list *lst)
{
    struct lnode *cur;
    printf("\nDump:\n");
    for (cur = lst->head; cur != NULL; cur = cur->next) {
        printf("  %d\n", cur->value);
    }
}

int main()
{
    struct list mylist;
    mylist.head = NULL;
    mylist.tail = NULL;

    list_add(&mylist, 10);
    list_add(&mylist, 20);
    list_add(&mylist, 30);
    list_dump(&mylist);

    list_remove(&mylist, 42);  // Value not in list

    list_remove(&mylist, 10);  // Remove head
    list_dump(&mylist);

    list_remove(&mylist, 30);  // Remove tail
    list_dump(&mylist);

    list_add(&mylist, 40);     // Add new element after removal
    list_dump(&mylist);

    return 0;
}

