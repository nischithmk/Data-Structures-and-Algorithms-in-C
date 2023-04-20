#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traverseLinkedList(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int isFull()
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL)
        return 1;
    else
        return 0;
}

int isEmpty(struct Node *ptr)
{
    if (ptr == NULL)
        return 1;
    else
        return 0;
}

struct Node *push(struct Node *ptr, int data)
{
    if (isFull())
        printf("Stack Overflow\n");
    else
    {
        struct Node *p = (struct Node *)malloc(sizeof(struct Node));
        p->data = data;
        p->next = ptr;
        return p;
    }
}

int pop(struct Node **ptr)
{

    if (isEmpty(*ptr))
        printf("Stack Underflow\n");
    else
    {
        struct Node *p = *ptr;
        *ptr = (*ptr)->next;
        int dt = p->data;
        free(p);
        return dt;
    }
}

int topOfStack(struct Node *ptr)
{
    if (isEmpty(ptr))
        printf("Stack is empty");
    else
    {
        return ptr->data;
    }
}
int bottomOfStack(struct Node *ptr)
{
    if (isEmpty(ptr))
        printf("Stack is empty");
    else
    {
        struct Node *p = ptr;
        while (p->next != NULL)
        {
            p = p->next;
        }
        return p->data;
    }
}

int peek(struct Node *ptr, int pos)
{
    struct Node *p = ptr;
    int i = 1;
    while (p != NULL && i != pos)
    {
        p = p->next;
        i++;
    }
    if (p != NULL)
    {

        printf("Element at position %d is %d\n", pos, p->data);
    }
    else
    {
        printf("Invalid position\n");
    }
}
void main()
{

    struct Node *top = NULL;

    printf("Check stack isFull isEmpty before push operation\n");
    if (isFull())
        printf("Stack is full\n");
    if (isEmpty(top))
        printf("stack is empty\n");

    printf("\nStack push operation\n");
    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);
    top = push(top, 40);

    printf("\nStack traversal after push operation\n");
    traverseLinkedList(top);

    printf("\nStack pop operation\n");
    printf("Popped element is %d\n", pop(&top));
    // printf("Popped element is %d\n", pop(&top));
    // printf("Popped element is %d\n", pop(&top));

    printf("\nStack traversal after pop operation\n");
    traverseLinkedList(top);

    printf("\nTop of stack operation\n");
    printf("Top element of stack is %d\n", topOfStack(top));

    printf("\nBottom of stack operation\n");
    printf("Bottom element of stack is %d\n", bottomOfStack(top));

    printf("\nStack peek operation\n");
    peek(top, 4);
}
