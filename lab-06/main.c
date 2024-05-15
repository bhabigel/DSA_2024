#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "patient.h"
#include "queue.h"

int main() {
    /*struct Patient patient1 = {"John Doe", "1234567890", {15, 4, 1990}, DIABETES};
    printf("Patient 1:\n");
    printPatient(&patient1);*/

   /* struct Patient patient2;
    readPatient(&patient2);
    printf("\nPatient 2:\n");
    printPatient(&patient2);

    FILE *file = fopen(strcat(patient2.CNP, ".txt"), "w");
    if (file != NULL) {
        fprintf(file, "Full Name: %s\n", patient2.fullName);
        fprintf(file, "CNP: %s\n", patient2.CNP);
        fprintf(file, "Birth Date: %d/%d/%d\n", patient2.birthDate.day, patient2.birthDate.month, patient2.birthDate.year);
        fprintf(file, "Disease: ");
        switch(patient2.disease) {
            case INFLUENZA:
                fprintf(file, "INFLUENZA\n");
                break;
            case DIABETES:
                fprintf(file, "DIABETES\n");
                break;
            case CANCER:
                fprintf(file, "CANCER\n");
                break;
            case HYPERTENSION:
                fprintf(file, "HYPERTENSION\n");
                break;
            case ASTHMA:
                fprintf(file, "ASTHMA\n");
                break;
            case HEPATITIS:
                fprintf(file, "HEPATITIS\n");
                break;
            case DEPRESSION:
                fprintf(file, "DEPRESSION\n");
                break;
            case MIGRAINES:
                fprintf(file, "MIGRAINES\n");
                break;
            case ANEMIA:
                fprintf(file, "ANEMIA\n");
                break;
            case OBESITY:
                fprintf(file, "OBESITY\n");
                break;
            case ALLERGIES:
                fprintf(file, "ALLERGIES\n");
                break;
            default:
                fprintf(file, "Unknown\n");
        }
        fclose(file);
        printf("\nPatient data written to file: %s\n", patient2.CNP);
    } else {
        printf("Error opening file.\n");
    }*/

    srand(time(NULL));
    MedicalCenter center;
    int random_value;
    int arrivals_without_place = 0;
    int idle_time_count = 0;
    int capacity;

    printf("Enter the capacity of the medical center: ");
    scanf("%d", &capacity);

    // Feladat 1
    createMedicalCenter(capacity, &center);
    FILE* file = fopen(INPUT_FILE, "r");
    if (!file) {
        printf("Error opening file %s!\n", INPUT_FILE);
        return EXIT_FAILURE;
    }

    // Feladat 2, 3, 4, 5
    for (int i = 0; i < capacity * 10; i++) {
        random_value = rand() % 2;
        if (random_value == 0) {
            Patient new_patient;
            if (fscanf(file, "%s %d %s", new_patient.name, &new_patient.age, new_patient.disease) == 3) {
                enqueue(&center, new_patient);
            }
        } else {
            dequeue(&center);
        }

        // Feladat 3
        if ((i + 1) % 3 == 0) {
            displayQueue(&center);
        }

        // Feladat 4
        if (random_value == 0 && center.size == center.capacity) {
            arrivals_without_place++;
        }

        // Feladat 5
        if (random_value == 1 && center.size == 0) {
            idle_time_count++;
        }
    }
    fclose(file);

    // Feladat 6
    printf("Remaining patients in the queue:\n");
    displayQueue(&center);

    // Feladat 7
    char search_name[50];
    printf("Enter the name of the patient to search for: ");
    scanf("%s", search_name);
    for (int i = 0; i < center.size; i++) {
        if (strcmp(center.patients[i].name, search_name) == 0) {
            printf("Patient %s is in the queue.\n", search_name);
            break;
        }
    }

    // Feladat 8
    int over_50_count = 0;
    for (int i = 0; i < center.size; i++) {
        if (center.patients[i].age > 50) {
            over_50_count++;
        }
    }
    printf("Number of patients over 50 years old: %d\n", over_50_count);

    // Feladat 9
    int diabetes_count = 0;
    for (int i = 0; i < center.size; i++) {
        if (strcmp(center.patients[i].disease, "DIABETES") == 0) {
            diabetes_count++;
        }
    }
    printf("Number of patients with DIABETES disease: %d\n", diabetes_count);

    // Feladat 10
    while (center.size > 0) {
        dequeue(&center);
    }
    printf("All patients have been served. Total number of patients served today: %d\n", center.capacity * 10 - arrivals_without_place);

    // Feladat 11
    free(center.patients);

    return EXIT_SUCCESS;
}
