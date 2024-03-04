//
// Created by Hanga on 26/02/2024.
//
#include <stdio.h>
#include <stdlib.h>

#ifndef LAB_02_FUNCTIONS_H
#define LAB_02_FUNCTIONS_H

int numberOfEvenNumbers(int n, int *pArray);
int sumOfPositiveNumbers(int n, int *pArray);
void allocateMemoryForMatrix2(int rows, int cols, int ***dpMatrix);
void readMatrix(int *pRows, int *pCols, int ***dpArray, const char *input);
void printMatrix(int rows, int cols, int **pMatrix, const char *output);
void printMatrix(int rows, int cols, int **pMatrix, const char *output);
void deallocateMemoryForMatrix(int rows, int ***dpMatrix);
void minimumValueOfRow(int cols, int *pRow);
float average(int n, int* pArray);
int numberOfOddNumbers(int n, int* pArray);
int productOfNegativeNumbers(int n, int* pArray);
int maximumValueOfColumn(int rows, int columnIndex, int** pMatrix);
float foatloAtlag(int rows, int cols, int** pMatrix);


#endif //LAB_02_FUNCTIONS_H
