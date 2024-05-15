//
// Created by Hanga on 03/05/2024.
//

#ifndef LAB_09_BST_PERSON_H
#define LAB_09_BST_PERSON_H

#endif //LAB_09_BST_PERSON_H

typedef struct Person {
    char name[50];
    int birth_year;
    int birth_month;
    int birth_day;
    char gender;
} Person;

typedef struct Node{
    Person data;
    struct Node *left, *right;
}Node;
Node *insertDatum(Node *node, Person data);
void inorderTraversal(Node *root);
void readPersonsFromFile(char *filename, Person persons[], int *count);
Node * createNewNode(Person newData);
Node *insert(Node *node, Person data);
Node *minValueNode(Node *node);
Node *maxValueNode(Node *node);
Node *deleteNode(Node *root, char *name);