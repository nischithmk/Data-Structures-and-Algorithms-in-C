#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
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

    struct Node *newHead = ptr;
    ptr = ptr->next;
    free(newHead);
    return ptr;
};

struct Node *deleteLast(struct Node *ptr)
{
    struct Node *p = ptr;
    struct Node *q = ptr->next;

    while (q->next != NULL)
    {
        q = q->next;
        p = p->next;
    }
    p->next = NULL;
    free(q);

    return ptr;
}

struct Node *deleteAfterNode(struct Node *ptr, int searchData)
{
    struct Node *p = ptr;
    struct Node *q = ptr->next;

    while (p != NULL)
    {
        if (p->data == searchData)
        {
            p->next = q->next;
            q->next = NULL;
            free(q);
        }
        p = p->next;
        q = q->next;
    }
    return ptr;
};

struct Node *deleteBeforeNode(struct Node *ptr, int searchData)
{
    struct Node *p = ptr;
    struct Node *q = ptr->next;
    struct Node *r = ptr->next->next;

    if (p->data == searchData)
    {
        printf("No nodes presnt before node %d", searchData);
    }
    else if (q->data == searchData)
    {
        p->next = NULL;
        free(p);
        return q;
    }
    else
    {
        while (q != NULL)
        {
            if (q->data == searchData)
            {
                p->next = q->next;
                q->next = NULL;
                free(q);
            }
            p = p->next;
            q = q->next;
        }
    }
    return ptr;
};

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
    fifth->next = NULL;

    printf("Linked list traversal\n");
    traverseList(head);

    printf("\nLinked list delete first operation\n");
    head = deleteFirst(head);
    printf("\nLinked list traversal\n");
    traverseList(head);

    printf("\nLinked list delete last operation\n");
    head = deleteLast(head);
    printf("\nLinked list traversal\n");
    traverseList(head);

    printf("\nLinked list delete AfterNode operation\n");
    head = deleteAfterNode(head, 20);
    printf("\nLinked list traversal\n");
    traverseList(head);

    printf("\nLinked list delete BeforeNode operation\n");
    head = deleteBeforeNode(head, 50);
    printf("\nLinked list traversal\n");
    traverseList(head);
}