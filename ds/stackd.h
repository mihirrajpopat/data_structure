#include<stdio.h>


//structure for the stack
struct stack 
{
	int *sta;
	int n;
	int top;
	int ele;
};

//for user choice 
void op()
{
	
		printf("\n\n=============== \n");
		printf("1 = push       ||\n");
		printf("2 = pop        ||\n");
		printf("3 = peak       ||\n");
		printf("4 = change     ||\n");
		printf("5 = display    ||\n");
		printf("6 = interchange||\n");
		printf("7 = exit       ||\n");
		printf("=============== \n");
		
		printf("ENTER YOUR CHOICE:= ");
}


//for the piush element in the stack
void push(struct stack *s)
{
	//check stack is empty of not 
				
	if(s->top==s->n-1)
	{
		printf("stack is over flow \n");
	
	}
	else
	{
		//push element in to the stack
		s->top++;
		s->sta[s->top]=s->ele;
				
	}	
}


//pop element in to the stack 
int pop(struct stack *s)
{
	//check stack under flow or not 
	if(s->top==-1)
	{
		printf("stack is under flow \n");
	
	}
	else
	{
		//return the element and pop
		return s->sta[s->top--];		
	}	
}

//display the stack 
void disp(struct stack *s)
{
	//check element 
	if(s->top==-1)
	{
		printf("stack is under flow ");
	}
	else
	{
		
		
		printf("\n stack element    \n");
		printf("  ===========\n");
		
		for(int i=s->top;i>=0;i--)
		{
			printf("||    %d   ||\n",s->sta[i]);
		
		}
		printf("  =========\n");
	}
	
}


//return the top 
int peak(struct stack *s)
{
	if(s->top==-1)
	{
		printf("stack is under flow");	

	}	
	else
	{
		return s->sta[s->top];
	}	
}
//change the stack value 	
void change(struct stack *s)
{
	int w,new;
	int temp=-1;
	if(s->top==-1)
	{
		printf("stack is under flow ");
	}
	else
	{
		printf("which element youwant to change ");
		scanf("%d",&w);
		for(int i=s->top;i>=0;i--)
		{
			if(w==s->sta[i])
			{
				temp=i;
				break;
			}
		}
		if(temp>=0)
		{
			printf("enter new element ");
			scanf("%d",&new);
			s->sta[temp]=new;
	
		}
		else
		{
			printf("element not found ");
		}
	}			
	
}
//inter change the value of the stack
void inter(struct stack *s)
{
	int dtemp=-1;
	int stemp=-1,temp,sno,dno;
	
	if(s->top==0)
	{
		printf("stack is under flow");
	}
	
	else
	{
		printf("which element you want to change with whom\n");
		printf("enter source number ");
		scanf("%d",&sno);
		printf("enter destination  number ");
		scanf("%d",&dno);
		for(int i=s->top;i>=0;i--)
		{
			if(sno==s->sta[i])
			{
				stemp=i;
				break;
			}
			
		}
		for(int i=s->top;i>=0;i--)
		{
			if(dno==s->sta[i])
			{
				dtemp=i;
				break;
			}
			
		}
		
		
		if(stemp>=0 || dtemp>=0)
		{
			temp=s->sta[stemp];
			s->sta[stemp]=s->sta[dtemp];
			s->sta[dtemp]=temp;
		}
		else
		{
			printf("wromg number ");
		}
		
		
		
		
		
	}
}
