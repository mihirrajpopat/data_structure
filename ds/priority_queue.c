
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data,priority;
    struct node* next;
}*front=NULL,*rear=NULL;
typedef struct node node;




node* create()
{
   node *newnode=(node*)malloc(sizeof(node));
   return newnode;
}
void dequeue()
{
    if(front==NULL)
    {
        printf("\nempty");
    }
    else if(front==rear)
    {
        printf("\n%d node having priority %d is completed\n",front->data,front->priority);
        free(front);
        rear=NULL;
        front=NULL;
    }
    else
    {
        node *temp=front;
        temp=front->next;
        printf("\n%d node having priority %d is completed\n",front->data,front->priority);
        free(front);
        front=temp;
    }
}
void display()
{
    if(front==NULL)
    {
        printf("\nempty");
    }
    else{

            node *temp=front;
            printf("\n");
        while(temp!=NULL)
        {
            printf("| %d has priority : %d |\n",temp->data,temp->priority);
            temp=temp->next;
        }
    }
}

void enqueue()
{
    node *newnode = create();

    int a;
    printf("\nEnter data : ");
   scanf("%d",&a);
   newnode->data=a;
    printf("\nEnter priority : ");
   scanf("%d",&a);
   newnode->priority=a;
   newnode->next=NULL;
    if(front==NULL)
   {
       front=newnode;
       rear=newnode;
   }
   else if(front->priority>=a)
    {
         node *temp=front;
        front=newnode;
        newnode->next=temp;
    }
    else if(rear->priority<=a)
    {
        rear->next=newnode;
        rear=newnode;
    }
   else
    {
        node* temp=front;

        while(temp->next!=NULL)
        {

            if(temp->priority<=a && temp->next->priority>=a)
            {
                node *temp1;
                temp1=temp->next;
                temp->next=newnode;
                newnode->next=temp1;
                break;
            }
            temp=temp->next;
        }
   }
}
