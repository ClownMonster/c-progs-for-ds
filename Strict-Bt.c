/*
 @Author: Dr.Mydhili K Nair, Professor, ISE Dept, RIT, Bangalore
 Purpose: This program does the following:
 a) Creates Binary Tree through 'Double Recursion' call to 'createTree' function
 b) Checks if the created Binary Tree is a Strictly Binary Tree or not
 c) Displays the tree through 'Double Recursion' call to 'displayTree' function
 
 Test Cases: This program checks the following unit test cases:
 NOTE: First three test cases are ONLY limited to root node
 1) Display error message of the root node is NULL
 2) Determines it is strictly binary tree by checking if both the left & right pointers of the root node is NULL
 3) Determines it is NOT strictly binary tree by checking if root->left is NOT NULL while root->right is or vice-versa
 4) Checks the condiction for a tree to be not strictly binary tree.
    Logic:
 --- First Pass the pointer root->left which is the left sub-tree
 --- Check each internal node / leaf node for Test Case #2 & Test Case #3
 --- If the left sub-tree returns '0' it means Test Case #2 or #3 failed=, meaning the left sub-tree is not strict binary tree.
 --- As long as the left sub-tree keeps returning '1' check the right sub-tree of that node
 --- If the right sub-tree also returns '1' recursively, it strict binary tree test is passed
 */
#include <stdio.h>
#include<stdlib.h>
typedef struct myBintree
{
    int marks;
    struct myBintree *left;
    struct myBintree *right;
    
}myBintree;

int strict = 0;
myBintree *root = NULL;

myBintree * createBinTree()
{
    int m; myBintree *ptr;
    
    printf("\n Press -1 if you dont want to enter marks ");
    scanf("%d", &m); //Remove '&' To DEMO Segmentation Fault
    
    if(m == -1) return NULL;
    else
    {
        ptr = (myBintree *)malloc(sizeof(myBintree));
        ptr->marks = m; ptr->left = NULL; ptr->right =NULL;
        printf("\n Enter Marks for LEFT node of %d ", ptr->marks);
        
        ptr->left = createBinTree();
        
        printf("\n Enter Marks for RIGHT node of %d ", ptr->marks);
        
        ptr->right = createBinTree();
        return ptr;
    }
    
}//End of createBinTree

int IsStrictlyBinTree(myBintree* root) {
    
    if(root->left == NULL && root->right == NULL)
    {
        printf("\n Test Case #2 \n");
        return 1;
    }
    
    else if ((root->left == NULL && root->right != NULL)  ||
             (root->right == NULL && root->left != NULL))
    {
        printf("\n Test Case #3 \n");
        return 0;
    }
    else
        
        if(IsStrictlyBinTree(root->left))
        {
            strict = IsStrictlyBinTree(root->right);
            return strict;
        }
        else
            return 0;
    /*
     The above code can be written shortly by using the ternary operator in the way given below:
     
     return ((IsStrictlyBinTree(root->left))?IsStrictlyBinTree(root->right):0);
     */
    
}//End of IsStrictlyBinTree

void displayBinTree(myBintree * root,int i)
{
    int j;
    
    
    if(root !=NULL)
    {
        displayBinTree(root->left,i+1);
        for(j=1;j<=i;j++) printf("\t"); //DEMO : Only prints tab
        //Donot enclose the two printf in brackets as the actual print happens
        //outside the for loop when loop condition fails
        //printf("%d(%d:%d)\n",root->marks,i,j);
        
        printf("%d \n",root->marks);
        displayBinTree(root->right,i+1);
    }
    
}//End of displayBinTree

int main()
{
    root = createBinTree();
    printf("\n Displaying....\n");
    
    if(root == NULL)
    {
        printf("\nTest Case #1 \n");
        printf("\n Root Node is NULL - Tree does not have even one node\n");
    }
    else
    {
    strict = IsStrictlyBinTree(root);
    if(strict == 1) printf("\n Created Tree is Strict Binary tree\n");
    else printf("\n Created Tree is NOT Strict Binary tree\n");
    displayBinTree(root, 1);
    }
    
}





