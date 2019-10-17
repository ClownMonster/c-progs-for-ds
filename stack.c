#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define SIZE 5
int stack[SIZE],Enter = 0,top = -1,del = -1 ;
int pop();
void push();
void display();
int main()
{
  printf("******stack Menu******\n");
  printf("Enter your Choice\n");
  printf("1.Push\n2.Pop\n3.Display\n4.exit\n\n");
  scanf("\n%d",&Enter);
  while(1)
    {
      switch (Enter)
      {
      case 1:   push();
                main();
                break;
      case 2:
               del = pop();
               if(del>= 0)
                 printf("%d is the popped item from the stack\n",del);
               else 
                  printf("\n");
               main(); 
               break;
      case 3:
              display();
              printf("\n");
              main();
              break;
      case 4: printf("\n******Terminating the program *******\n");
              exit(0);
              
              
      default: printf("\nInvalid choice\n");
               main();
               break;
      }
    }
}

void push()
{ if(top == SIZE -1)
  {
    printf("stack overflow\n");
    return;
  }
  else
  {
    printf("enter the number to be pushed into the stack\n");
    scanf("%d",&stack[++top]);
    return;
  }
}

int pop()
{
  if(top == -1)
  {
    printf("Stack underflow\n");
    return 0;
  }
  else{
    del = stack[top];
    --top;
    return del;
  }
}

void display()
{ int i;
  for(i=0;i<=top;i++)
  printf("%d\n",stack[i]);
  return;
}
