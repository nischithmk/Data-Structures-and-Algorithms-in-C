#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *nextNode;
};

void insertToLinkedList(struct Node *head, struct Node *first, struct Node *second,
                        struct Node *third, struct Node *fourth, struct Node *fifth)
{
    head->data = 10;        // assign value 10 to head node
    head->nextNode = first; // point the headnode to first node
    first->data = 20;
    first->nextNode = second;
    second->data = 30;
    second->nextNode = third;
    third->data = 40;
    third->nextNode = fourth;
    fourth->data = 50;
    fourth->nextNode = fifth;
    fifth->data = 60;
    fifth->nextNode = NULL;
}

void displayLinkedList(struct Node *head)
{
    while (head != NULL)
    {
        if (head->nextNode == NULL)
        {
            printf("%d ", head->data);
            head = head->nextNode;
        }
        else
        {
            printf("%d -> ", head->data);
            head = head->nextNode;
        }
    }
}

struct Node *deleteFirstNode(struct Node *head)
{
    struct Node *ptr = head;
    head = head->nextNode;
    free(ptr);
    return head;
}

struct Node *deleteLastNode(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->nextNode;

    while (q != NULL)
    {
        if (q->nextNode == NULL)
        {
            p->nextNode = NULL;
        }
        p = p->nextNode;
        q = q->nextNode;
    }
    free(p);
    free(q);
    return head;
}

struct Node *deleteNodeAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->nextNode;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->nextNode;
        q = q->nextNode;
    }
    p->nextNode = q->nextNode;
    free(q);
    return head;
}

struct Node *deleteGivenNode(struct Node *head, struct Node *deleteNode)
{
    struct Node *p = head;
    struct Node *q = head->nextNode;
    while (q != deleteNode)
    {
        p = p->nextNode;
        q = q->nextNode;
    }
    p->nextNode = q->nextNode;
    free(q);
    return head;
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *first = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fifth = (struct Node *)malloc(sizeof(struct Node));

    insertToLinkedList(head, first, second, third, fourth, fifth);
    printf("\nLinked list is  : ");
    displayLinkedList(head);

    head = deleteFirstNode(head);
    printf("\n\nTraversal after deletion of first node : ");
    displayLinkedList(head);

    head = deleteLastNode(head);
    printf("\n\nTraversal after deletion of last node : ");
    displayLinkedList(head);

    head = deleteNodeAtIndex(head, 2);
    printf("\n\nTraversal after deletion of given index node : ");
    displayLinkedList(head);

    struct Node *node_to_delete = second; // replace with node to delete of your choice
    head = deleteGivenNode(head, node_to_delete);
    printf("\n\nTraversal after deletion of given node : ");
    displayLinkedList(head);
}
