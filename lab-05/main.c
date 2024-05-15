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
    FILE* file =fopen("bemenet1.txt","r");
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
    FILE* file1 = fopen("bemenet1.txt", "r");
    if (!file1) {
        perror("Error opening file");
        return -1;
    }
    Queue carQueue;
    createQueue(6, &carQueue);

    char line[100];
    if (fgets(line, 100, file1) != NULL) {
        char *token = strtok(line, " ");
        while (token != NULL) {
            enqueue(&carQueue, token);
            token = strtok(NULL, " ");
        }
    }

    fclose(file1);

    bool ok = true;
    while (ok) {
        printf("Choose from the following options:\n"
               "1. Check if queue is empty\n"
               "2. Check if queue is full\n"
               "3. Add a new car to the queue\n"
               "4. Remove a car from the queue\n"
               "5. Display the cars waiting in the queue\n"
               "6. Exit\n\n"
               "Choose an option:");

        int option;
        scanf("%i", &option);

        switch (option) {
            case 1:
                if (isEmpty(carQueue)) {
                    printf("It is empty\n\n");
                } else {
                    printf("It isn't empty\n\n");
                }
                break;
            case 2:
                if (isFull(carQueue)) {
                    printf("It is full\n\n");
                } else {
                    printf("It isn't full\n\n");
                }
                break;
            case 3:
                printf("Enter the car you want to add: ");
                char temp;
                scanf(" %c", &temp);
                enqueue(&carQueue, &temp);
                break;
            case 4:
                printf("Removed the first item from the queue: %s\n", dequeue(&carQueue));
                break;
            case 5:
                display(carQueue);
                break;
            case 6:
                ok = false;
                break;
            default:
                printf("Invalid option\n\n");
        }
    }


}
