#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
        if (ptr->nextNodePtr == NULL)
        {

            printf("%d ", ptr->data);
            ptr = ptr->nextNodePtr;
        }

        else
        {
            printf("%d -> ", ptr->data);
            ptr = ptr->nextNodePtr;
        }
    }
    printf("\n");
}

// Insertion at the beginning of linked list
struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->nextNodePtr = head;
    ptr->data = data;
    return ptr;
}

// Insertion at the end of linked list
struct Node *insertAtLast(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *dummy = head;
    while (dummy->nextNodePtr != NULL)
    {
        dummy = dummy->nextNodePtr;
    }
    dummy->nextNodePtr = ptr;
    ptr->data = data;
    ptr->nextNodePtr = NULL;

    return head;
}

// Insertion at the specified index of linked list
struct Node *insertAtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *dummy = head;
    int i = 0;
    bool validIndex = true;
    while (i != index - 1)
    {
        if (dummy->nextNodePtr == NULL)
        {
            printf("Invalid index..!\n");
            validIndex = false;
            return head;
        }
        else
        {

            dummy = dummy->nextNodePtr;
            i++;
        }
    }
    if (validIndex)
    {

        ptr->nextNodePtr = dummy->nextNodePtr;
        ptr->data = data;
        dummy->nextNodePtr = ptr;
        return head;
    }
}

// Insertion after given node of linked list
struct Node *insertAfterNode(struct Node *head, struct Node *prevNode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

    ptr->nextNodePtr = prevNode->nextNodePtr;
    prevNode->nextNodePtr = ptr;
    ptr->data = data;
    return head;
}

int main()
{
    int data = 0;
    // create nodes with struct Node and assign memory in heap using malloc
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *first = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

    // Initial insertion
    linkedList_insertion(head, first, second, third, fourth);
    printf("Traversal before insertion at beginning : ");
    linkedList_Traversal(head);

    // Insertion at the beginning of linked list
    printf("\nEnter the value to insert in beginning : ");
    scanf("%d", &data);
    head = insertAtFirst(head, data);
    printf("Traversal After insertion at beginning : ");
    linkedList_Traversal(head);

    // Insertion at the end of linked list
    printf("\nEnter the value to insert at last : ");
    scanf("%d", &data);
    head = insertAtLast(head, data);
    printf("Traversal After insertion at end : ");
    linkedList_Traversal(head);

    // Insertion at the specified index of linked list
    int pos = 0;
    printf("\nEnter the position of linked list to insert : ");
    scanf("%d", &pos);
    printf("Enter the value to insert after the specified position : ");
    scanf("%d", &data);
    head = insertAtIndex(head, data, pos);
    printf("Traversal for insertion after specified position : ");
    linkedList_Traversal(head);

    // Insertion after given node of linked list
    printf("\nEnter the value to insert to new node after Second node : ");
    scanf("%d", &data);
    head = insertAfterNode(head, second, data);
    printf("Traversal for insertion after second node : ");
    linkedList_Traversal(head);
}
