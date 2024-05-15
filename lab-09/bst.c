#include "bst.h"


Node *insert2(Node *node, int key) {
    if(node==NULL)
        return createNewNode2(key);

    if(key<node->info2)
        node->left2=insert2(node->left2, key);
    else
        node->right2=insert2(node->right2,key);

    return node;
}

Node *createNewNode2(int newData) {
    Node *root = (Node*)malloc(sizeof(Node));
    if (root == NULL) {
        printf("Nem sikerült memóriát foglalni.\n");
        exit(1);
    }
    root->info2 = newData;
    root->right2 = root->left2 = NULL;
    return root;
}

Node *minValueNode2(Node *node) {
    Node *current = node;
    while(current != NULL && current->left2 != NULL)
        current = current->left2;
    return current;
}

Node *maxValueNode2(Node *node) {
    Node *current = node;
    while(current != NULL && current->right2 != NULL)
        current = current->right2;
    return current;
}

Node *deleteNode2(Node *root, int key) {
    if (root == NULL) return root;

    if (key < root->info2)
        root->left2 = deleteNode2(root->left2, key);
    else if (key > root->info2)
        root->right2 = deleteNode2(root->right2, key);
    else {
        if (root->left2 == NULL) {
            Node *temp = root->right2;
            free(root);
            return temp;
        } else if (root->right2 == NULL) {
            Node *temp = root->left2;
            free(root);
            return (temp);
        }
        Node *temp = minValueNode2(root->right2);
        root->info2 = temp->info2;
        root->right2 = deleteNode2(root->right2, temp->info2);
    }
    return root;
}
