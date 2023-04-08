#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// create a node
struct Node
{
    int data;
    struct Node *nextNodePtr;
};

// insert values to nodes
void linkedList_insertion(struct Node *head, struct Node *first, struct Node *second,
                          struct Node *third, struct Node *fourth)
{

    head->data = 10;           // assign value 10 to head node
    head->nextNodePtr = first; // point the headnode to first node

    first->data = 20;
    first->nextNodePtr = second;

    second->data = 30;
    second->nextNodePtr = third;

    third->data = 40;
    third->nextNodePtr = fourth;

    fourth->data = 50;
    fourth->nextNodePtr = NULL;
}

// iterate through linked list and print the node values
void linkedList_Traversal(struct Node *ptr)
{ // loop until next node is null
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->nextNodePtr;
    }
}
int main()
{
    // create nodes with struct Node and assign memory in heap using malloc
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *first = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

    linkedList_insertion(head, first, second, third, fourth);
    linkedList_Traversal(head);
}
