#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node 
{
	int data;
	struct node *next;
}node;

typedef struct stack
{
	node *top;
}stack;

void set_initial_pos(stack *s)
{
	s->top = NULL;
}

bool isEmptyStack(stack *s)
{
	return s->top==NULL;
}

node *createNode(int data)
{
	node *newnode = (node *)malloc(sizeof(node));
	newnode->data = data;
	newnode->next = NULL;
	return newnode;
}

int pop(stack *s)
{
	if(isEmptyStack(s))
		return 0;
		
	int res;
	node *curr = s->top;
	res = s->top->data;
	s->top = s->top->next;
	free(curr);
	curr=NULL;
	return res;
}

bool push(stack *s, int no)
{
	node *newnode = createNode(no);
	if(newnode==NULL)
		return false;
	if(s->top!=NULL)
		newnode->next = s->top;
	s->top = newnode;
	return true;
}

int peek(stack *s)
{
	if(isEmptyStack(s))
		return 0;
	return s->top->data;
}

void displayStack(stack *s)
{
	if(isEmptyStack(s))
	{	
		printf("Stack is empty");
	}
	else
	{
		for(node *curr = s->top; curr!=NULL; curr=curr->next)
			printf("%d -> ", curr->data);
		printf("\n");
	}
}
