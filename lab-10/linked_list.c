// Created by Hanga on 15/05/2024.

#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

Node* newNode(int new_data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Error allocating memory\n");
        exit(-8);
    }
    newNode->data = new_data;
    newNode->next = NULL;
    return newNode;
}

bool isEmpty(Node *head) {
    return head == NULL;
}

void insertAtBeginning(Node** head_ref, int new_data) {
    Node* node = newNode(new_data);
    node->next = *head_ref;
    *head_ref = node;
}

void insertAfter(Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("The given previous node cannot be NULL\n");
        return;
    }
    Node* node = newNode(new_data);
    node->next = prev_node->next;
    prev_node->next = node;
}

void insertAtEnd(Node** head_ref, int new_data) {
    Node* node = newNode(new_data);
    if (*head_ref == NULL) {
        *head_ref = node;
        return;
    }
    Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = node;
}

void deleteFromBeginning(Node** head_ref) {
    if (*head_ref == NULL) return;
    Node* temp = *head_ref;
    *head_ref = (*head_ref)->next;
    free(temp);
}

void deleteFromEnd(Node** head_ref) {
    if (*head_ref == NULL) return;
    if ((*head_ref)->next == NULL) {
        free(*head_ref);
        *head_ref = NULL;
        return;
    }
    Node* second_last = *head_ref;
    while (second_last->next->next != NULL) {
        second_last = second_last->next;
    }
    free(second_last->next);
    second_last->next = NULL;
}

void deleteNode(Node** head_ref, int key) {
    Node* temp = *head_ref, *prev = NULL;
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

bool searchNode(Node* head, int key) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == key) return true;
        current = current->next;
    }
    return false;
}

void sortLinkedList(Node** head_ref) {
    int swapped;
    Node *ptr1;
    Node *lptr = NULL;
    if (*head_ref == NULL)
        return;
    do {
        swapped = 0;
        ptr1 = *head_ref;
        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}
int buildNumberFromList(Node* head) {
    int number = 0;
    while (head != NULL) {
        number = number * 10 + head->data;
        head = head->next;
    }
    return number;
}