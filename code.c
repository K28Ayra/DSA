#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 /// global variable

int values[MAX_SIZE];    
int *pointers[MAX_SIZE]; //pointer array
int size = 0;

// insertion
void insert(int value)
{
    if (size < MAX_SIZE)
    {
        values[size] = value;
        pointers[size] = &values[size]; // allocating memory
        size++;
        printf("Value inserted.\n");
    }
    else
    {
        printf("List is full. Cannot insert more values.\n");
    }
}

// deletion
void delete(int value)
{
    int index = -1; // first initialize i to -1
    for (int i = 0; i < size; i++)
    {
        if (*pointers[i] == value)
        {
            index = i; // if value found update index
            break;
        }
    }

    if (index == -1)
    {
        printf("Value not found in the list.\n");
        return;
    }

    for (int i = index; i < size - 1; i++)
    { // deletion happens here and shifitng
        pointers[i] = pointers[i + 1];
    }
    size--;
    printf("Value deleted from the list.\n");
}
// search
void search(int value)
{
    for (int i = 0; i < size; i++)
    {
        if (*pointers[i] == value)
        {
            printf("Value found at location  %d in the list.\n", i);
            return;
        }
    }
    printf("Value not found in the list.\n");
}

// to display
void display()
{
    printf("List: [");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", *pointers[i]);
    }
    printf(" ]\n");
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\nOptions:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insert(value);
            break;
        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            delete (value);
            break;
        case 3:
            printf("Enter value to search: ");
            scanf("%d", &value);
            search(value);
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);

        default:
            printf("invalid choice.");
        }
    }
    return 0;
}