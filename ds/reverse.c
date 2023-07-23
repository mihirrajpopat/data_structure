#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
}*head=NULL,*reverse_head=NULL;
typedef struct node node;


//sort the linklist
//reach at middle
//use last  pointer :doubt

node* create()
{
   node *newnode=(node*)malloc(sizeof(node));
   return newnode;
}
void insert_at_first()
{
   node *newnode = create();

   int a;
   printf("\nEnter data : ");
   scanf("%d",&a);
   newnode->data=a;
    newnode->next=NULL;
   if(head==NULL)
   {
       head=newnode;
   }
   else
   {
       node *temp=head;
        head=newnode;
        newnode->next=temp;
   }
}
void display()
{
    if(head==NULL)
    {
        printf("\nempty");
    }
    else{

            node *temp=head;
            printf("\n");
        while(temp!=NULL)
        {
            printf("%d",temp->data);
            if(temp->next!=NULL)
            {
                printf(" -> ");
            }
            temp=temp->next;
        }
    }
}
void insert_at_last()
{
   node *newnode = create();

   int a;
   printf("\nEnter data : ");
   scanf("%d",&a);
   newnode->data=a;
   newnode->next=NULL;

   if(head==NULL)
   {

       head=newnode;
   }

   else{

        node *temp=head;

        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
   }

}

void delete_at_last()
{
    if(head==NULL)
    {
        printf("\n empty");
    }
    else if(head->next==NULL)
    {
        free(head);
        head=NULL;

    }
    else
    {
        node *temp=head;
        while(temp->next->next!=NULL)
        {

            temp=temp->next;
        }
        free(temp->next);
        temp->next=NULL;
    }
}

void delete_at_first()
{
    if(head==NULL)
    {
        printf("\n empty");
    }
    else if(head->next==NULL)
    {
        free(head);
        head=NULL;
    }
    else
    {
        node *temp=head->next;
        free(head);
        head=temp;
    }
}
bool isEmpty(node *head)
{
    if(head==NULL)
        return false;

    else
        return true;
}
void reverse_linklist(int k)
{
    int first=1,i=1;
    node *last1=head,*last2=NULL,*head1=NULL;

    node *prev=head;
    head=head->next;
    node *curr=head;
    prev->next=NULL;


    while(head!=NULL)
    {
        if(i<k)
        {
            if(i==0)
            {
                last2=curr;
            }
            head=head->next;
            curr->next=prev;
            prev=curr;
            curr=head;
            i++;
        }

        if(i==k && first==1)
        {
            head1=prev;
            i=0;
            first=0;
            prev=NULL;
        }

        if(first==0 && i==k)
        {
            last1->next=prev;
            last1=last2;
            i=0;
             prev=NULL;
        }
    }

    if(head1==NULL)
    {
        head=prev;
        return;
    }

    if(i!=0)
    {
        last1->next=prev;
    }

    head=head1;
}

