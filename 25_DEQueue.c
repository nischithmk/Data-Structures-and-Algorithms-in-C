#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int f;
    int r;
    int *arr;
};

void queueTraversal(struct Queue *q)
{
    for (int i = q->f + 1; i <= q->r; i++)
    {
        printf("Element : %d\n", q->arr[i]);
    }
}

int isFull(struct Queue *q)
{
    if (q->r == q->size - 1)
        return 1;
    else
        return 0;
}

// Insertion at rear - Normal queue behaviour
void enQueueRear(struct Queue *q, int data)
{
    if (isFull(q))
    {
        printf("Queue Overflow\n");
    }
    else
    {
        q->arr[++q->r] = data;
    }
}
// Insert at front
void enQueueFront(struct Queue *q, int data)
{
    if (q->f == -1)
    {
        printf("Cannot insert at Front\n");
    }
    else
    {
        q->arr[q->f] = data;
        q->f--;
    }
}

// Deletion at front - Normal behaviour
int deQueueFront(struct Queue *q)
{
    int elem = -1;
    if (q->r == q->f)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        q->f++;
        elem = q->arr[q->f];
    }

    return elem;
}
int deQueueRear(struct Queue *q)
{
    int elem = -1;
    if (q->r == q->f)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        elem = q->arr[q->r];
        q->r--;
    }

    return elem;
}

void main()
{
    struct Queue q;
    q.size = 10;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    printf("Queue Insertion At Rear end\n");
    enQueueRear(&q, 10);
    enQueueRear(&q, 20);
    enQueueRear(&q, 30);
    enQueueRear(&q, 40);
    enQueueRear(&q, 50);
    enQueueRear(&q, 60);
    enQueueFront(&q, 70);

    printf("\nQueue Traversal after insertion\n");
    queueTraversal(&q);

    printf("\nQueue Deletion Operation\n");
    printf("Removed Element %d\n", deQueueFront(&q));
    printf("Removed Element %d\n", deQueueFront(&q));
    printf("Removed Element %d\n", deQueueFront(&q));
    printf("Removed Element %d\n", deQueueRear(&q));
    printf("Removed Element %d\n", deQueueRear(&q));

    printf("\nQueue Traversal after deletion\n");
    queueTraversal(&q);

    printf("Queue Insertion At Front end\n");
    enQueueFront(&q, 70);
    enQueueFront(&q, 80);

    printf("\nQueue Traversal after insertion at Front\n");
    queueTraversal(&q);

    printf("Removed Element %d\n", deQueueRear(&q));
    printf("Removed Element %d\n", deQueueRear(&q));
    printf("Removed Element %d\n", deQueueRear(&q));
    printf("Removed Element %d\n", deQueueRear(&q));

    printf("\nQueue Traversal\n");
    queueTraversal(&q);
}