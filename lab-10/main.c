#include <stdio.h>
#include "linked_list.h"

int main() {
    Node* unsortedList = NULL;
    Node* sortedList = NULL;
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);
    while (number > 0) {
        insertAtEnd(&unsortedList, number % 10);
        number /= 10;
    }
    printf("Original List: ");
    printList(unsortedList);
    sortLinkedList(&unsortedList);
    printf("Sorted List: ");
    printList(unsortedList);
    Node* temp = unsortedList;
    while (temp != NULL) {
        orderedList(&sortedList, temp->data);
        temp = temp->next;
    }

    int smallestNumber = buildNumberFromList(sortedList);
    int largestNumber = buildNumberFromList(unsortedList);

    printf("Smallest Number: %d\n", smallestNumber);
    printf("Largest Number: %d\n", largestNumber);

    return 0;
}
