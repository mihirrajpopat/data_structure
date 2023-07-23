#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char data;
    struct node* next;
}*head[2],*last[2];
typedef struct node node;


//sort the linklist
//reach at middle
//use last  pointer :doubt

node* create()
{
   node *newnode=(node*)malloc(sizeof(node));
   return newnode;
}

void display(int i)
{
    if(head[i]==NULL)
    {
        printf("\nempty");
    }
    else{
            node *temp=head[i];
            printf("\n");
        while(temp!=NULL)
        {
            printf(" %c ",temp->data);
            temp=temp->next;
        }
    }
}
void insert_at_last(char a,int i)
{
   node *newnode = create();
   newnode->data=a;
   newnode->next=NULL;

   if(head[i]==NULL)
   {
       head[i]=newnode;
       last[i]=newnode;
   }
   else{
    last[i]->next=newnode;
    last[i]=newnode;
   }

}

int compare()
{

    if(head[0]==NULL || head[1]==NULL)
    {
        //printf("\nString is empty");
        return 2;
    }
    else{
            node *temp1=head[0],*temp2=head[1];

        while(temp1!=NULL || temp2!=NULL)
        {

            if(temp1->data == temp2->data)
            {
                if(temp1->next==NULL && temp2->next!=NULL)
                {
                    return -1;
                }
                if(temp1->next!=NULL && temp2->next==NULL)
                {
                    return 1;
                }
                temp1=temp1->next;
                temp2=temp2->next;
                continue;
            }
            if(temp1->data > temp2->data)
            {
                return 1;
            }
            else{
                return -1;
        }
        return 0;
    }
}
}
void string_compare()
{
   // node *string_head1=NULL,*string_head2=NULL;

    char str1[100],str2[100];

    printf("Enter string 1 : ");
    scanf("%s",str1);
    for(int i=0;i<strlen(str1);i++)
    {
       insert_at_last(str1[i],0);
    }

    display(0);

    printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    printf("\n Enter string 2 : ");
    scanf("%s",str2);
    for(int i=0;i<strlen(str2);i++)
    {
       insert_at_last(str2[i],1);
    }
    display(1);

    printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    int res = compare();

    if(res==1)
    {
        printf("\n result : %d -> String 1 is greater than string 2",res);
    }
    else if(res==-1)
    {
        printf("\n result : %d -> String 2 is greater than string 1",res);
    }
    else if(res==2){
        printf("\n One or both String are empty",res);
    }
    else{
        printf("\n result : %d -> Both string are same",res);
    }
    printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    return;
}
