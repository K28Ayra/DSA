#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;                    //Data of the node
    struct node *next;       //Address of the node
}*q;
  

void createNodeList(int n)
{
    struct node *p, *tmp;
    int item, i;
    q = (struct node *)malloc(sizeof(struct node));
    if(q == NULL) 			
    {
        printf(" Memory can not be allocated.");
    }
    else
    {
// reads data for the node through keyboard
        printf(" Input data for node 1 : "); //head node
        scanf("%d", &item);
        q-> data = item;      
        q-> next = NULL; //Links the address field to NULL
        tmp = q;
//Creates n nodes and adds to linked list
        for(i=2; i<=n; i++)
        {
            p = (struct node *)malloc(sizeof(struct node));
            if(p == NULL) 			//check whether the p is NULL and if so no memory allocation
            {
                printf(" Memory can not be allocated.");
                break;
            }
            else
            {
                printf(" Input data for node %d : ", i);
                scanf(" %d", &item);
                p->data = item; 
                p->next = NULL; 
                 tmp->next = p;
                tmp = tmp->next;
            }
        }
    }
} 
//tmp stored the whole list, forst q(head) and then rest of the nodes are assigned to it.
  //function to create the list


void FirstNodeDeletion()
{
    struct node *toDelptr;
    if(q == NULL)
    {
        printf(" There are no node in the list.");
    }
    else
    {
        toDelptr = q;
        q = q->next;
        free(toDelptr);  // Clears the memory occupied by first node
    }
}	    //function to delete the first node

//at end..
void deleteAtEnd()
{  
        struct node *ptr,*ptr1;  
        if(q == NULL)  
        {  
            printf("\nThe list is empty.");  
        }  
        else if(q -> next == NULL)  
        {  
            q = NULL;  
            free(q);  
           
        }  
 
        else  
        {  
            ptr = q;   
            while(ptr->next != NULL)  
                {  
                    ptr1 = ptr;  
                    ptr = ptr ->next;  
                }  
                ptr1->next = NULL;  
                free(ptr);  
                
            }     
        }

void deleteInBetween( int index)
{
struct node *ptr;
    struct node *p ;
     p=q;
        p = p->next;
        q = p->next;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next;
    free(q);
}

//by value


// struct node *deleteByValue(struct node *head, int value)
// {

//     struct node *p = head;
//     struct node *q = head->next;
//     while (q->next != NULL && q->data != value)
//     {
//         p = p->next;
//         q = q->next;
//     }
//     if (q->data == value)
//     {
//         p->next = q->next;
//         free(q);
//         return head;
//     }
// }

void displayList()
{
    struct node *tmp;
    if(q == NULL)
    {
        printf(" No data found in the list.");
    }
    else
    {
        tmp = q;
        printf("[");
        while(tmp != NULL)
        {
            printf(" %d ", tmp->data);   // prints the data of current node
            tmp = tmp->next;                 // advances the position of current node
        }
        printf("]");
    }
}            //function to display the list


int main()
{
    int n,num,index,x;
		printf("\n\n Linked List:\n");
		printf("------------------------------------------------------------\n");
    printf(" Input the number of nodes : ");
    scanf("%d", &n);
    createNodeList(n);
    printf("\n The Linked List is : \n");		
    displayList();
printf("\nENTER:\n 1= Deleting 1st node,\n 2= Deleting Last node\n 3= Deleting in between \n 4= DEleting by a given value\n\n ENTER=");
scanf("%d",&x);

if(x==1){
//deleting 1st node
    FirstNodeDeletion();
    printf("\n Data, after deletion of first node : \n");		
    displayList();
}

else if(x==2){
    deleteAtEnd();
 printf("\nDeletion of the last node\n");
        displayList();
}
else {
     
     printf("\nEnter index=");
     scanf("%d",&index);
     printf("\nAfter Deletion\n");
     deleteInBetween(index);
 
        displayList();
}

// else{
//     printf("\nDeletion by a given data/key\n");
//        deleteByValue(head, 11);
//         displayList();
// }
    return 0;
}



