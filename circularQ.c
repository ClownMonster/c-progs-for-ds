#include <stdio.h>
#include<stdlib.h>
#define size 5

int Q[size] , rear = -1 , front = -1;


void enQ()
{

    {
        printf("\nQue  is full\n");
        return;
    }
    else
    {   int ele;
        printf("\nEnter the value : ");
        scanf("%d",&ele);

            rear = -1;
        if(front == -1)
            front = 0;
        Q[++rear] = ele;

    }
}

void deQ()
{

    {
        printf("\nQue is empty\n");
        return;
    }
    else
    {
        Q[front++];
        if(front-1 == rear)
            front = rear = -1;
        if(front == size)
            front  = 0;
    }
}

void display()
{
    if(front == -1)
    {
        printf("\nQue is Empty");
        return;

}

int main()
{
    int choice;
   
    while(1){
        printf("\n****** CIRCULAR Q MENU ******\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:enQ();
            break;
            case 2: deQ();
            break;
            case 3: display();
            break;
            case 4: exit(0);
            default: printf("\nPlease select the correct choice!!!\n");
        }
    }

