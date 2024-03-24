//
// Created by Hanga on 18/03/2024.
//

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>

void createStack(int capacity, Stack *stack)
{
    stack->capacity = capacity;
    stack->top = -1;
    stack->elements = (int*)calloc(stack->capacity, sizeof (int));
    if(!stack->elements) {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
}

bool isEmpty(Stack stack)
{
    return stack.top == -1;
}
bool isFull(Stack stack)
{
    return stack.top == stack.capacity-1;
}
int pop(Stack *stack)
{
    if (isEmpty(*stack)) {
        printf(EMPTY_MESSAGE);
        return INT_MIN;
    }
    int temp = stack->elements[stack->top];
    stack->elements[stack->top--] = 0;
    return temp;
}

void push(Stack *stack, int item)
{
    if(isFull(*stack)) {
        printf(FULL_MESSAGE);
        return;
    }
    stack->elements[++stack->top] = item;
}

int peek(Stack stack) {
    if (isEmpty(stack)) {
        printf(EMPTY_MESSAGE);
        return INT_MIN;
    }
    return stack.elements[stack.top];
}

int size(Stack stack)
{
    return stack.top+1;
}

int Postfix(char *tomb) {
    Stack stack;
    createStack(100, &stack);

    char *token = strtok(tomb, " ");
    int operand1, operand2, result;

    while (token) {
        if (isdigit(*token)) {
            push(&stack, atoi(token));
        } else {
            operand2 = pop(&stack);
            operand1 = pop(&stack);

            switch (*token) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 != 0)
                        result = operand1 / operand2;
                    else {
                        printf("Hibas muvelet\n");
                        return INT_MIN;
                    }
                    break;
                default:
                    printf("Hibas operator\n");
                    return INT_MIN;
            }
            push(&stack, result);
        }
        token = strtok(NULL, " ");
    }

    if (size(stack) == 1) {
        return pop(&stack);
    } else {
        printf("Hianyos kifejezes\n");
        return INT_MIN;
    }
}
