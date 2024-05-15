//
// Created by Hanga on 22/04/2024.
//

#ifndef LAB_08_LINKED_LIST_H
#define LAB_08_LINKED_LIST_H
#define ALLOCATION_ERROR "Error"

typedef struct Node{
    int data;
    struct Node* next;
}Node;
Node* newNode(int new_data);
bool isEmpty(Node *head);
void printList(Node* node);
Node* covertIntToList();
void deleteFromBeginning(Node** head_ref);
Node *addLists(Node *first, Node *second);
void insertAtEnd(Node** head_ref, int new_data);
void insertOrdered(int num, Node **head);
#endif //LAB_08_LINKED_LIST_H
