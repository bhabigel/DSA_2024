//
// Created by Hanga on 29/04/2024.
//

#include "binary_tree.h"
#include <stdio.h>
#include <malloc.h>

Node *createNewNode1(int newData)
{
    Node *root=(Node*)malloc(sizeof(Node));
    root->info1=newData;
    root->right1=root->left1=NULL;
    return root;
}

Node *insertLeft1(Node *root, int newData)
{
    Node *new_node= createNewNode1(newData);
    new_node->left1=root->left1;
    root->left1=new_node;
    return new_node;
}
Node *insertRight1(Node *root, int newData)
{
    Node *new_node= createNewNode1(newData);
    new_node->right1=root->right1;
    root->right1=new_node;
    return new_node;
}

void preorderTraversal1(Node *root)
{
    if(root!=NULL)
    {
        printf("%i",root->info1);
        preorderTraversal1(root->left1);
        preorderTraversal1(root->right1);
    }
}
void inorderTraversal1(Node *root)
{
    if(root!=NULL)
    {
        inorderTraversal1(root->left1);
        printf("%i ",root->info1);
        inorderTraversal1(root->right1);
    }
}

void postorderTraversal1(Node *root) {
    if(root!=NULL) {
        postorderTraversal1(root->left1);
        postorderTraversal1(root->right1);
        printf("%i ", root->info1);
    }
}