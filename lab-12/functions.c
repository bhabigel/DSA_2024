//
// Created by Hanga on 15/05/2024.
//

#include <malloc.h>
#include <stdio.h>
#include "functions.h"

void createHashArray(HashTable *pHashTable) {
    pHashTable->items = (HashItem *)malloc(pHashTable->size * sizeof(HashItem));
    pHashTable->size=0;
    for (int i = 0; i < CAPACITY; i++) {
        pHashTable->items[i] = dummyData;
    }
}
int hashCode(int key) {
    return key%CAPACITY;
}
void insert(HashTable *hashTable, int key, int data) {
    if (hashTable->size == CAPACITY - 1) {
        return;
    }
    int code = hashCode(key);
    int i = 0;
    while (hashTable->items[code + i].key != dummyData.key) {
        i++;
    }
    HashItem item = {key, data};
    hashTable->items[(code + i) % CAPACITY] = item;
    hashTable->size++;
}

void display(HashTable hashTable)
{
    for(int i=0;i<hashTable.size;i++)
    {
        if(hashTable.items[i].key==dummyData.key)
        {
            printf("index: %i :-------EMPTY--------\n",i);
        }
        else
            printf("index: %i {%i, %i} OG KEY: %i\n", i,hashTable.items[i].key,
                   hashTable.items[i].data, hashCode(hashTable.items[i].key));
    }

}

int search(HashTable hashTable, int key) {
    int index = hashCode(key);
    int i = 0;
    while (hashTable.items[(index+i) % CAPACITY].key != key && hashTable.items[(index + i) % CAPACITY].key != dummyData.key) {
        i++;
    }
    if (hashTable.items[(index + i) % CAPACITY].key == key) {
        return (index + i) % CAPACITY;
    } else {
        return -1;
    }
}

void delete(HashTable *hashTable, int key) {
    int index = hashCode(key);
    int i = 0;
    while (hashTable->items[(index + i) % CAPACITY].key != key &&
           hashTable->items[(index + i) % CAPACITY].key != dummyData.key) {
        i++;
    }
    if (hashTable->items[(index + i) % CAPACITY].key == key) {
        hashTable->items[index].key = dummyData.key;
        hashTable->items[index].data = dummyData.data;
        hashTable->size++;
    }
}