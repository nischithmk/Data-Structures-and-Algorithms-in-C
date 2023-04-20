#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *f = NULL;
struct Node *r = NULL;

void queueTraversal()
{
    struct Node *p = f;
    while (p != NULL)
    {
        printf("Element : %d\n", p->data);
        p = p->next;
    }
}

void enQueue(int val)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));

    if (p == NULL)
    {
        printf("Queue Overflow");
    }
    else
    {
        p->data = val;
        p->next = NULL;
        if (f == NULL)
        {
            f = r = p;
        }
        else
        {
            r->next = p;
            r = p;
        }
    }
}

int deQueue()
{
    int elem = -1;
    struct Node *p = f;
    if (f == NULL)
    {
        printf("Queue is Empty\n");
        return elem;
    }
    else
    {
        f = f->next;
        elem = p->data;
        free(p);
        return elem;
    }
}

void main()
{

    printf("Queue Insertion Operation\n");
    enQueue(10);
    enQueue(20);
    enQueue(30);
    enQueue(40);
    enQueue(50);

    printf("\nQueue Traversal after insertion\n");
    queueTraversal();

    printf("\nQueue Deletion Operation\n");
    printf("Removed Element %d\n", deQueue());
    printf("Removed Element %d\n", deQueue());
    printf("Removed Element %d\n", deQueue());

    printf("\nQueue Traversal after deletion\n");
    queueTraversal();
}