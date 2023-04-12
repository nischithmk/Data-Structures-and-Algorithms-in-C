#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
        return 1;
    else
        return 0;
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
        return 1;
    else
        return 0;
}

void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
        printf("Stack Overflow, Cannot push %d to stack\n", val);
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack underflow, Cannot pop stack\n");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

// pee function to find the element at given index
int peek(struct stack *ptr, int pos)
{
    int ind = ptr->top - pos + 1;
    if (ind < 0)
    {
        printf("Invalid position\n");
        return -1;
    }
    else
    {
        return ptr->arr[ind];
    }
}

int topOfStack(struct stack *s)
{
    if (isEmpty(s))
        return -1;
    else
    {
        return s->arr[s->top];
    }
}

int bottomOfStack(struct stack *s)
{
    if (isEmpty(s))
        return -1;
    else
    {
        return s->arr[0];
    }
}
void main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    printf("Stack has been created successfully\n");

    // check if satck is empty or not before insertion
    printf("\nChecking stack before push operation for isFull and isEmpty condition\n");
    if (isEmpty(s))
        printf("The stack is empty\n");
    else
        printf("The stack is not empty\n");

    // check if satck is full or not before insertion
    if (isFull(s))
        printf("The stack is full\n");
    else
        printf("The stack is not full\n");

    // calling push function to insert data in stack
    printf("\nStack push operation\n");
    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);
    push(s, 50); // --> pushed 5 elements to stack
    push(s, 60); // --> this will give stack overflow

    printf("\nChecking stack after push operation, for isFull and isEmpty condition\n");
    // check if satck is empty or not after insertion
    if (isEmpty(s))
        printf("The stack is empty\n");
    else
        printf("The stack is not empty\n");

    // check if satck is full or not after insertion
    if (isFull(s))
        printf("The stack is full\n");
    else
        printf("The stack is not full\n");

    // pop operation
    printf("\nStack pop operation\n");
    printf("Popped %d from stack\n", pop(s));
    // printf("Popped %d from stack\n", pop(s));
    // printf("Popped %d from stack\n", pop(s));
    // printf("Popped %d from stack\n", pop(s));
    // printf("Popped %d from stack\n", pop(s));
    // printf("Popped %d from stack\n", pop(s));

    printf("\nChecking stack after pop operation, for isFull and isEmpty condition\n");
    // check if satck is empty or not after insertion
    if (isEmpty(s))
        printf("The stack is empty\n");
    else
        printf("The stack is not empty\n");

    // check if satck is full or not after insertion
    if (isFull(s))
        printf("The stack is full\n");
    else
        printf("The stack is not full\n");

    // peek operation
    printf("\nStack peek operation\n");
    for (int j = 1; j <= s->top + 1; j++)
    {
        printf("The value at index %d is %d\n", j, peek(s, j));
    }

    // stack top  operation
    printf("\nStack top operation\n");
    int topofstack = topOfStack(s);
    if (topofstack == -1)
        printf("Stack is empty\n");
    else
        printf("Top element of the stack is %d\n", topofstack);

    // stack bottom operation
    printf("\nStack bottom operation\n");
    int bottomofstack = bottomOfStack(s);
    if (bottomofstack == -1)
        printf("Stack is empty\n");
    else
        printf("Top element of the stack is %d\n", bottomofstack);
}