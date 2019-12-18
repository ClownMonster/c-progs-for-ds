#include <stdio.h>
#include<stdlib.h>

typedef struct node{
 	int data;
 	struct node *next;
}node;

typedef struct Queue
{
	struct node *front, *rear;
}Queue;

Queue* Q ;

void create_Queue()
{	
	Q->front = Q->rear = NULL;
	return;
}


void push()
{	
	node* temp = (node *)malloc(sizeof(node));
	printf("\nEnter the data to be pushed : ");
	scanf("%d",&temp->data);
	temp->next = NULL;
	if(Q->rear == NULL)
	{
		Q->front = Q->rear = temp;
		return;
	}

	Q->rear->next = temp;
	Q->rear = temp;
}

void pop()
{
	if(Q->front == NULL)
	{
		printf("\nQueue is Empty\n");
		return;
	}
	node* temp = Q->front;
	Q->front = Q->front->next;
	free(temp);
	if(Q->front == NULL)
	Q->rear = NULL;
}

void display()
{	
	if(Q->front == NULL)
	{
		printf("\nQueue is Empty\n");
		return;
	}
	printf("\nQueue Elements : ");
	node* temp = Q->front;
	while(temp != NULL)
	{
		printf("%d\t",temp->data);
		temp = temp->next;
		
	}
}

int main()
{

	int choice;
	 Q = (Queue *)malloc(sizeof(Queue));
	create_Queue();
	while(1)
	{
		printf("\n1.EnQ\n2.DeQ\n3.display\n4.Exit\nEnter Your Choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: push();
					break;
			case 2 : pop(); break;

			case 3 : display(); break;

			case 4: exit(0);

			default: printf("\nInvalid option\n");
		}
	}
return 0;
}