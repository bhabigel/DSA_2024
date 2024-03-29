#include "function.h"
#include <string.h>
#include <stdio.h>
int sum(int a,int b)
{
    return a+b;
}



float minimum(float number1, float number2, float number3)
{
    float min = number1;
    if (number2 < min) {
        min = number2;
    }
    if (number3 < min) {
        min = number3;
    }
    return min;
}

void allocateMemoryForArray2(int n, int **dpArray) {
    *dpArray = malloc(n * sizeof(int));
    if (!*dpArray)
        exit(MEMORY_ALLOCATION_ERROR);
}

void readArray(int *pn, int **dpArray, const char *input) {
    if (strcmp(input, "CON") == 0) {
        // Read from keyboard
    }
    if (strcmp(input, "FILE") == 0) {
        // Read from file
        FILE *in = fopen(input, "r");
        if (!in) exit(EXIT_FAILURE);
        fscanf(in, "%i", pn);
        allocateMemoryForArray2(*pn, dpArray);

        for (int i = 0; i < *pn; i++) {
            fscanf(in, "%i", &((*dpArray)[i]));
        }
        fclose(in);
    }
}

void printArray(int *n, int **dpArray, const char *output) {
    FILE *file = fopen(output, "w");
    if (file == NULL) {
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++) {
        fprintf(file, "%d ", dpArray[i]);
    }

    fclose(file);
}

void dellocateMemoryArray(int **dpArray) {
    free(*dpArray);
}


