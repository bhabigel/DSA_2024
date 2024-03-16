//
// Created by Hanga on 16/03/2024.
//
#include "array.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

void createIntArray(int capacity, IntArray* pArray) {
    pArray->elements = (int *)malloc(capacity * sizeof(int));
    if (pArray->elements == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
     pArray->capacity = capacity;
    pArray->size = 0;
}
void printArray(IntArray array) {
    printf("[");
    for (int i = 0; i < array.size; i++) {
        printf("%d", array.elements[i]);
        if (i < array.size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}
bool isEmpty(IntArray array) {
    return (array.size == 0);
}
bool isFull(IntArray array) {
    return (array.size == array.capacity);
}

int getItemAt(IntArray array, int position) {
    if (position >= 0 && position < array.size) {
        return array.elements[position];
    } else {
        return INT_MIN;
    }
}

void insertFirst(IntArray* pArray, int item) {
    if (pArray->size < pArray->capacity) {
        for (int i = pArray->size; i > 0; i--) {
            pArray->elements[i] = pArray->elements[i - 1];
        }
        pArray->elements[0] = item;
        pArray->size++;
    }
}

void insertLast(IntArray* pArray, int item) {
    if (pArray->size < pArray->capacity) {
        pArray->elements[pArray->size] = item;
        pArray->size++;
    }
}

void insertAt(IntArray* pArray, int position, int item) {
    if (position >= 0 && position <= pArray->size && pArray->size < pArray->capacity) {
        for (int i = pArray->size; i > position; i--) {
            pArray->elements[i] = pArray->elements[i - 1];
        }
        pArray->elements[position] = item;
        pArray->size++;
    }
}

void deleteItemAt(IntArray* pArray, int position) {
    if (position >= 0 && position < pArray->size) {
        for (int i = position; i < pArray->size - 1; i++) {
            pArray->elements[i] = pArray->elements[i + 1];
        }
        pArray->size--;
    }
}

int search(IntArray pArray, int item) {
    for (int i = 0; i < pArray.size; i++) {
        if (pArray.elements[i] == item) {
            return i;
        }
    }
    return -1;
}
bool update(IntArray* pArray, int position, int newItem) {
    if (position >= 0 && position < pArray->size) {
        pArray->elements[position] = newItem;
        return true;
    } else {
        return false;
    }
}

void deallocateIntArray(IntArray *pArray) {
    free(pArray->elements);
    pArray->capacity = 0;
    pArray->size = 0;
}