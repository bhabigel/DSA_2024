//
// Created by Hanga on 22/04/2024.
//

#include <malloc.h>
#include <stdio.h>
#include "linked_list.h"

Node *newNode(int new_data) {
    Node *node;
    node = (Node *) malloc(sizeof(Node));
    if (!node) {
        printf("ALLOCATION_ERROR");
        exit(-1);
    }
    node->data=new_data;
    node->next=NULL;
    return node;
}

void insertAtEnd(Node** head_ref, int new_data)
{
    if (isEmpty(*head_ref))
    {
        Node *node = newNode(new_data);
        *head_ref = node;
    }
    else
    {
        Node *current = *head_ref;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode(new_data);
    }
}


bool isEmpty(Node *head)
{
    return head==NULL;
}

void printList(Node* node)
{
    Node *current = node;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

Node* covertIntToList()
{
    printf("Kerlek irj be egy szamot:");
    int szam;
    scanf("%d", &szam);
    Node *head=NULL;
    while(szam>0)
    {
        insertAtEnd(&head, szam%10);
        szam /=10;
    }
return head;
}
void deleteFromBeginning(Node** head_ref)
{
    if(isEmpty(*head_ref))
    {
        printf("Lista ures\n");
        return;
    }
    Node *new=(*head_ref)->next;
    free(*head_ref);
    *head_ref=NULL;
    *head_ref=new;

}

Node *addLists(Node *first, Node *second)
{
    Node *sum=NULL;
    int kov=0;
    while(first !=NULL && second != NULL)
    {
        int one=first->data;
        int two=second->data;
        insertAtEnd(&sum,(one+two+kov)%10);
        kov = (one+two+kov)/10;
        deleteFromBeginning(&first);
        deleteFromBeginning(&second);

    }
            while (first!=NULL)
        {
            int one=first->data;
            insertAtEnd(&sum,(one+kov)%10);
            kov=(one+kov)/10;
            deleteFromBeginning(&first);
        }
        while (second!=NULL)
        {
            int one=second->data;
            insertAtEnd(&sum,(one+kov)%10);
            kov=(one+kov)/10;
            deleteFromBeginning(&second);
        }

        if(kov!=0)
        {
            insertAtEnd(&sum,kov);
        }
    return sum;

}


