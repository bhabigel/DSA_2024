//
// Created by Hanga on 15/05/2024.
//

#ifndef LAB_12_FUNCTIONS_H
#define LAB_12_FUNCTIONS_H
#define CAPACITY 31
typedef struct {
    int key;
    int data;
} HashItem;
typedef struct {
    HashItem *items;
    int size;
}HashTable;
int hashCode(int key);
static HashItem dummyData = {-1, 0};
void createHashArray(HashTable *pHashTable);
void insert(HashTable *hashTable, int key, int data);
void delete(HashTable *hashTable, int key);
int search(HashTable hashTable, int key);
void display(HashTable hashTable);
int size(HashTable hashTable);
void destroyHashArray(HashTable *pHashTable); 

#endif //LAB_12_FUNCTIONS_H
