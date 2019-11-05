#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct student
{
	int rollno; char name[20];
	struct student *next;
}student; //student variable for the structure

int srollno = 0, scount = 0; char sname[20]; student *head = NULL , *sptr = NULL;

void demo_options()
{
	printf("*******Single Linked List********\n");
	printf("1.Demo Options\n2.Search\n3.Insert\n4.Delete\n5.Print Details\n6.Quit");
}

student * search(student *sptr,int srollno)
{	
	if(head == NULL)
	{
		printf("List is Empty\n");
		return NULL;
	}

	else
	{
		while(sptr != NULL)
		{ 	if(sptr->rollno == srollno)
				return sptr;
			else sptr = sptr->next;
		}
		return NULL;
	}
}

void print_Details(student *sptr)
{
	if(head == NULL )
	{
		printf("Empty List\n");
		return;
	}
	else
	{
		printf("\nNumber of students in the list is : %d",scount);
		printf("\nHead Address : %d\n\n",head);
		while(sptr != NULL)
		{
			printf("\nthis node Address : %d \t\tRoll number : %d\t || \t\tName : %s",sptr,sptr->rollno,sptr->name);
			sptr = sptr->next;
			printf("\t\t\tNext node Address : %d",sptr);
		}
		printf("\n");
		printf("\n");
	}
}

student * create_new_node(student *next)
{
	student *newstudent = (student *)malloc(sizeof(student));
	strcpy(newstudent->name,sname);
	newstudent->rollno = srollno;
	newstudent->next = next;
	scount++;
	return newstudent;	
}

student * Insert(student *head)
{
	printf("Enter the Roll Number : "); scanf("%d",&srollno);
	printf("Enter the Name : "); scanf("%s",sname);
	int position;
	int rollposition;
	
	if(head == NULL)
	{
		printf("\nYou are the first student to enroll\n");
		student *newstudent = create_new_node(head);
		head = newstudent;
		return head;
	}

	else if(head != NULL)
	{
		sptr = NULL;
		printf("Do you want to insert After or Before a Roll NUmber >>\n Enter 1 to inster After \n Enter 0 to insert Before \n >> : ");
		scanf("%d",&position);

		if(position == 0)
		{	
			printf("\nEnter the Roll number of the student you want to insert before : ");
			scanf("%d",&rollposition);
		}

		else if(position == 1)
		{
			printf("\n Enter the Roll number of the student you want to insert after : ");
			scanf("%d",&rollposition);
		}

		else
		{
			printf("\nInvalid choice\n");
		}

		//searching the student with rollposition 
		sptr = search(head , rollposition);

		if(sptr != NULL)
		{
			if(position == 1 && sptr->next == 0) //end node check
			{
				printf("\nInserting After the End Node\n");
				student *newstudent = create_new_node(sptr->next);
				sptr->next = newstudent;
			}

			else if(position == 1 && sptr->next != NULL)
			{
				printf("\nInserting after a  Middle Node\n");
				student *newstudent = create_new_node(sptr->next);
				sptr->next = newstudent;
			}

			else if(position == 0 && sptr == head)
			{
				printf("\nInserting Before Head Node \n");
				student *newstudent = create_new_node(head);
				head = newstudent;
			}

			else if(position == 0 && sptr != head)
			{
				printf("\nInserting Before a Middle Node\n");

				student *bsptr = head;
				if(bsptr->next == sptr)
				{
					student *newstudent = create_new_node(bsptr->next);
					bsptr->next =  newstudent;
				}

				else
				{
					while(bsptr->next != sptr)
					{
						bsptr = bsptr->next;
					}

					bsptr->next = create_new_node(bsptr->next);
				}


			}
			
		}
		else
			{
				printf("\nSorry the Roll Number you wanted to use Does not exit\n");
			}//end of sptr != NULL's if
 	
		return head;

	}

}

student * Delete(student *head , int srollno)
{
	sptr = search(head, srollno);
	if(sptr == NULL)
	{
		printf("Roll Number you are trying to delete doesnot exist\n");
		return head;
	}

	else 
	{	
		if(sptr == head)
		{
			printf("Deleting the Head Node\n");
			head = sptr->next;
			free(sptr);
			scount--;
		}

		else if(sptr->next == NULL)
		{
			printf("Deleting the End Node\n");
			student  *bsptr = head;
			while(bsptr->next != sptr)
			{
				bsptr = bsptr->next;
			}

			bsptr->next = NULL;
			free(sptr); scount--;
		}

		else
		{
			printf("Deleting Middle Node\n");
			student *bsptr = head;
			while(bsptr->next != sptr)
			{
				bsptr  = bsptr->next;
			}
			bsptr->next = sptr->next;
			free(sptr); scount--;
		}
		return head;
	}
}

int main()
{	
	demo_options();
	int choice = 0;
	while(1)
	{
		printf("\nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: demo_options();
					break;

			case 2:printf("Enter the Roll number of the student to be searched\n");
					scanf("%d",&srollno);
					sptr = search(head , srollno);
					if(sptr != NULL)
                	{
                    	printf("\nStudent with RollNo %d found with  Name  %s at the Address : %d",sptr->rollno, sptr->name,sptr);
                	}
                	else
                	{
                    printf("\nStudent with RollNo %d not found.",srollno);
               		}	
					break;

			case 3 : head = Insert(head);
					break;


			case 4:	printf("\nEnter the Students Roll number you want to delete from the list\n"); scanf("%d",&srollno);
					head = Delete(head , srollno);
					break;


			case 5: print_Details(head);
					break;


			case 6:	exit(0);
					break;

			default:	printf("Invalid choice\n");
						break;
		}

	}
	return 0;	
}
