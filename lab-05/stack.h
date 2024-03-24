//
// Created by Hanga on 18/03/2024.
//

#ifndef LAB_05_STACK_H
#define LAB_05_STACK_H
#define EMPTY_MESSAGE "Stack is empty.\n"
#define FULL_MESSAGE "Stack is full.\n"
#define MEMORY_ALLOCATION_ERROR_CODE 1
#define MEMORY_ALLOCATION_ERROR_MESSAGE "Memory allocation failed.\n"


typedef struct {
    int capacity;
    int top;
    int *elements;
}Stack;

void createStack(int capacity, Stack *stack);
bool isFull(Stack stack);
void push(Stack *stack, int item);
int pop(Stack *stack);
int peek(Stack stack);
int size(Stack stack);
bool isEmpty(Stack stack);
int Postfix(char *tomb);

#endif //LAB_05_STACK_H
