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

char pop(struct stack *ptr, char data)
{
    char elem = ptr->arr[ptr->top];
    ptr->top--;
}

int match(char popChar, char topChar)
{
    if (popChar == '(' && topChar == ')')
        return 1;
    if (popChar == '[' && topChar == ']')
        return 1;
    if (popChar == '{' && topChar == '}')
        return 1;
}

int matchingParenthesis(char *exp)
{
    struct stack *s;
    s->size = 100;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));
    char popped_char;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            push(s, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if (isEmpty(s))
            {
                return 0;
            }
            else
            {
                popped_char = pop(s, exp[i]);
                if (!match(popped_char, exp[i]))
                    return 0;
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
    char *expression = "{1+(2-4)/[2-5]})";
    if (matchingParenthesis(expression))
    {
        printf("Parenthesis is matching");
    }
    else
    {
        printf("Parenthesis is NOT matching");
    }
}