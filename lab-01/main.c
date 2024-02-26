#include <stdio.h>
#include "function.h"
int main() {
    int a,b,c;
    int choice;
    float number1, number2,number3;

    printf("\t1.Sum of two numbers\n"
           "\t2.Minimum from three numbers\n"
           "\t.3 Dynamic memory allocation\n"
           "Choose one exercise:"
           );
    scanf("%i",&choice);


    switch (choice) {

        case 1:
        {
            printf("Enter two numbers:");
            scanf("%i%i",&a,&b);
            printf("The sum is: %i", sum(a,b));
            break;
        }
        case 2:
        {
            printf("Enter three numbers:");
            scanf("%f%f%f",&number1,&number2,&number3);
            printf("The minimum from the numbers is: %2.f", minimum(number1,  number2,  number3));
            break;
        }
        case 3:
        {
            int n=5, *pArray = NULL;
            allocateMemoryForArray2(n,&pArray);
            readArray(&n, &pArray, "be.txt");
             //printArray(&n, &pArray, "be.txt");
            break;
        }
    }

//
}
