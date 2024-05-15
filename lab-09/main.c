#include <stdio.h>
#include "bst_person.h"

int main() {
    Node *root = NULL;

    Person persons[100];
    int count;
    readPersonsFromFile("szemelyek.txt", persons, &count);

    for (int i = 0; i < count; i++) {
        root = insert(root, persons[i]);
    }

    printf("\nA szemelyek nev szerint rendezve:\n");
    inorderTraversal(root);

    Node *minNode = minValueNode(root);
    Node *maxNode = maxValueNode(root);
    printf("\nMinimalis szemely: %s\n", minNode->data.name);
    printf("Maximalis szemely: %s\n", maxNode->data.name);

    root = deleteNode(root, "David");
    printf("\nBob szemely torolve.\n");

    Node *root2 = NULL;
    Person persons2[100];
    int count2;
    readPersonsFromFile("szemelyek2.txt", persons2, &count2);

    for (int i = 0; i < count2; i++) {
        root2 = insertDatum(root2, persons2[i]);
    }

    printf("\nA szemelyek szuletesi datum szerint rendezve:\n");
    inorderTraversal(root2);
    return 0;
}
