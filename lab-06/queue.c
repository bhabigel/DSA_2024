#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void createMedicalCenter(int capacity, MedicalCenter* center) {
    center->capacity = capacity;
    center->front = 0;
    center->rear = -1;
    center->size = 0;
    center->patients = (Patient*)calloc(capacity, sizeof(Patient));
    if (!center->patients) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
}

void enqueue(MedicalCenter* center, Patient patient) {
    if (center->size == center->capacity) {
        printf("The medical center is full.\n");
        return;
    }
    center->rear = (center->rear + 1) % center->capacity;
    center->patients[center->rear] = patient;
    center->size++;
}

void dequeue(MedicalCenter* center) {
    if (center->size == 0) {
        printf("The medical center is empty.\n");
        return;
    }
    printf("%s has been served.\n", center->patients[center->front].name);
    center->front = (center->front + 1) % center->capacity;
    center->size--;
}

void displayQueue(MedicalCenter* center) {
    if (center->size == 0) {
        printf("The medical center is empty.\n");
        return;
    }

    printf("Patients in the medical center:\n");
    int i = center->front;
    for (int j = 0; j < center->size; j++) {
        printf("%s (%d years)\n", center->patients[i].name, center->patients[i].age);
        i = (i + 1) % center->capacity;
    }
}

