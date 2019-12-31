
#include <stdio.h>
#include<stdlib.h>
#include <math.h> 

typedef struct polynode
{
    int coeff;
    int power;
    struct polynode *next;
}polynode;

polynode *head;

//Creating the polynomial
void createPolynomial()
{
    polynode *ptr, *newnode, *prev;
    ptr = newnode = prev = NULL;
    int coeff, power;
    printf("Input is terminated when coeff & power value equals 0  i,e for the last element x^0\n");
    printf("Enter the coeff and power :");
    scanf("%d %d", &coeff, &power); 
    while(coeff != 0) // base condition for input 
    {
        newnode = (polynode *)malloc(sizeof(polynode));
        newnode->coeff = coeff;
        newnode->power = power;
        newnode->next = NULL; 
        if(head == NULL)
            head = newnode ; 
        else 
        {
            if(newnode->power > head->power) // newnode's power value is larger than head node's power
            {
                newnode->next = head;
                head = newnode; //Newnode becomes head
            }
            else
            {
                ptr = head;
                while( (ptr!= NULL) && (newnode->power  < ptr->power) )
                {
                    prev = ptr;
                    ptr = ptr->next;
                }
                if(ptr == NULL)    //When current last node is reached
                {
                    prev->next = newnode;
                    newnode->next = ptr; //newnode becomes last node
                }
                else //For newnode has intermediate power values
                {
                    prev->next = newnode;//newnode power value is greater than OR equal to current node
                    newnode->next = ptr;
                }
            }
        }
        
        printf("\nEnter value of coeff and power : ");
        scanf("%d %d", &coeff,&power);
    }
}


int evaluatePolynomial()
{
    polynode *ptr = head;
     if(head == NULL)
    {
        printf("Empty\n");
        return 0;
    }
    int result = 0, x = 0;
    printf("Enter the value of X in the Polynomial  \n");
    scanf("%d", &x);
    while(ptr!= NULL) 
    {
        result = result + ptr->coeff * pow(x, ptr->power);
        ptr = ptr->next;
    }
    return result;
}


void displayPolynomial()
{
    polynode *ptr;
    if(head == NULL)
    {
        printf("Empty\n");
        return;
    }
    ptr = head;
    while(ptr!= NULL) 
    {
        printf("%d*x^%d + ", ptr->coeff, ptr->power);
        ptr = ptr->next;
    }
    printf("NULL"); 
}
int main()
{
    int choice, result;
    for(;;)
    {
        printf("\n1.Create Polynomial\n2.Evaluate\n3.Display\n4.Exit\nEnter your choice :");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                createPolynomial();
                printf("\nUse Option 3 to display the polynomial After Creation");
                break;
            case 2:
                result = evaluatePolynomial();
                printf("\nResult is %d", result);
                break;
            case 3:
                printf("\nPolynomial is ");
                displayPolynomial();
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid option\n\n");
                break;
        }
    }
}
