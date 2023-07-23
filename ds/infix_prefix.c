#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char data;
    struct node* next;
}*stack_top=NULL,*infix_top=NULL,*prefix_head=NULL,*prefix_last=NULL;
typedef struct node node;

node* create(char a)
{
   node *newnode=(node*)malloc(sizeof(node));
   newnode->next=NULL;
   newnode->data=a;
   return newnode;
}

int isOperator(char a)
{
    return (a == '*' || a == '/' || a == '+' || a == '-' || a=='^');
}

int precedence(char a)
{
    switch(a)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
}
char pop_stack()
{
        node *temp=stack_top;
        char a=temp->data;
        stack_top=stack_top->next;
        free(temp);
        return a;
}

void insert_prefix(char a)
{
    node *newnode = create(a);

    if(prefix_head==NULL)
    {
        prefix_head=newnode;
        prefix_last=newnode;
        return;
    }

    prefix_last->next=newnode;
    prefix_last=newnode;
    return;
}
void insert_infix(char a)
{
    node *newnode = create(a);

    if(infix_top==NULL)
    {
        infix_top=newnode;
        return;
    }

    newnode->next=infix_top;
    infix_top=newnode;
    return;
}

void insert_stack(char a)
{

    if(stack_top==NULL)
    {
        node *newnode = create(a);
        stack_top=newnode;
        return;
    }

    if(precedence(a)>=precedence(stack_top->data) || a==')' || stack_top->data==')')
    {
          node *newnode = create(a);
          newnode->next=stack_top;
          stack_top=newnode;
          return;
    }

    if(precedence(a)<precedence(stack_top->data))
    {
        char b = pop_stack();
        insert_prefix(b);
        insert_stack(a);
    }

    return;
}

void display()
{
     node *temp=prefix_head;
            printf("\n");
        while(temp!=NULL)
        {
            printf(" %c ",temp->data);
            temp=temp->next;
        }

}

void reverse_linklist()
{
    if(prefix_head==NULL)
    {
        printf("\nempty");
    }
    else if(prefix_head->next==NULL){
        printf("\n only 1 element");
    }
    else
    {
            node *prev=prefix_head,*curr;
            prefix_last=prefix_head;
            prefix_head=prefix_head->next;
            curr=prefix_head;
            prev->next=NULL;
            while(prefix_head!=NULL)
            {
                prefix_head=prefix_head->next;
                curr->next=prev;
                prev=curr;
                curr=prefix_head;
            }
            prefix_head=prev;
    }
}

void infix_prefix()
{
    char infix[100];

    printf("\n Enter Infix String : ");
    scanf("%s",infix);

    for(int i=0;i<strlen(infix);i++)
    {
        insert_infix(infix[i]);
    }

    node *temp=infix_top;
    while(temp!=NULL)
    {
        if(isalnum(temp->data))
        {
           insert_prefix(temp->data);
           temp=temp->next;
           continue;
        }
        if(temp->data=='(')
        {
            while(stack_top->data!=')')
            {

                char a = pop_stack();
                insert_prefix(a);

            }
            pop_stack();
            temp=temp->next;
            continue;
        }
        if(temp->data==')')
        {
             insert_stack(temp->data);
             temp=temp->next;
             continue;
        }
        else if(isOperator(temp->data))
        {
            insert_stack(temp->data);
            temp=temp->next;
            continue;
        }
        if(!isOperator(temp->data))
        {
            printf("\n %c is not an operator ",temp->data);
        }
    }

    while(stack_top!=NULL)
    {
        char a=pop_stack();
        insert_prefix(a);
    }

    reverse_linklist();
    printf("\n Prefix Expression : ");
    display();
}
