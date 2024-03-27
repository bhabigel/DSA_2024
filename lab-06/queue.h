//
// Created by Hanga on 27/03/2024.
//

#ifndef LAB_06_QUEUE_H
#define LAB_06_QUEUE_H

typedef struct {
    int capacity;
    int front;
    int rear;
    char ** elements;
}Queue;

#define EMPTY_MESSAGE "Stack is empty.\n"
#define FULL_MESSAGE "Stack is full.\n"
#define MEMORY_ALLOCATION_ERROR_CODE 1
#define MEMORY_ALLOCATION_ERROR_MESSAGE "Memory allocation failed.\n"


void createQueue(int capacity, Queue *queue);
void destroyQueue(Queue* queue);
bool isFull(Queue queue);
bool isEmpty(Queue queue);
void enqueue(Queue* queue, char* item);
char* dequeue(Queue* queue);
void display(Queue queue);


#endif //LAB_06_QUEUE_H
