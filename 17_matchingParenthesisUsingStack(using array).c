#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
        return 0;
}

void push(struct stack *ptr, char element)
{
    ptr->top++;
    ptr->arr[ptr->top] = element;
}

int pop(struct stack *ptr)
{
    char elem = ptr->arr[ptr->top];
    ptr->top--;
}

int matchingParenthesis(char *exp)
{
    struct stack *s;
    s->size = 100;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(s, '(');
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(s))
            {
                return 0;
            }
            else
            {
                pop(s);
            }
        }
    }
    if (isEmpty(s))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void main()
{
    char *expression = "8-(6+5*(38))/(2*5))(";
    if (matchingParenthesis(expression))
    {
        printf("Parenthesis is matching");
    }
    else
    {
        printf("Parenthesis is NOT matching");
    }
}