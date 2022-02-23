
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
	int rollno; char name[20];
	struct student *next, *prev;

}student;

student *head = NULL, *tail = NULL, *sptr = NULL;
int srollno = 0, scount = 0;
char sname[20];

void Demo_options()
{
	printf("*******Double Linked List********\n");
	printf("1.Demo Options\n2.Search\n3.Insert\n4.Delete\n5.Print Details\n6.Quit\n");
}

student *Search(student *sptr, int srollno)
{
	if(head == NULL)
	{
		printf("\nList is Empty\n");
		return NULL;
	}
	else
	{
		do
		{
			if(sptr->rollno == srollno)
				return sptr;
			else sptr = sptr->next;
		}while(sptr != head);
	  return NULL;
	}

}

student *creat_new_node(student *next, student *prev)
{
	student *newstudent = (student *)malloc(sizeof(student));
	strcpy(newstudent->name,sname);
	newstudent->rollno = srollno;
	newstudent->next = next;
	newstudent->prev = prev;
	scount++;
	return newstudent;
}

void print_details(student *sptr)
{
	if(head == NULL)
	{
		printf("\nList is Empty\n");
	}
	else
	{
		printf("\n\t\tNumber of student in the list : %d\n",scount);
		printf("Head node Address : %d\n",head);
		do
		{
			printf("\nThis node Address : %d \tRoll number : %d\t || \tName : %s",sptr,sptr->rollno,sptr->name);
			printf("\tPrevious Node Address : %d",sptr->prev);
			sptr = sptr->next;
			printf("\t\tNext node Address : %d",sptr);
			
		}while(sptr != head);
		printf("\n");
		printf("\n");
	}
}

student *Insert(student *head)
{
	int position, rollposition;
	printf("\nEnter the Roll number : "); scanf("%d",&srollno);
	printf("\nEnter the Name : "); scanf("%s",sname);
	if(head  == NULL)
	{
		printf("\nYou are the first student to enroll");
		student *newstudent = creat_new_node(head,tail);
		head = newstudent;
		tail = head;
		head->next = tail; head->prev = tail;
		tail->next = head; tail->prev = head;
		return head;
	}

	else  if(head != NULL)
	{
		printf("\nDo you want to insert After or Before :\nEnter 1 to insert After and 0 to insert Before\n\t>> : ");
		scanf("%d",&position);
		if(position == 1)
		{
			printf("\nEnter the Roll number of the student you wish to insert After : "); 
			scanf("%d",&rollposition);
		}

		else if(position == 0)
		{
			printf("\nEnter the Roll number of the student you wish to insert Before : "); 
			scanf("%d",&rollposition);
		}
		else
		{
			printf("\nInvalid choice\n");
		}

		sptr = Search(head, rollposition);
		if(sptr != NULL)
		{
			if(position == 1 && sptr == tail)
			{
				printf("\nInserting after the end Node\n");
				student *newstudent = creat_new_node(sptr->next,sptr);
				tail = newstudent;
				sptr->next = tail;
				//tail->prev = sptr; tail->next = head;
				head->prev = tail;
			}

			else if(position == 1 && sptr == head)
			{
				printf("\nInserting After Head Node\n");
				student *newstudent = creat_new_node(sptr->next, head);
				head->next = newstudent;
				newstudent->next->prev = newstudent;

			}

			else if(position == 1 && sptr != tail)
			{
				printf("\nInserting After a Middle NOde\n");
				student *newstudent = creat_new_node(sptr->next,sptr);
				newstudent->next->prev = newstudent;
				sptr->next = newstudent;
			}

			else if(position == 0 && sptr == head)
			{
				printf("\nInserting Before Head Node\n");
				student *newstudent = creat_new_node(sptr, tail);
				head->prev = newstudent;
				head = newstudent;
				tail->next = head;
			}
			else if(position == 0 && sptr->next == NULL)
			{
				printf("\nInserting Before the tail Node");
				student *newstudent = creat_new_node(sptr,sptr->prev);
				sptr->prev = newstudent;
				sptr->prev->next = newstudent;
			}

			else if(position == 0 && sptr != head || sptr != tail)
			{
				printf("\nInserting Before a Middle Node\n");
				student *newstudent =  creat_new_node(sptr,sptr->prev);
				sptr->prev->next = newstudent;
                sptr->prev = newstudent;
			}

		}
		else printf("\nThe Roll number you are trying to access does not exits in the List\n"); 

		return head;
	}

}

student *Delete(student *head, int srollno)
{
	sptr = Search(head , srollno);
	if(sptr == NULL)
	{
		printf("\nThe Roll Number you were Trying to delete does not exits in the List\n");
		return head;
	}

	else
	{
		if(sptr == head)
		{	
			printf("\nDeleting the head node\n");
			head = sptr->next;
			tail->next =head;
			head->prev = tail;
			free(sptr); 
			scount--;
			return head;
		}
		else if(sptr == tail)
		{
			printf("\nDeleting End Node");
			tail = sptr->prev;
			tail->next = head;
			head->prev = tail;
			free(sptr); scount--;
		}
		else
		{
			printf("\nDeleting a Middle Node\n");
			sptr->prev->next = sptr->next;
			sptr->next->prev = sptr->prev;
			free(sptr);
			scount--;
		}

		return  head;
	}

}

int main()
{ 
	int choice;
	Demo_options();
	while(1)
	{
		printf("\nEnter your Choice : "); scanf("%d",&choice);
		switch(choice)
		{
			case 1 : Demo_options();
					 break;

			case 2: printf("\nEnter the Roll number of the student you wish to search : ");
					scanf("%d",&srollno);
					sptr = Search(head, srollno);
					if(sptr != NULL)
					{
						printf("\nThe Roll number %d is found with Name %s at the Address :%d\n",sptr->rollno,sptr->name,sptr);
					}
					else
					{
						printf("\nRoll Number %d is not found in the List\n",srollno);
					}
					break;

			case 3: head = Insert(head);
					break;
					
			case 4: printf("\nEnter the Roll Number of the student you wish to delete from the list : ");
					scanf("%d",&srollno);
					head = Delete(head, srollno);
					break;

			case 5:	print_details(head);
					break;

			case 6: exit(0);
					break;

			default: printf("\nInvalid Choice\n");
					 break;
		}

	}
return 0;
}
=======
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
int rollno; char name[20];
struct student *next, *prev; // next and prev structure pointers gives the address of next and prvious nodes respectively

}student;

student *head = NULL, *tail = NULL, *sptr = NULL;
int srollno = 0, scount = 0; // scount to count number of nodes in ll
char sname[20];

void Demo_options()
{
	printf("*******Double Linked List********\n");
	printf("1.Demo Options\n2.Search\n3.Insert\n4.Delete\n5.Print Details\n6.Quit\n");
}

student *Search(student *sptr, int srollno)
{
	if(head == NULL)
	{
		printf("\nList is Empty\n");
		return NULL;
	}
	else // search algorithm you can prefer other types of search too
	{
		do
		{
			if(sptr->rollno == srollno)
				return sptr;
			else sptr = sptr->next;
		}while(sptr != head);
	  return NULL;
	}

}

student *creat_new_node(student *next, student *prev)
{
	student *newstudent = (student *)malloc(sizeof(student));
	strcpy(newstudent->name,sname);
	newstudent->rollno = srollno;
	newstudent->next = next;
	newstudent->prev = prev;
	scount++;
	return newstudent;
}

void print_details(student *sptr)
{
	if(head == NULL)
	{
		printf("\nList is Empty\n");
	}
	else
	{
		printf("\n\t\tNumber of student in the list : %d\n",scount);
		printf("Head node Address : %d\n",head);
		do
		{
			printf("\nThis node Address : %d \tRoll number : %d\t || \tName : %s",sptr,sptr->rollno,sptr->name);
			printf("\tPrevious Node Address : %d",sptr->prev);
			sptr = sptr->next;
			printf("\t\tNext node Address : %d",sptr);
			
		}while(sptr != head);
		printf("\n");
		printf("\n");
	}
}

student *Insert(student *head)
{
	int position, rollposition;
	printf("\nEnter the Roll number : "); scanf("%d",&srollno);
	printf("\nEnter the Name : "); scanf("%s",sname);
	if(head  == NULL)
	{
		printf("\nYou are the first student to enroll");
		student *newstudent = creat_new_node(head,tail);
		head = newstudent;
		tail = head;
		head->next = tail; head->prev = tail;
		tail->next = head; tail->prev = head;
		return head;
	}

	else  if(head != NULL) // base condition
	{
		printf("\nDo you want to insert After or Before :\nEnter 1 to insert After and 0 to insert Before\n\t>> : ");
		scanf("%d",&position);
		if(position == 1)
		{
			printf("\nEnter the Roll number of the student you wish to insert After : "); 
			scanf("%d",&rollposition);
		}

		else if(position == 0) // make new node as first
		{
			printf("\nEnter the Roll number of the student you wish to insert Before : "); 
			scanf("%d",&rollposition);
		}
		else
		{
			printf("\nInvalid choice\n");
		}

		sptr = Search(head, rollposition);
		if(sptr != NULL)
		{
			if(position == 1 && sptr == tail)
			{
				printf("\nInserting after the end Node\n");
				student *newstudent = creat_new_node(sptr->next,sptr);
				tail = newstudent;
				sptr->next = tail;
				//tail->prev = sptr; tail->next = head;
				head->prev = tail;
			}

			else if(position == 1 && sptr == head)
			{
				printf("\nInserting After Head Node\n");
				student *newstudent = creat_new_node(sptr->next, head);
				head->next = newstudent;
				newstudent->next->prev = newstudent;

			}

			else if(position == 1 && sptr != tail)
			{
				printf("\nInserting After a Middle NOde\n");
				student *newstudent = creat_new_node(sptr->next,sptr);
				newstudent->next->prev = newstudent;
				sptr->next = newstudent;
			}

			else if(position == 0 && sptr == head)
			{
				printf("\nInserting Before Head Node\n");
				student *newstudent = creat_new_node(sptr, tail);
				head->prev = newstudent;
				head = newstudent;
				tail->next = head;
			}
			else if(position == 0 && sptr->next == NULL)
			{
				printf("\nInserting Before the tail Node");
				student *newstudent = creat_new_node(sptr,sptr->prev);
				sptr->prev = newstudent;
				sptr->prev->next = newstudent;
			}

			else if(position == 0 && sptr != head || sptr != tail)
			{
				printf("\nInserting Before a Middle Node\n");
				student *newstudent =  creat_new_node(sptr,sptr->prev);
				sptr->prev->next = newstudent;
                sptr->prev = newstudent;
			}

		}
		else printf("\nThe Roll number you are trying to access does not exits in the List\n"); 

		return head;
	}

}

student *Delete(student *head, int srollno)
{
	sptr = Search(head , srollno);
	if(sptr == NULL)
	{
		printf("\nThe Roll Number you were Trying to delete does not exits in the List\n");
		return head;
	}

	else
	{
		if(sptr == head)
		{	
			printf("\nDeleting the head node\n");
			head = sptr->next;
			tail->next =head;
			head->prev = tail;
			free(sptr); 
			scount--;
			return head;
		}
		else if(sptr == tail)
		{
			printf("\nDeleting End Node");
			tail = sptr->prev;
			tail->next = head;
			head->prev = tail;
			free(sptr); scount--;
		}
		else
		{
			printf("\nDeleting a Middle Node\n");
			sptr->prev->next = sptr->next;
			sptr->next->prev = sptr->prev;
			free(sptr);
			scount--;
		}

		return  head;
	}

}

int main()
{ 
	int choice;
	Demo_options();
	while(1)
	{
		printf("\nEnter your Choice : "); scanf("%d",&choice);
		switch(choice)
		{
			case 1 : Demo_options();
					 break;

			case 2: printf("\nEnter the Roll number of the student you wish to search : ");
					scanf("%d",&srollno);
					sptr = Search(head, srollno);
					if(sptr != NULL)
					{
						printf("\nThe Roll number %d is found with Name %s at the Address :%d\n",sptr->rollno,sptr->name,sptr);
					}
					else
					{
						printf("\nRoll Number %d is not found in the List\n",srollno);
					}
					break;

			case 3: head = Insert(head);
					break;
					
			case 4: printf("\nEnter the Roll Number of the student you wish to delete from the list : ");
					scanf("%d",&srollno);
					head = Delete(head, srollno);
					break;

			case 5:	print_details(head);
					break;

			case 6: exit(0);
					break;

			default: printf("\nInvalid Choice\n");
					 break;
		}

	}
return 0;
}

