#include <stdio.h>
#include "stack.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/* while (token) {
     printf("%s\n", token);
     token = strtok(NULL, " ");
 }*/
int main() {
    FILE* file =fopen("bemenet.txt","r");
    if(!file)
    {
        return -1;
    }

    int n=100;
    Stack* stack;
    createStack(n,&stack);
    char input[100];
    fscanf(file, "%[^\n]", input);

    int result = Postfix(input);
    if (result != INT_MIN) {
        printf("A postfix eredmenye: %d\n", result);
    }

    fclose(file);

}
