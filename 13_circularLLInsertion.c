#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Circular linked list traversal
void traverseList(struct Node *ptr)
{
    struct Node *p = ptr;

    do
    {
        printf("Element : %d\n", p->data);
        p = p->next;
    } while (p != ptr);
};

// Insert a node in begining
struct Node *insertFirst(struct Node *ptr, int data)
{
    struct Node *firstNode = (struct Node *)malloc(sizeof(struct Node));
    firstNode->data = data;

    struct Node *p = ptr;
    do
        p = p->next;
    while (p->next != ptr);
    p->next = firstNode;
    firstNode->next = ptr;
    return firstNode;
}

// Insert a node at the end
struct Node *insertLast(struct Node *ptr, int data)
{
    struct Node *lastNode = (struct Node *)malloc(sizeof(struct Node));
    lastNode->data = data;

    struct Node *p = ptr;
    do
        p = p->next;
    while (p->next != ptr);
    p->next = lastNode;
    lastNode->next = ptr;
    return ptr;
}

// insert new node at give index value assuming index starts from 0
struct Node *insertAtIndex(struct Node *ptr, int data, int index)
{
    struct Node *atIndexNode = (struct Node *)malloc(sizeof(struct Node));
    atIndexNode->data = data;

    struct Node *p = ptr;
    struct Node *q = ptr->next;
    int i = 0;
    do
    {
        i += 1;
        q = q->next;
        p = p->next;
    } while (q->next != ptr && i + 1 != index);
    atIndexNode->next = p->next;
    p->next = atIndexNode;
    return ptr;
}
void main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fifth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = second;
    second->data = 20;
    second->next = third;
    third->data = 30;
    third->next = fourth;
    fourth->data = 40;
    fourth->next = fifth;
    fifth->data = 50;
    fifth->next = head;

    printf("Circular Linked list traversal\n");
    traverseList(head);

    printf("\nInsert at first operation\n");
    head = insertFirst(head, 100);
    printf("Circular Linked list traversal after insertFirst\n");
    traverseList(head);

    printf("\nInsert at last operation\n");
    head = insertLast(head, 200);
    printf("Circular Linked list traversal after insertLast\n");
    traverseList(head);

    printf("\nInsert at given index operation\n");
    head = insertAtIndex(head, 300, 3);
    printf("Circular Linked list traversal after insertAtIndex\n");
    traverseList(head);
}