#include <stdio.h>
#include <stdlib.h>
struct Queue
{
    int size;
    int f;
    int b;
    int *arr;
};

void queueTraversal(struct Queue *q)
{
    for (int i = q->f + 1; i <= q->b; i++)
    {
        printf("Element : %d\n", q->arr[i]);
    }
}

int isFull(struct Queue *q)
{
    if (q->b == q->size - 1)
        return 1;
    else
        return 0;
}

void enQueue(struct Queue *q, int data)
{
    if (isFull(q))
    {
        printf("Queue Overflow");
    }
    else
    {
        q->arr[++q->b] = data;
    }
}

int deQueue(struct Queue *q)
{
    int elem = -1;
    if (q->b == q->f)
    {
        printf("Queue Underflow");
    }
    else
    {
        q->f++;
        elem = q->arr[q->f];
    }

    return elem;
}

void main()
{
    struct Queue q;
    q.size = 10;
    q.f = q.b = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    printf("Queue Insertion Operation\n");
    enQueue(&q, 10);
    enQueue(&q, 20);
    enQueue(&q, 30);
    enQueue(&q, 40);

    printf("\nQueue Traversal after insertion\n");
    queueTraversal(&q);

    printf("\nQueue Deletion Operation\n");
    printf("Removed Element %d\n", deQueue(&q));
    printf("Removed Element %d\n", deQueue(&q));
    printf("Removed Element %d\n", deQueue(&q));
    printf("Removed Element %d\n", deQueue(&q));
    printf("Removed Element %d\n", deQueue(&q));

    printf("\nQueue Traversal after deletion\n");
    queueTraversal(&q);
}