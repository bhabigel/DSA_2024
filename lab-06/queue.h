//
// Created by Hanga on 14/04/2024.
//

#ifndef LAB_06_QUEUE_H
#define LAB_06_QUEUE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CAPACITY 100
#define INPUT_FILE "patients.txt"

typedef struct {
    char name[50];
    int age;
    char disease[50];
} Patient;

typedef struct {
    int capacity;
    int front;
    int rear;
    int size;
    Patient* patients;
} MedicalCenter;

void createMedicalCenter(int capacity, MedicalCenter* center);
void enqueue(MedicalCenter* center, Patient patient);
void dequeue(MedicalCenter* center);
void displayQueue(MedicalCenter* center);

#endif //LAB_06_QUEUE_H
