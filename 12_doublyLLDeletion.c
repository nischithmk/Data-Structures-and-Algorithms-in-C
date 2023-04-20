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

struct Node *deleteFirst(struct Node *ptr)
{
    struct Node *p = ptr;
    ptr = ptr->next;
    ptr->prev = NULL;
    p->next = NULL;
    free(p);
    return ptr;
}

struct Node *deleteLast(struct Node *ptr)
{
    struct Node *lastNode = ptr;

    struct Node *p = ptr;
    while (lastNode->next != NULL)
    {
        lastNode = lastNode->next;
    }
    struct Node *q = lastNode->prev;
    printf("\nq data %d\n", q->data);
    q->next = NULL;
    lastNode->next = NULL;
    lastNode->prev = NULL;
    free(lastNode);
    return ptr;
}

struct Node *deleteAtIndex(struct Node *ptr, int index)
{
    struct Node *p = ptr;
    int i = 1;
    while (p->next != NULL && i != index)
    {
        p = p->next;
        i += 1;
    }
    struct Node *q = p->prev;
    q->next = p->next;
    p->next->prev = q;
    p->next = NULL;
    p->prev = NULL;
    free(p);
    return ptr;
}

struct Node *deleteAfterIndex(struct Node *ptr, int index)
{
    struct Node *p = ptr;
    int i = 1;
    while (p->next != NULL && i != index)
    {
        p = p->next;
        i += 1;
    }
    struct Node *q = p->prev;
    q->next = p->next;
    p->next->prev = q;
    p->next = NULL;
    p->prev = NULL;
    free(p);
    return ptr;
}

void main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fifth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *six = (struct Node *)malloc(sizeof(struct Node));
    struct Node *seven = (struct Node *)malloc(sizeof(struct Node));
    struct Node *eight = (struct Node *)malloc(sizeof(struct Node));

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
    fifth->next = six;

    six->prev = fifth;
    six->data = 60;
    six->next = seven;

    seven->prev = six;
    seven->data = 70;
    seven->next = eight;

    eight->prev = seven;
    eight->data = 80;
    eight->next = NULL;

    printf("Doubly Linked list traversal\n");
    traverseList(head);

    printf("\nDoubly Linked list delete first operation\n");
    head = deleteFirst(head);
    printf("\nDoubly Linked list traversal\n");
    traverseList(head);

    printf("\nDoubly Linked list delete last operation\n");
    head = deleteLast(head);
    printf("\nDoubly Linked list traversal\n");
    traverseList(head);

    printf("\nDoubly Linked list delete at index operation\n");
    head = deleteAtIndex(head, 3);
    printf("\nDoubly Linked list traversal\n");
    traverseList(head);

    printf("\nDoubly Linked list delete after index operation\n");
    head = deleteAfterIndex(head, 4);
    printf("\nDoubly Linked list traversal\n");
    traverseList(head);
}