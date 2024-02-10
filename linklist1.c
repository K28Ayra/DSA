#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next; // self referencing structure
};
// traversal

void traversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element:%d\n", ptr->data);
        ptr = ptr->next;
    }
}

// insertion at the beginning of the linked list
struct node *insertAtFirst(struct node *head, int data)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

// insertion in between
struct node *insertInBetween(struct node *head, int data, int index)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

// insertion at the end

struct node *insertAtEnd(struct node *head, int data)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

// insertion after a node
struct node *insertAfterNode(struct node *head, struct node *prevNode, int data)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;

    // dynamic alllocation of linked list in heap
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    // assigning values to it...

    head->data = 7;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 34;
    third->next = NULL;

    // call traversal function
    traversal(head);

    // insertion at first call
    printf("\nAfter insertion(at first)\n");
    head = insertAtFirst(head, 78); // update head cz now our new head is new element's head;
    traversal(head);
    printf("\nInsertion in between\n");
    head = insertInBetween(head, 55, 2);
    traversal(head);

    printf("\nInsertion at the end\n");
    head = insertAtEnd(head, 99);
    traversal(head);

    printf("\nInsertion after a node\n");
    head = insertAfterNode(head, second, 111);
    traversal(head);

    return 0;
}
