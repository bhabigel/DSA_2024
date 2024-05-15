#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createQueue(int capacity, Queue *queue) {
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->elements = (char **)calloc(queue->capacity, sizeof(char *));
    if (!queue->elements) {
        printf("MEMORY_ALLOCATION_ERROR_MESSAGE\n");
        exit(-1);
    }
}

void destroyQueue(Queue *queue) {
    free(queue->elements);
    queue->front = queue->rear = -1;
    queue->capacity = 0;
}

bool isEmpty(Queue queue) {
    return queue.front == -1;
}

bool isFull(Queue queue) {
    return queue.rear == queue.capacity - 1;
}

void enqueue(Queue *queue, char *item) {
    if (isFull(*queue)) {
        printf("FULL_MESSAGE\n");
        return;
    }
    if (isEmpty(*queue)) {
        queue->front = 0;
    }
    strcpy(queue->elements[++queue->rear], item);
}

char *dequeue(Queue *queue) {
    if (isEmpty(*queue)) {
        printf("EMPTY_MESSAGE\n");
        return NULL;
    }
    char *item = queue->elements[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front++;
    }
    return item;
}

void display(Queue queue) {
    if (isEmpty(queue)) {
        printf("The queue is empty.\n");
        return;
    }
    printf("The elements in the queue are:\n");
    for (int i = queue.front; i <= queue.rear; ++i) {
        printf("%s\n", queue.elements[i]);
    }
}
