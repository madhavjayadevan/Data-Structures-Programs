#include<stdio.h>
#define N 5
int Q[N],Pr[N];
int r = -1,f = -1;
void enqueue(int data,int p)
{
	int i;
	if(r==N-1)
		printf("Queue is full");
	else
	{
		if(f==-1)
		{
			f = r = 0;
			Q[r] = data;
			Pr[r] = p;

		}
		else
		{
			for(i = r;i>=f;i--)
			{
				if(p>Pr[i])
				{
					Q[i+1] = Q[i];
					Pr[i+1] = Pr[i];	
				}
				else
					break;
			}
			Q[i+1] = data;
			Pr[i+1] = p;
			r++;
		}	
	}

}
void print() //print the data of Queue
{
int i;
	for(i=f;i<=r;i++)
	{
		printf("\nElement = %d\tPriority = %d",Q[i],Pr[i]);
	}
}
int dequeue() //remove the data from front
{
	if(f == -1)
	{
		printf("Queue is Empty");
	}	
	else
	{
		printf("\ndeleted Element = %d\t Its Priority = %d",Q[f],Pr[f]);
		if(f==r)
			f = r = -1;
		else
			f++;
	}
}
void main()
{
	int opt,data,p;
	do{
		printf("\n\n1. Insert the Data\n2. Show the Data\n3. Delete the data\n0. Exit");
		printf("\nEnter Your Choice:-");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				printf("\nEnter your data and Priority of data:-");
				scanf("%d %d",&data,&p);
				enqueue(data,p);
				break;
			case 2:
				print();
				break;
			case 3:
				 dequeue();
				break;
			case 0:
				break;
			default:
				printf("\nIncorrect Choice");

		}
	}while(opt!=0);
}