#include "functions.h"
#include <string.h>
#include <stdio.h>
int numberOfEvenNumbers(int n, int *pArray)
{
    int count=0;
    for(int i=0;i<n;i++)
        if(pArray[i]%2==0)
            count++;
    return count;
}

int sumOfPositiveNumbers(int n, int *pArray)

{
    int sum=0;
    for(int i=0;i<n;i++)
        if(pArray[i]%2==0)
            sum += pArray[i];
    return sum;
}

void allocateMemoryForMatrix2(int rows, int cols, int ***dpMatrix) {
    *dpMatrix = (int **)malloc(rows * sizeof(int *));
    if (*dpMatrix == NULL) {
        printf("Error");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < rows; i++) {
        (*dpMatrix)[i] = (int *)malloc(cols * sizeof(int));
        if ((*dpMatrix)[i] == NULL) {
            printf("Error");
            exit(EXIT_FAILURE);
        }
    }
}

void readMatrix(int *pRows, int *pCols, int ***dpArray, const char *input) {
    FILE *file = fopen(input, "r");
    if (file == NULL) {
        printf("Error");
        exit(EXIT_FAILURE);
    }
    fscanf(file, "%d %d", pRows, pCols);

    allocateMemoryForMatrix2(*pRows, *pCols, dpArray);

    for (int i = 0; i < *pRows; i++) {
        for (int j = 0; j < *pCols; j++) {
            fscanf(file, "%d", &(*dpArray)[i][j]);
        }
    }

    fclose(file);
}

void printMatrix(int rows, int cols, int **pMatrix, const char *output) {
    FILE *file = fopen(output, "w");

    if (file == NULL) {
        printf("Error");
        return;
    }

    fprintf(file, "%d %d\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(file, "%d ", pMatrix[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}
void deallocateMemoryForMatrix(int rows, int ***dpMatrix)
{
    for (int i = 0; i < rows; i++) {
        free(dpMatrix[i]);
    }
    free(dpMatrix);

}

void minimumValueOfRow(int cols, int *pRow){
    int min = pRow[0];

    for (int i = 1; i < cols; i++) {
        printf("%i , ",pRow[i]);
        if (pRow[i] < min) {
            min = pRow[i];
        }
    }

    printf("\n%i",min);
}