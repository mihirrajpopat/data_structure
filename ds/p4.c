#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>


struct con{
 int cust_id;
 char name[50];
 char phone_number[11];
};

struct node{
 struct con *data;
 struct node *next;
};

struct list{
 struct node *head;
 struct node *last;
 int count;
};
typedef struct node node;
typedef struct list list;
typedef struct con con;
void set_pos(list *li)
{
 li->head=NULL;
 li->last=NULL;
 li->count=0;
}
node *createnode(list *li,con *c1)
{
 node *newnode=(node *)malloc(sizeof(node));
 newnode-> data=(con *)malloc(sizeof(con));
 newnode->data->cust_id=c1->cust_id;
 strcpy(newnode->data->name,c1->name);
 strcpy(newnode->data->phone_number,c1->phone_number);
 newnode->next=NULL;
 li->count++;
 return newnode ;
}
bool Insert_first(list *li,con *c1)
{
  node *newnode=createnode(li,c1);
  if(newnode==NULL)
   return false;

  if(li->head==NULL)
  {
   li->head=newnode;
   li->last=newnode;
   li->last->next=li->head;
   return true;
  }
  else
  {
   newnode->next=li->head;
   li->head=newnode;
   li->last->next=li->head;
   return true;
  }
}
bool Insert_last(list *li,con *c1)
{
 node *newnode=createnode(li,c1);
  if(newnode==NULL)
   return false;
 if(li->head==NULL)
 {
  li->head=newnode;
  li->last=newnode;
  li->last->next=li->head;
  return true;
 }
 else
 {
  li->last->next=newnode;
  li->last=newnode;
  li->last->next=li->head;
  return true;
 }
}
void Display_contact(list *li,con *c1)
{
 if(li->head==NULL)
 {
  printf("list is empty....\n");
  return;
 }

 node *temp=li->head;
 do
 {
  printf("| | %2d | | %10s | | %10s | |\n",temp->data->cust_id,
 temp->data->name,temp->data->phone_number);
  temp=temp->next;
 }while(temp!=li->head);
}
bool Insert_specific(list *li,con *c1,int index)
{
 index--;
 node *temp=li->head;
 if(li->count > index)
 {
  node *newnode=createnode(li,c1);
  if(newnode==NULL)
  return false;

  if(index==0)
  {
   newnode->next=li->head;
   li->head=newnode;
   li->last->next=li->head;
   return true;
  }

  for(int i=1; i<index ;i++)
  {
   temp=temp->next;
  }
   newnode->next=temp->next;
   temp->next=newnode;
    return true;
 }
 return false;
}
bool Delete_first(list *li)
{
 if(li->head==NULL)
 {
  return false;
 }
 else
 {
  if(li->last==li->head)
  {
   node *temp=li->head;
   printf("| %d | | %s | | %s |\n",temp->data->cust_id,
   temp->data->name,temp->data->phone_number);
   set_pos(li);
   free(temp);
  }
  else
  {
   node *temp=li->head;
   li->head=li->head->next;
   printf("| %d | | %s | | %s |\n",temp->data->cust_id,
   temp->data->name,temp->data->phone_number);
   li->last->next=li->head;
   free(temp);
  }

  li->count--;
  return true;
 }
}
bool Delete_last(list *li)
{

 if(li->head==NULL)
 {
  return false;
 }
 else
 {
  node *temp=li->head;
  if(li->head==li->last)
  {
   temp=li->head;
   printf("| %d | | %s | | %s |\n",temp->data->cust_id,
   temp->data->name,temp->data->phone_number);
   set_pos(li);
   free(temp);
  }
  else
  {
   while(temp->next->next != li->head)
   {
    temp=temp->next;
   }
   node *temp2=temp->next;
   li->last=temp;
   li->last->next=li->head;
   printf("| %d | | %s | | %s |\n",temp2->data->cust_id,
   temp2->data->name,temp2->data->phone_number);
   free(temp2);
  }

  li->count--;
  return true;
 }

}
bool delete_specific(list *li,con *c1,int index)
{
 index--;
 node *temp=li->head;
 if(li->count > index)
 {
  if(index==0)
  {
   Delete_first(li);
   return true;
  }
  else
  {
   for(int i=1; i<index ;i++)
   {
    temp=temp->next;
   }
    node *temp2=temp->next;
     temp->next=temp->next->next;
    printf("| %d | | %s | | %s |\n",temp2->data->cust_id,
    temp2->data->name,temp2->data->phone_number);
    free(temp2);
    li->count--;
   return true;
  }
 }
 return false;
}
void Display_sorted(list *li,con *c1)
{
 con *temp3;
 if(li->head==NULL)
  printf("ERROR : list is Empty");
 else
 {
  for(node *temp=li->head ; temp->next !=li->head ; temp=temp->next)
  {
   for(node *temp2=li->head ; temp2->next !=li->head ;temp2=temp2->next)
   {
    if(temp2->data->cust_id >
temp2->next->data->cust_id)
{
     temp3=temp2->next->data;
     temp2->next->data=temp2->data;
     temp2->data=temp3;
    }
   }
  }
  Display_contact(li,c1);
 }

}
int Search_name(list *li,con *c1,char n[])
{
  int flag=0;
  node *temp=li->head;
  do
  {
   flag++;
   if(strcmp(temp->data->name,n)==0)
   {
    return flag;
   }
   temp=temp->next;
  }while(temp != li->head);
  return 0;
}
int Search_id(list *li,con *c1,int id)
{
int flag=0;
  node *temp=li->head;
  do
  {
   flag++;
   if(id == temp->data->cust_id)
   {
    return flag;
   }
   temp=temp->next;
  }while(temp != li->head);
  return 0;
}
int Search_pn(list *li,con *c1,char pn[])
{
int flag=0;
  node *temp=li->head;
  do
  {
   flag++;
   if(strcmp(temp->data->phone_number,pn)==0)
   {
    return flag;
   }
   temp=temp->next;
  }while(temp != li->head);
  return 0;
}
bool delete_name(list *li,con *c1,char n[])
{
   // if(head)
 int flag1=Search_name(li,c1,n);
 if(flag1==0)
 {
  return false;
 }
 else
 {
  delete_specific(li,c1,flag1);
  return true;
 }
}
bool delete_id(list *li,con *c1, int id)
{
 int flag1=Search_id(li,c1,id);
 if(flag1==0)
 {
  return false;
 }
 else
 {
  delete_specific(li,c1,flag1);
  return true;
 }
}
bool delete_pn(list *li,con *c1,char pn[])
{
 int flag1=Search_pn(li,c1,pn);
 if(flag1==0)
 {
  return false;
 }
 else
 {
  delete_specific(li,c1,flag1);
  return true;
 }
}

int main()
{
 char line[]="________________________________________\n";
  list *li = (list *)malloc(sizeof(list));
  con  *c1 = (con *)malloc(sizeof(con));
   if(li == NULL)
   {
      printf("ERROR : list memory is not allocated....\n");
      exit(0);
   }
   set_pos(li);
   for(;;)
   {
       char n[30];
       int index;
       char pn[30];
       int no;
     printf("%s", line);
     printf("1.  Insert first contact\n");
     printf("2.  Insert last contact \n");
     printf("3.  Insert specific index contact\n");
     printf("4.  Delete sepcific position contact\n");
     printf("5.  Delete first contact\n");
     printf("6.  Delete last contact\n");
     printf("7.  Display sorted order\n");
     printf("8.  Search contact by name\n");
     printf("9.  Search contact by customer id\n");
     printf("10. Search contact by phone number\n");
     printf("11. Delete contact by name\n");
     printf("12. Delete contact by customer id\n");
     printf("13. Delete contact by phone number\n");
     printf("14. Display contact list\n");
     printf("15. Exit Program\n");
     printf("%s", line);

     int ch;
     printf("Enter your choise : ");
     scanf("%d", &ch);

     switch(ch)
     {
   case 1:
    printf("Enter customer id: ");
    scanf("%d",&c1->cust_id);

    printf("Enter the name of customer: ");
    scanf("%s",c1->name);

    printf("Enter customer phone number: ");
    scanf("%s",c1->phone_number);

    if(Insert_first(li,c1)==true)
    {
     printf("node is added on first pos...\n");
    }
    else
    {
     printf("ERROR not added...\n");
    }
     break;
   case 2:
    printf("Enter customer id: ");
    scanf("%d",&c1->cust_id);

    printf("Enter the name of customer: ");
    scanf("%s",c1->name);

    printf("Enter customer phone number: ");
    scanf("%s",c1->phone_number);

    if(Insert_last(li,c1)==true)
    {
     printf("node is added on last pos...\n");
    }
    else
    {
     printf("ERROR not added...\n");
    }
     break;
   case 3:

    printf("Enter customer id: ");
    scanf("%d",&c1->cust_id);

    printf("Enter the name of customer: ");
    scanf("%s",c1->name);

    printf("Enter customer phone number: ");
    scanf("%s",c1->phone_number);

    printf("Enter index Num: ");
    scanf("%d",&index);

    if(Insert_specific(li,c1,index))
    {
     printf("node is added...\n");
    }
    else
    {
     printf("ERROR......\n");
    }
     break;
   case 4:
       if(li->head==NULL)
       {
            printf("\nList is Empty\n");
       }
       else
       {
           printf("Enter index Num: ");
            scanf("%d",&index);

            if(delete_specific(li,c1,index))
            {
             printf("Node is delete...\n");
            }
            else
            {
             printf("No such index......\n");
            }
       }

     break;
   case 5:
    if(Delete_first(li))
    {
     printf("data is deleted.....\n");
    }
    else
{
     printf("List Empty...\n");
    }

     break;
   case 6:
    if(Delete_last(li))
    {
     printf("data is deleted.....\n");
    }
    else
    {
     printf("List Empty...\n");
    }
     break;
   case 7:

        if(li->head==NULL)
       {
            printf("\nList is Empty\n");
       }
       else
       {
            Display_sorted(li,c1);
       }
     break;
   case 8:
        if(li->head==NULL)
       {
            printf("\nList is Empty\n");
       }
       else
       {
             printf("Enter the name of customer: ");
            scanf("%s",n);

            if(Search_name(li,c1,n)==0)
            {
             printf("ERROR: not found...\n");
            }
            else
            {
             printf("name is in list....\n");
            }

       }

        break;
   case 9:

         if(li->head==NULL)
       {
            printf("\nList is Empty\n");
       }
       else
       {
            printf("Enter customer id: ");
            scanf("%d",&no);

            if(Search_id(li,c1,no)==0)
            {
             printf("ERROR: not found...\n");
            }
            else
            {
             printf("number is in list....\n");
            }
       }
     break;
   case 10:

         if(li->head==NULL)
       {
            printf("\nList is Empty\n");
       }
       else
       {
            printf("Enter the phone number: ");
            scanf("%s",pn);

            if(Search_pn(li,c1,pn)==0)
            {
             printf("ERROR: not found...\n");
            }
            else
            {
             printf("phone number is in list....\n");
            }
       }
     break;
   case 11:

        if(li->head==NULL)
       {
            printf("\nList is Empty\n");
       }
       else
       {
            printf("Enter the name of customer: ");
            scanf("%s",n);

            if(delete_name(li,c1,n))
            {

             printf("deleted ....\n");
            }
            else
            {
             printf("ERROR: not found...\n");
            }
       }
     break;
   case 12:

        if(li->head==NULL)
       {
            printf("\nList is Empty\n");
       }
       else
       {
            printf("Enter the id of customer: ");
            scanf("%d", &no);

            if(delete_id(li,c1,no))
            {
             printf("deleted ....\n");
            }
            else
            {
             printf("ERROR: not found...\n");
            }
       }
     break;
   case 13:

        if(li->head==NULL)
       {
            printf("\nList is Empty\n");
       }
       else
       {
            printf("Enter the phone number of customer: ");
            scanf("%s",pn);

            if(delete_pn(li,c1,pn))
            {
             printf("deleted ....\n");
            }
            else
            {
             printf("ERROR: not found...\n");
            }
       }
     break;
   case 14:
     Display_contact(li,c1);
     break;
   case 15:
     exit(0);
   default:
     printf("ERROR : Your choise is invalid....\n");
  }
 }
}
