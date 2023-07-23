#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"graph.h"

char line[]="===================================================\n";

int main()
{
	int edge, vertax, weight, direct;
	
	//printf("Enter graph is 0. direct 1. undirect : ");
	scanf("%d", &direct);
	
	//printf("Enter graph is 0. weight 1. unweight : ");
	scanf("%d", &weight);
	
	//printf("Enter no of vertax : ");
	scanf("%d", &vertax);
	
	//printf("Enter no of edge : ");
	scanf("%d", &edge);
	
	if(direct==0)
	{
		dgraph *dg = (dgraph *)malloc(sizeof(dgraph));
		if(dg==NULL)
		{	
			printf("ERROR : Memory is not allocated.....\n");
			exit(0);
		}
		set_initial_pos_dgraph(dg, vertax, edge, weight);
		create_dgraph(dg);
		displayDgraph(dg);
		
		printf("%sDFS is.....\n", line);
		int sp;
		scanf("%d", &sp);
		dfs_mat(dg, sp);
		printf("%sBFS is.....\n", line);
		bfs_mat(dg, sp);
	}
	else
	{
		ugraph *ug = (ugraph *)malloc(sizeof(ugraph));
		if(ug==NULL)
		{	
			printf("ERROR : Memory is not allocated.....\n");
			exit(0);
		}
		set_initial_pos_ugraph(ug, vertax, edge, weight);
		create_undirect_graph(ug);
		displayUgraph(ug);
		
		printf("%sDFS is.....\n", line);
		int sp;
		scanf("%d", &sp);
		dfs_list(ug, sp);
		printf("%sBFS is.....\n", line);
		bfs_list(ug, sp);
	}
	return 1; 
}
