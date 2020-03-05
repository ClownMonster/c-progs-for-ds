#include <stdlib.h>
#include<stdio.h>

typedef struct btree
{
	int data;
	struct btree *left, *right;
}btree;

btree *root = NULL;

btree* create_tree()
{
	int m; btree *ptr;
	printf("Enter -1 if you dont want to enter data : ");
	scanf("%d",&m);
	if(m == -1) return NULL;
	else
	{
		ptr = (btree *)malloc(sizeof(btree));
	    ptr->data = m; ptr->left = NULL; ptr->right=NULL;

		printf("\nEnter the data for left of %d : ",ptr->data );
        ptr->left = create_tree();

        printf("\nEnter the data for right of %d : ",ptr->data);
        ptr->right = create_tree();

        return ptr;
	}

}


void display(btree* root,int i)
{
    int j;
    if(root != NULL)
    {
        display(root->left,i+1);
        for(j=1;j<=i;j++) printf("\t"); 
        printf("%d \n",root->data);
        display(root->right,i+1);
    }
}

int main()
{
	root = create_tree();

	printf("\nDisplaying..\n");
	if(root == NULL)
		printf("Root does not exists\n");
	else if(root->left == NULL && root->right != NULL)
		printf("\nTree is Right skewed\n");
	else if(root->left != NULL && root->right == NULL)
		printf("\nTree is leftt skewed\n");
	else
		display(root, 1);
}
