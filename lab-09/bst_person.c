#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include "bst_person.h"

int compareDates(int year1, int month1, int day1, int year2, int month2, int day2) {
    if (year1 != year2)
        return year1 - year2;
    if (month1 != month2)
        return month1 - month2;
    return day1 - day2;
}

Node *insertDatum(Node *node, Person data) {
    if(node == NULL)
        return createNewNode(data);

    int cmp = compareDates(data.birth_year, data.birth_month, data.birth_day,
                           node->data.birth_year, node->data.birth_month, node->data.birth_day);

    if (cmp > 0)
        node->right = insertDatum(node->right, data);
    else if (cmp < 0)
        node->left = insertDatum(node->left, data);
    else {
        if (data.gender == 'M')
            node->right = insertDatum(node->right, data);
        else
            node->left = insertDatum(node->left, data);
    }

    return node;
}

void inorderTraversal(Node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("Nev: %s, Szuletesi datum: %d-%02d-%02d, Nem: %c\n", root->data.name, root->data.birth_year, root->data.birth_month, root->data.birth_day, root->data.gender);
        inorderTraversal(root->right);
    }
}

void readPersonsFromFile(char *filename, Person persons[], int *count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Hiba a fajl megnyitasakor.\n");
        exit(1);
    }

    *count = 0;
    while (fscanf(file, "%s %d %d %d %c", persons[*count].name, &persons[*count].birth_year, &persons[*count].birth_month, &persons[*count].birth_day, &persons[*count].gender) == 5) {
        (*count)++;
    }

    fclose(file);
}

Node *createNewNode(Person newData)
{
    Node *root=(Node *)malloc(sizeof(Node));
    if(root == NULL)
    {
        printf("memory allocation failed");
        exit(1);
    }

    root->data = newData;
    root->right = root->left = NULL;
    return root;
}

Node *insert(Node *node, Person data) {
    if(node == NULL)
        return createNewNode(data);

    int cmp = strcmp(data.name, node->data.name);
    if (cmp < 0)
        node->left = insert(node->left, data);
    else if (cmp > 0)
        node->right = insert(node->right, data);

    return node;
}

Node *minValueNode(Node *node) {
    Node *current = node;
    while(current != NULL && current->left != NULL)
        current = current->left;
    return current;
}

Node *maxValueNode(Node *node) {
    Node *current = node;
    while(current != NULL && current->right != NULL)
        current = current->right;
    return current;
}

Node *deleteNode(Node *root, char *name) {
    if (root == NULL) return root;

    if (strcmp(name, root->data.name) < 0)
        root->left = deleteNode(root->left, name);
    else if (strcmp(name, root->data.name) > 0)
        root->right = deleteNode(root->right, name);
    else {
        if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return (temp);
        }
        Node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data.name);
    }
    return root;
}
