//
// Created by Hanga on 03/05/2024.
//

#ifndef LAB_09_BST_H
#define LAB_09_BST_H

#endif //LAB_09_BST_H
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int info2;
    struct Node *left2, *right2;
}Node;
Node *createNewNode2(int newData);

Node * insert2(Node *node, int key);
//inorder traversal
void inorderTraversal2(Node *root);
//find the min number
Node * minValueNode2(Node *node);
//find the max number
Node * maxValueNode2(Node *node);
//deleting a node
Node *deleteNode2(Node *root, int key);