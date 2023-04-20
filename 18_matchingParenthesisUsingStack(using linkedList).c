#include <stdio.h>
#include <stdlib.h>

struct stack
{
    char elem;
    struct stack *next;
};

int isEmpty(struct stack *ptr)
{
    if (ptr == NULL)
    {
        return 1;
    }
    else
        return 0;
}

struct stack *push(struct stack *ptr, char element)
{
    struct stack *newNode = (struct stack *)malloc(sizeof(struct stack));
    newNode->elem = element;
    newNode->next = ptr;
    return newNode;
}

struct stack *pop(struct stack **ptr)
{
    struct stack *p = *ptr;
    *ptr = (*ptr)->next;
    free(p);
    return *ptr;
}

int matchingParenthesis(char *exp)
{
    struct stack *s = NULL;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            s = push(s, '(');
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(s))
            {
                return 0;
            }
            else
            {
                pop(&s);
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
    char *expression = "(8-(6+5)*(38))/(2*5)(";
    if (matchingParenthesis(expression))
    {
        printf("Parenthesis is matching");
    }
    else
    {
        printf("Parenthesis is NOT matching");
    }
}