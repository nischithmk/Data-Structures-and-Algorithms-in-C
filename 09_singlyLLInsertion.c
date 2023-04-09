#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    /* data */
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
}

void searchList(struct Node *ptr, int searchData)
{
    int count = 0;
    bool found = false;
    while (ptr != NULL)
    {
        count += 1;
        if (ptr->data == searchData)
            found = true;
        ptr = ptr->next;
    }

    if (found)
        printf("Data found at position %d", count);
    else
        printf("Data not found..!");
}

struct Node *insertAfter(struct Node *ptr, int searchData, int data)
{
    // struct Node *headNode = ptr;
    bool found = false;
    while (ptr != NULL)
    {

        if (ptr->data == searchData)
        {
            found = true;
            struct Node *insertAfterNode = (struct Node *)malloc(sizeof(struct Node));
            insertAfterNode->data = data;
            insertAfterNode->next = ptr->next;
            ptr->next = insertAfterNode;
            printf("Node inserted successfully after data - %d", searchData);
            break;
        }
        ptr = ptr->next;
    }
    if (!found)
    {
        printf("Search node not found and data not inserted..! ");
    }
}

struct Node *insertBefore(struct Node *ptr, int searchData, int data)
{
    struct Node *nextNode = ptr->next;
    bool found = false;
    struct Node *insertBeforeNode = (struct Node *)malloc(sizeof(struct Node));

    if (ptr->data == searchData)
    {
        found = true;
        insertBeforeNode->data = data;
        insertBeforeNode->next = ptr;
        printf("Node inserted successfully Before data - %d", searchData);
        return insertBeforeNode;
    }
    else
    {
        while (nextNode != NULL)
        {
            if (nextNode->data == searchData)
            {
                found = true;

                insertBeforeNode->next = ptr->next;
                ptr->next = insertBeforeNode;
                printf("Node inserted successfully Before data - %d", searchData);
                return insertBeforeNode;
            }
            nextNode = nextNode->next;
            ptr = ptr->next;
        }
    }
    if (!found)
    {
        printf("Search node not found and data not inserted..! ");
    }
}

void inserAtEnd(struct Node *ptr, int data)
{
    struct Node *insertEndNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *headNode = ptr;
    bool found = false;
    while (headNode->next != NULL)
    {
        headNode = headNode->next;
    }
    insertEndNode->data = data;
    headNode->next = insertEndNode;
    insertEndNode->next = NULL;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    // allocate memory in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // insert data to nodes and link to next node
    head->data = 10;
    head->next = second;
    second->data = 20;
    second->next = third;
    third->data = 30;
    third->next = fourth;
    fourth->data = 40;
    fourth->next = NULL;

    printf("\n\nTraverse Linked List function call executing\n");
    traverseList(head);
    printf("\n\nSearch Linked List function call executing\n");
    searchList(head, 0);
    printf("\n\nLinked List Insert After Function Call Executing\n");
    insertAfter(head, 40, 1000);
    printf("\n\nTraverse Linked List after calling InsertAfter\n");
    traverseList(head);
    printf("\n\nLinked List Insert Before Function Call Executing\n");
    head = insertBefore(head, 10, 2000);
    printf("\n\nTraverse Linked List After Calling InsertBefore\n");
    traverseList(head);
    printf("\n\nLinked List Delete Function Call Executing\n");
    inserAtEnd(head, 500);
    printf("\n\nTraverse Linked List After Calling Delete\n");
    traverseList(head);
    return 0;
}