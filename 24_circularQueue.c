#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int f;
    int r;
    int size;
    int *arr;
};

void queueTraversal(struct Queue *q)
{

    for (int i = q->f + 1; i <= q->r; i++)
    {
        printf("Element : %d\n", q->arr[i]);
    }
};

void enQueue(struct Queue *q, int val)
{

    if (q->f == -1 && (q->r + 1) == q->size)
    {
        printf("Cannot add element %d - Queue is Full \n", val);
    }
    else
    {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = val;
    }
}

int deQueue(struct Queue *q)
{
    int elem = -1;
    if (q->f == q->r)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        q->f = (q->f + 1) % q->size;
        elem = q->arr[q->f];
    }
    return elem;
}

void main()
{

    struct Queue q;
    q.f = q.r = -1;
    q.size = 4;
    q.arr = (int *)malloc(q.size * sizeof(int));

    printf("Queue Insertion Operation\n");
    enQueue(&q, 10);
    enQueue(&q, 20);
    enQueue(&q, 30);
    enQueue(&q, 40);
    enQueue(&q, 50);
    enQueue(&q, 60);

    printf("\nQueue Traversal after insertion\n");
    queueTraversal(&q);

    printf("\nQueue Deletion Operation\n");
    printf("Removed Element %d\n", deQueue(&q));
    printf("Removed Element %d\n", deQueue(&q));
    printf("Removed Element %d\n", deQueue(&q));
    printf("Removed Element %d\n", deQueue(&q));
    printf("Removed Element %d\n", deQueue(&q));
    printf("Removed Element %d\n", deQueue(&q));

    printf("\nQueue Traversal after deletion\n");
    queueTraversal(&q);
}
