#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
        return 1;
    else
        return 0;
}
int isOperator(char elem)
{
    if (elem == '*' || elem == '/' || elem == '+' || elem == '-' || elem == '(' || elem == ')')
    {
        return 1;
    }
    else
        return 0;
}

int precedence(char elem)
{
    if (elem == '/' || elem == '*')
        return 3;
    if (elem == '+' || elem == '-')
        return 2;
    else
        return 0;
}

char stackTop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}

void push(struct stack *ptr, char elem)
{
    ptr->top++;
    ptr->arr[ptr->top] = elem;
    printf("--> %c\n", ptr->arr[ptr->top]);
}

char pop(struct stack **ptr)
{

    char elem = (*ptr)->arr[(*ptr)->top];
    (*ptr)->top--;
    return elem;
}

char *infixToPostfix(char *exp)
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 100;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));
    char *postfix = (char *)malloc((strlen(exp) + 1) * sizeof(char));
    int j = 0;
    int i = 0;
    while (exp[i] != '\0')
    {
        if (!isOperator(exp[i]))
        {
            postfix[j] = exp[i];
            j++;
            i++;
        }
        else if (exp[i] == '(')
        {
            push(s, exp[i]);
            i++;
        }
        else if (exp[i] == ')')
        {
            while (s->top > -1 && stackTop(s) != '(')
            {
                postfix[j++] = stackTop(s);
                i++;
                s->top--;
            }
            if (s->top > -1 && stackTop(s) != '(')
                return "Invalid Expression";
            else
                pop(&s);
        }
        else if (isOperator(exp[i]))
        {
            if (precedence(exp[i]) > precedence(stackTop(s)))
            {
                push(s, exp[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(&s);
                j++;
            }
        }
    }

    while (!isEmpty(s))
    {
        postfix[j] = pop(&s);
        j++;
    }

    postfix[j] = '\0';
    return postfix;
}

void main()
{

    char *expression = "m-n*(p/z)";
    printf("The Infix expression is %s\n", expression);
    printf("The Postfix expression is %s\n", infixToPostfix(expression));
}