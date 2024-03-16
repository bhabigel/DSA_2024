#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array.h"

#define MAX_CAPACITY 10

int main() {
    IntArray array;
    createIntArray(MAX_CAPACITY, &array);

    printf("1.I declared and allocated memory for the array.\n");

    printf("\n2. Print array elements:\n");
    printArray(array);

    printf("\n3. Fill the array with consecutive numbers from 1 up to half of the maximum capacity:\n");
    for (int i = 1; i <= MAX_CAPACITY / 2 && i <= array.capacity; i++) {
        insertLast(&array, i);
    }
    printf("Array after filling with consecutive numbers: ");
    printArray(array);

    printf("\n5. Fill the array with additional consecutive numbers until it's full:\n");
    int nextValue = array.size + 1;
    while (!isFull(array)) {
        if (nextValue % 2 == 0) {
            insertFirst(&array, nextValue);
        } else {
            insertLast(&array, nextValue);
        }
        nextValue++;
    }
    printf("Array after further filling: ");
    printArray(array);

    printf("\n7. Search for a value in the array:\n");
    int searchValue;
    printf("Enter a value to search in the array: ");
    scanf("%d", &searchValue);
    getchar();
    int position = search(array, searchValue);
    if (position != -1) {
        printf("The value %d is found at position %d.\n", searchValue, position);
    } else {
        printf("The value %d is not found in the array.\n", searchValue);
    }

    printf("\n8. Update a value at a specific position in the array:\n");
    if (position != -1) {
        int newValue;
        printf("Enter the new value: ");
        scanf("%d", &newValue);
        if (update(&array, position, newValue)) {
            printf("Array after update: ");
            printArray(array);
        } else {
            printf("Failed to update. Invalid position.\n");
        }
    }

    printf("\n9. Delete random elements from the array:\n");
    srand(time(NULL));
    while (!isEmpty(array)) {
        int randomPosition = rand() % array.size;
        deleteItemAt(&array, randomPosition);
        if (isEmpty(array)) {
            printf("Array is empty.\n");
        } else {
            printf("Element deleted at position %d.\n", randomPosition);
        }
    }

    printf("\n10. Print final array:\n");
    printArray(array);

    deallocateIntArray(&array);
    printf("11.I deallocate the memory:\n");
    return 0;
}
