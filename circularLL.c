#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student //strucutre with two data
{
	int rollno; char name[20];
	struct student *next;

}student;
student *head = NULL, *sptr = NULL, *tail = NULL;
int srollno = 0, scount = 0;
char sname[20];

void demo_options()
{
	printf("*******Single Circular Linked List********\n");
	printf("1.Demo Options\n2.Search\n3.Insert\n4.Delete\n5.Print Details\n6.Quit");
}

void print_details(student *sptr)
{

	if(head == NULL ) // base condition
	{
		printf("Empty List\n");
		return;
	}
	else
	{
		printf("\nNumber of students in the list is : %d",scount);
		printf("\nHead Address : %d\n\n",head);
		do
		{
			printf("\nthis node Address : %d \tRoll number : %d\t || \tName : %s",sptr,sptr->rollno,sptr->name);
			sptr = sptr->next;
			printf("\t\tNext node Address : %d",sptr);
		}while(sptr!= head);
		printf("\n");
		printf("\n");
	}
}

student *create_new_node(student *next) // called each time when needed a new memory allocation
{
	student *newstudent = (student *)malloc(sizeof(student));
	strcpy(newstudent->name,sname);
	newstudent->rollno = srollno;
	newstudent->next = next;
	scount++;
	return newstudent;	
}

student *Search(student *sptr , int srollno)
{
	if(head == NULL)
	{
		printf("List is Empty\n");
		return NULL;
	}

	else
	{
		do
		{ 	if(sptr->rollno == srollno)
				return sptr;
			else sptr = sptr->next;
		}while(sptr !=  head);
		return NULL;
	}
}

student *Insert()
{
	printf("Enter the Roll Number : "); scanf("%d",&srollno);
	printf("Enter the Name : "); scanf("%s",sname);
	int position;
	int rollposition;
	
	if(head == NULL) // checking head condition
	{
		printf("\nYou are the first student to enroll\n");
		student *newstudent = create_new_node(head);
		head = newstudent;
		tail = head;
		tail->next = head;
		head->next = tail;
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

		//Searching the student with rollposition 
		sptr = Search(head , rollposition);

		if(sptr != NULL)
		{
			if(position == 1 && sptr == tail) //end node check
			{
				printf("\nInserting After the End Node\n");
				student *newstudent = create_new_node(head);
				tail = newstudent;
				sptr->next = tail;
				tail->next = head;

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
				head->next = sptr;
				tail->next = head;
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

student *Delete(student *head, int srollno)
{
	sptr = Search(head, srollno);
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
			tail->next = head;
			free(sptr);
			scount--;
		}

		else if(sptr == tail)
		{
			printf("Deleting the End Node\n");
			student  *bsptr = head;
			while(bsptr->next != sptr)
			{
				bsptr = bsptr->next;
			}

			bsptr->next = head;
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
	int choice = 0;
	demo_options();
	while(1)
	{
		printf("\nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: demo_options();
					break;

			case 2:printf("Enter the Roll number of the student to be Searched\n");
					scanf("%d",&srollno);
					sptr = Search(head , srollno);
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


			case 5: print_details(head);
					break;


			case 6:	exit(0);
					break;

			default:	printf("Invalid choice\n");
						break;
		}
	}

  return 0;
}
