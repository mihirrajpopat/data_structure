#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct qnode 
{
	int data;
	struct qnode *next;
}qnode;

typedef struct queue
{
	qnode *rear;
	qnode *front;
}queue;

void set_initial_pos_queue(queue *q)
{
	q->front = q->rear = NULL;
}

bool isEmptyQueue(queue *q)
{
	return q->rear==NULL;
}

qnode *createNodeQueue(int data)
{
	qnode *newnode = (qnode *)malloc(sizeof(qnode));
	newnode->data = data;
	newnode->next = NULL;
	return newnode;
}

int deque(queue *q)
{
	if(isEmptyQueue(q))
		return 0;
		
	int res;
	qnode *curr = q->front;
	res = q->front->data;
	
	if(q->front==q->rear)
	{	
		q->front = q->rear = NULL;
		return res;
	}
	
	q->front = q->front->next;
	free(curr);
	curr=NULL;
	return res;
}

bool enque(queue *q, int no)
{
	qnode *newnode = createNodeQueue(no);
	if(newnode==NULL)
		return false;
	
	if(isEmptyQueue(q))
		q->front = q->rear = newnode;
	else
	{
		q->rear->next = newnode;
		q->rear =  newnode;	
	}
	return true;
}
/*
void displayQueue(queue *q)
{
	if(isEmptyQueue(q))
		printf("Queue empty");
	else
	{
		for(qnode *curr = q->front; curr!=NULL; curr = curr->next)
			printf("| %d |", curr->data);
		printf("\n");
	}
}
*/
