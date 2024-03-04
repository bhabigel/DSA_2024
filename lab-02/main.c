#include <stdio.h>
#include "functions.h"
int main() { 

int n,choice1,choice2,choice3;
printf("Hany elemu tombokkel szeretnel dolgozni? (1 vagy 2)\n");
scanf("%i", &choice1);

    switch (choice1) {

        case 1:
        {
            printf("\t1.Paros elemek szama\n"
                   "\t2.Pozitiv szamok osszege\n"
                "\t3.Atlag kiszamitasa\n"
                "\t4.Paratlan elemek szama\n"
                "\t5.Negativ szamok szorzata\n"
                   "Valassz!\n");
            scanf("%i", &choice2);

            printf("Hany eleme van a tombnek?");
            scanf("%i", &n);
            int array[100];
            printf("Add meg az elemeket\n");
            for(int i=0;i<n;i++)
                scanf("%i", &array[i]);

            switch (choice2) {

                case 1:
                {
                    printf("A paros szamok szama: %d\n", numberOfEvenNumbers(n, array));
                    break;
                }
                case 2:
                {
                    printf("Pozitiv szamok osszege: %d\n", sumOfPositiveNumbers(n, array));
                    break;
                }
                case 3:
                {
                    printf("Elemek atlaga: %2.f\n", average(n, array));
                    break;
                } 
                case 4:
                {
                    printf("%d paratlan elem van\n", average(n, array));
                    break;
                }
                case 5:
                {
                    printf("%d\n", productOfNegativeNumbers(n, array));
                    break;
                }
            }
            break;
        }

        case 2:
        {
            printf("\t1.Matrix beolvasasa es kiiratasa\n"
                   "\t2.Matrix adott soranak legkissebb eleme\n"
                   "\t3.Egy adott oszlop legnagyobb eleme\n"
                   "\t4.Foatlo elemeinek atlaga\n"
                   "Valassz!\n");
            scanf("%i", &choice3);

            int rows, cols;
            int **matrix;
            switch (choice3) {

                case 1:
                {
                    readMatrix(&rows, &cols, &matrix, "be.txt");
                    printMatrix(rows, cols, matrix, "ki.txt");
                    deallocateMemoryForMatrix(rows,&matrix);
                    break;
                }

                case 2:
                {
                    readMatrix(&rows, &cols, &matrix, "be.txt");
                    printf("Hanyadik sorban szeretnel keresni?\n");
                    int x;
                    scanf("%i",&x);
                    minimumValueOfRow(cols,&rows);
                    deallocateMemoryForMatrix(rows,&matrix);
                    break;
                }
                case 3:
                {
                    readMatrix(&rows, &cols, &matrix, "be.txt");
                    printf("Hanyadik oszopban szeretnel keresni?\n");
                    int columnIndex;
                    scanf("%i",&columnIndex);
                    maximumValueOfColumn(rows, columnIndex,&matrix);
                    deallocateMemoryForMatrix(rows,&matrix);
                    break;
                }
                case 4:
                {
                    readMatrix(&rows, &cols, &matrix, "be.txt");
                    printMatrix(rows, cols, matrix, "ki.txt");
                    printf("Az atlag: %2.f", foatloAtlag(rows, cols, &matrix));
                    deallocateMemoryForMatrix(rows, &matrix);
                    break;
                }


            }


        }

    }



}
