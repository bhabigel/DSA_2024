#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "functions.h"
int main() {
    srand(time(0));
    HashTable  hTable;
    createHashArray(&hTable);
    for(int i=0;i<CAPACITY;i++)
    {
        int key=rand()%11;
        int data = rand()%100;
        printf("key %i, data %i", key,data);
        insert(&hTable,key,data);
        display(hTable);
        printf("\n\n");
    }


}
