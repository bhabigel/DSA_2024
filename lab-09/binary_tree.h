//
// Created by Hanga on 29/04/2024.
//

#ifndef LAB_09_BINARY_TREE_H
#define LAB_09_BINARY_TREE_H

#endif //LAB_09_BINARY_TREE_H

typedef struct Node
{
    int info1;
    struct Node*left1,*right1;
}Node;
Node *createNewNode1(int newData);
Node *insertLeft1(Node *root, int newData);
Node *insertRight1(Node *root, int newData);
void preorderTraversal1(Node *root);






