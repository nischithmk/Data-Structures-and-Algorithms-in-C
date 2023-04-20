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

struct Node *deleteFirst(struct Node *ptr)
{
    struct Node *p = ptr;
    struct Node *q = ptr->next;
    do
    {
        p = p->next;

    } while (p->next != ptr);
    p->next = q;
    return q;
}

struct Node *deleteLast(struct Node *ptr)
{
    struct Node *p = ptr;
    struct Node *q = ptr->next;
    do
    {
        p = p->next;
        q = q->next;

    } while (q->next != ptr);
    p->next = q->next;
    q->next = NULL;
    free(q);
    return ptr;
}

struct Node *deleteAtIndex(struct Node *ptr, int index)
{
    struct Node *p = ptr;
    struct Node *q = ptr->next;
    int i = 0;
    do
    {
        i += 1;
        p = p->next;
        q = q->next;

    } while (q->next != ptr && i + 2 != index);
    p->next = q->next;
    q->next = NULL;
    free(q);
    return ptr;
}

void main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fifth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *sixth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *seven = (struct Node *)malloc(sizeof(struct Node));
    struct Node *eight = (struct Node *)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = second;
    second->data = 20;
    second->next = third;
    third->data = 30;
    third->next = fourth;
    fourth->data = 40;
    fourth->next = fifth;
    fifth->data = 50;
    fifth->next = sixth;
    sixth->data = 60;
    sixth->next = seven;
    seven->data = 70;
    seven->next = eight;
    eight->data = 80;
    eight->next = head;

    printf("Circular Linked list traversal\n");
    traverseList(head);

    printf("\nDelete at first operation\n");
    head = deleteFirst(head);
    printf("Circular Linked list traversal after deleteFirst operation\n");
    traverseList(head);

    printf("\nDelete at last operation\n");
    head = deleteLast(head);
    printf("Circular Linked list traversal after deleteLast operation\n");
    traverseList(head);

    printf("\nDelete at given index operation\n");
    head = deleteAtIndex(head, 3);
    printf("Circular Linked list traversal after deleteAtIndex operation\n");
    traverseList(head);
}