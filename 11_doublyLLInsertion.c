#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

void traverseList(struct Node *ptr)
{

    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
};

struct Node *insertFirst(struct Node *ptr, int data)
{
    struct Node *firstNode = (struct Node *)malloc(sizeof(struct Node));
    firstNode->data = data;
    firstNode->prev = NULL;

    firstNode->next = ptr;
    ptr->prev = firstNode;

    return firstNode;
}

struct Node *insertLast(struct Node *ptr, int data)
{
    struct Node *lastNode = (struct Node *)malloc(sizeof(struct Node));
    lastNode->data = data;
    lastNode->next = NULL;

    struct Node *p = ptr;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = lastNode;
    lastNode->prev = p;
    return ptr;
}

struct Node *insertAtIndex(struct Node *ptr, int data, int index)
{
    struct Node *indexNode = (struct Node *)malloc(sizeof(struct Node));
    indexNode->data = data;
    indexNode->next = NULL;
    int i = 0;
    struct Node *p = ptr;
    while (p->next != NULL && i + 1 != index)
    {
        p = p->next;
        i += 1;
    }
    struct Node *q = p->prev;
    q->next = indexNode;
    indexNode->prev = q;
    indexNode->next = p;
    p->prev = indexNode;
    return ptr;
}

struct Node *insertAfterIndex(struct Node *ptr, int data, int index)
{
    struct Node *afterNode = (struct Node *)malloc(sizeof(struct Node));
    afterNode->data = data;
    afterNode->next = NULL;
    int i = 0;
    struct Node *p = ptr;
    while (p->next != NULL && i + 1 != index)
    {
        p = p->next;
        i += 1;
    }
    printf("\n%d\n", p->data);
    struct Node *q = p->next;
    afterNode->next = p->next;
    afterNode->prev = p;
    q->prev = afterNode;
    p->next = afterNode;
    return ptr;
}

void main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fifth = (struct Node *)malloc(sizeof(struct Node));

    head->prev = NULL;
    head->data = 10;
    head->next = second;

    second->prev = head;
    second->data = 20;
    second->next = third;

    third->prev = second;
    third->data = 30;
    third->next = fourth;

    fourth->prev = third;
    fourth->data = 40;
    fourth->next = fifth;

    fifth->prev = fourth;
    fifth->data = 50;
    fifth->next = NULL;

    printf("Doubly Linked list traversal\n");
    traverseList(head);

    printf("\nDoubly Linked list insert first operation\n");
    head = insertFirst(head, 100);
    printf("\nDoubly Linked list traversal\n");
    traverseList(head);

    printf("\nDoubly Linked list insert last operation\n");
    head = insertLast(head, 900);
    printf("\nDoubly Linked list traversal\n");
    traverseList(head);

    printf("\nDoubly Linked list insert at index operation\n");
    head = insertAtIndex(head, 500, 3);
    printf("\nDoubly Linked list traversal\n");
    traverseList(head);

    printf("\nDoubly Linked list insert after index operation\n");
    head = insertAfterIndex(head, 800, 3);
    printf("\nDoubly Linked list traversal\n");
    traverseList(head);
}