struct queue
{
	int *qu;
	int f;
	int r;
	int n;
	int ele;
};
void opq()
{
	
		printf("\n\n=============== \n");
		printf("1 = Enqueue     ||\n");
		printf("2 = Dqueue      ||\n");
		printf("3 = Rear        ||\n");
		printf("4 = Front       ||\n");
		printf("5 = Isfull      ||\n");
		printf("6 = IsEmpty     ||\n");
		printf("7 = exit        ||\n");
		printf("=============== \n");
				
		printf("ENTER YOUR CHOICE:= ");
}

int enqueue(struct queue *q)
{
	if(q->f==q->n)
	{
		q->f=-1;
		q->r=-1;
	}
	if(q->r==q->n-1)
	{
		printf("stack is overflow");
		
	}
	else
	{
		if(q->f==-1)
		{
			q->f=0;
			
			
		}
		q->r++;
		q->qu[q->r]=q->ele;
	}
	
}

int dispq(struct queue *q)
{
	if(q->f==-1 || q->f==q->n)
	{
		printf("queue is empty");
		
	}
	else
	{
		printf("\n......queue is......\n");
		printf("====================\n");
		printf("|");
		for(int i=q->f;i<=q->r;i++)
		{			
			printf(" %d |",q->qu[i]);
		}
		printf("\n====================\n");
		
	}	
	
}

int isfull(struct queue *q)
{
	if(q->r==q->n-1)
	{
		printf("Queue is full \n");
		return 1;
	}
	else
	{
		printf("still space");
		return 0;
	}	
}
int isempty(struct queue *q)
{
	if(q->f==-1 || q->f==q->n)
	{
		printf("\nQueue is empty");
		return 0;
	}
	else
	{
		
		return 1;
	}
	
}
int dqueue(struct queue *q)
{
	if(q->f==-1 || q->f==q->n)
	{
		printf("queue is empty");
	}
	else
	{
		return q->qu[q->f++];
		
	}
}
int front(struct queue *q)
{
	if(q->f==-1 || q->f==q->n)
	{
		printf("queue is empty");
	}	
	else
	{
		return q->qu[q->f];
	}
}
int rear(struct queue *q)
{
	if(q->r==q->n-1)
	{
		printf("Queue is overflow");
		
	}	
	else
	{
		return q->qu[q->r];
	}
}












		
		
		
