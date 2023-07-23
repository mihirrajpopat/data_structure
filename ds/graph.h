#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdlib.h>
#include"stack_list.h"
#include"queue_list.h"

typedef struct gnode
{
	int data, weight;
	struct gnode *next;
}gnode;

typedef struct 
{
	gnode **adjli;
	int vertax, edge;
	int type;
}ugraph;

gnode *createnode(int data, int weight)
{
	gnode *newnode = (gnode *)malloc(sizeof(gnode));
	newnode->next = NULL;
	newnode->data = data;
	newnode->weight = weight;
	return newnode;
}

void set_initial_pos_ugraph(ugraph *g, int v, int e, int t)
{
	g->vertax = v;
	g->edge = e;
	g->type = t;
	
	g->adjli = (gnode **)malloc(sizeof(gnode *) * g->vertax);
	for(int i=0; i<g->vertax; i++)
	{
		g->adjli[i] = createnode(i+1, 1);					
	}
}

bool insertLast(gnode *head, int data, int weight)
{
	gnode *newnode = createnode(data, weight);
	if(newnode==NULL)
		return false;

	gnode *curr = head;
	while(curr->next!=NULL)
	{	
		curr=curr->next;	
	}
	curr->next = newnode;
	return true;
}


void create_undirect_graph(ugraph *g)
{	
	for(int i=0; i<g->edge; i++)
	{
		int u, v, w=1;
		//printf("Enter any two veratx : ");
		scanf("%d %d", &u, &v);
		if(g->type == 0)
		{
		//	printf("Enter edge weight : ");
			scanf("%d", &w);	
		}
		insertLast(g->adjli[u-1], v, w);
		insertLast(g->adjli[v-1], u, w);
	}	
}

void displayUgraph(ugraph *g)
{
	printf("Graph list is....\n");
	for(int i=0; i<g->vertax; i++)
	{
		for(gnode *curr = g->adjli[i]; curr!=NULL; curr = curr->next)
		{
			if(g->type==0)
				printf("{ %d, %d } -> ", curr->data, curr->weight);
			else
				printf("{ %d } -> ", curr->data, curr->weight);
		}
		printf("\n");					
	}	
}

void dfs_list(ugraph *g, int sp)
{
	stack *s = (stack *)malloc(sizeof(stack));
	set_initial_pos(s);
	
	bool visited[g->vertax];
	
	for(int i=0; i<g->vertax; i++)
		visited[i] = false;
		
	push(s, sp);
	visited[sp-1] = true;
	
	while(!isEmptyStack(s))
	{
		int res = pop(s);
		printf("| %d |",  res);
		
		for(gnode *curr = g->adjli[res-1]->next; curr!=NULL;curr = curr->next)
		{
			if(visited[curr->data-1] == false)
			{
				visited[curr->data-1] = true;
				push(s, curr->data);
			}
		}
	}
	printf("\n");
}

void bfs_list(ugraph *g, int sp)
{
	queue *q = (queue *)malloc(sizeof(queue));
	set_initial_pos_queue(q);
	
	bool visited[g->vertax];
	
	for(int i=0; i<g->vertax; i++)
		visited[i] = false;
		
	enque(q, sp);
	visited[sp-1] = true;
	
	while(!isEmptyQueue(q))
	{
		int res = deque(q);
		printf("| %d |",  res);
		
		for(gnode *curr = g->adjli[res-1]->next; curr!=NULL;curr = curr->next)
		{
			if(visited[curr->data-1] == false)
			{
				visited[curr->data-1] = true;
				enque(q, curr->data);
			}
		}
	}
	printf("\n");
}


//direct graph 
typedef struct
{
	int **adjmat;
	int vertax, edge;
	int type;
}dgraph; 

void set_initial_pos_dgraph(dgraph *g, int v, int e, int t)
{
	g->vertax = v;
	g->edge = e;
	g->type = t;
	
	g->adjmat = (int **)malloc(sizeof(int *) * g->vertax);
	for(int i=0; i < g->vertax; i++)
	{
		g->adjmat[i] = (int *)malloc(sizeof(int) * g->vertax);
	}
	
	for(int i=0; i<g->vertax; i++)
	{
		for(int j=0; j<g->vertax; j++)
		{
			g->adjmat[i][j] = 0;
		}
	}
}

void create_dgraph(dgraph *g)
{
	for(int i=0; i<g->edge; i++)
	{
		int u, v, w=1;
		//printf("Enter any two veratx : ");
		scanf("%d %d", &u, &v);
		if(g->type == 0)
		{
		//	printf("Enter edge weight : ");
			scanf("%d", &w);	
		}
		g->adjmat[u-1][v-1] = w;	
	}	
}

void displayDgraph(dgraph *g)
{
	printf("Graph matrix is....\n");
	for(int i=0; i<g->vertax; i++)
	{
		for(int j=0; j<g->vertax; j++)
		{
			printf("| %2d |", g->adjmat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void dfs_mat(dgraph *g, int sp)
{
	bool visited[g->vertax];
	for(int i=0; i<g->vertax; i++)
	{
		visited[i] = false;
	}
	
	stack *s = (stack *)malloc(sizeof(stack));
	set_initial_pos(s);
	
	sp--;
	visited[sp] = true;
	push(s, sp);
	
	while(!isEmptyStack(s))
	{
		int res = pop(s);
		printf("| %d |", res+1);
		for(int i=0; i<g->vertax; i++)
		{
			if(g->adjmat[res][i] >0 && visited[i]==false)
			{
				visited[i] = true;
				push(s, i);
			}
		}
	}
	printf("\n");
}

void bfs_mat(dgraph *g, int sp)
{
	bool visited[g->vertax];
	for(int i=0; i<g->vertax; i++)
	{
		visited[i] = false;
	}
	
	queue *q = (queue *)malloc(sizeof(queue));
	set_initial_pos_queue(q);
	
	sp--;
	visited[sp] = true;
	enque(q, sp);
	
	while(!isEmptyQueue(q))
	{
		int res = deque(q);
		printf("| %d |", res+1);
		for(int i=0; i<g->vertax; i++)
		{
			if(g->adjmat[res][i] > 0 && visited[i]==false)
			{
				visited[i] = true;
				enque(q, i);
			}
		}
	}
	printf("\n");
}
