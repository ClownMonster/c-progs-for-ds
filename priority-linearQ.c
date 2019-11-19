#include <string.h>
#include<stdio.h>
#include<stdlib.h>
#define size 5

int Q[size], rear = -1;


void EnQ()
{
    if(rear == size-1)
        {
            printf("Que is full\n");
            return;
        }
    else
    {   printf("\nEnter the value : ");
        int ele, i ;
        scanf("%d",&ele);
        
        if(rear == -1)
        {
            Q[++rear] = ele;
            return;
        }
        else
        {   
            for(i = rear; i>= 0; i--)
            {
                if(ele > Q[i])
                    Q[i+1] = Q[i];
                else
                    break;

            }//end of for

            Q[i+1] = ele;
            rear++;
        }
    }
}


void DQ()
{
    if(rear == -1)
    {
        printf("\nQue is Empty\n");
        return;
    }
    else
    {
        Q[rear--];
    }
}

void display()
{
    if(rear == -1)
    {
        printf("\nQue is Empty\n");
        return;
    }
    else
    {   int i;
        printf("\n");
        for(i=0; i<=rear;i++)
            printf("%d",Q[i]);
    }
}

int main()
{ int choice;
    while(1)
    {
        printf("\n1.EnQ\n2.DQ\n3.display\n4.Exit\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: EnQ();
                    break;

            case 2: DQ();
                    break;

            case 3: display();
                    break;

            case 4: exit(0);

            default : printf("\nInvalid choice\n");
        }
    }



return 0;
}