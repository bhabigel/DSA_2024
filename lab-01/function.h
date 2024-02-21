#ifndef LAB_01_FUNCTION_H
#define LAB_01_FUNCTION_H

#include <stdio.h>
#include <stdlib.h>
#define MEMORY_ALLOCATION_ERROR 1
int sum(int a, int b);
float minimum(float number1, float number2, float number3);
void allocateMemoryForArray2(int n, int **dpArray);
void readArray(int *n, int **dpArray, const char *input);
void printArray(int *n, int **dpArray, const char *input);
void dellocateMemoryArray(int **dpArray);
#endif //LAB_01_FUNCTION_H
