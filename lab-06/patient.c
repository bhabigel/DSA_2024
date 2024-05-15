#include "patient.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void readPatient(struct Patient *patient) {
    printf("Enter full name: ");
    fgets(patient->fullName, sizeof(patient->fullName), stdin);
    patient->fullName[strcspn(patient->fullName, "\n")] = '\0'; // Remove newline character if present

    printf("Enter CNP: ");
    fgets(patient->CNP, sizeof(patient->CNP), stdin);
    patient->CNP[strcspn(patient->CNP, "\n")] = '\0'; // Remove newline character if present

    printf("Enter birth date (dd mm yyyy): ");
    scanf("%d %d %d", &patient->birthDate.day, &patient->birthDate.month, &patient->birthDate.year);
    getchar(); // Clear input buffer

    int diseaseIndex;
    printf("Enter disease: ");
    printf("0-INFLUENZA, 1-DIABETES, 2-CANCER, 3-HYPERTENSION, 4-ASTHMA, 5-HEPATITIS, 6-DEPRESSION, 7-MIGRAINES, 8-ANEMIA, 9-OBESITY, 10-ALLERGIES\n");

    // Új sortörés karakterek törlése a bemeneti pufferből
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    // Betegség számának beolvasása
    if (scanf("%d", &diseaseIndex) != 1) {
        printf("Invalid input for disease!\n");
        return;
    }

    // Ellenőrzés, hogy a betegség sorszáma érvényes-e
    if (diseaseIndex < 0 || diseaseIndex > 10) {
        printf("Invalid disease option!\n");
        return;
    }

    // Átállítás az enum Disease indexelésére
    patient->disease = (enum Disease)diseaseIndex;
}


void printPatient(const struct Patient *patient) {
    printf("Full Name: %s\n", patient->fullName);
    printf("CNP: %s\n", patient->CNP);
    printf("Birth Date: %d/%d/%d\n", patient->birthDate.day, patient->birthDate.month, patient->birthDate.year);
    printf("Disease: ");
    switch(patient->disease) {
        case INFLUENZA:
            printf("INFLUENZA\n");
            break;
        case DIABETES:
            printf("DIABETES\n");
            break;
        case CANCER:
            printf("CANCER\n");
            break;
        case HYPERTENSION:
            printf("HYPERTENSION\n");
            break;
        case ASTHMA:
            printf("ASTHMA\n");
            break;
        case HEPATITIS:
            printf("HEPATITIS\n");
            break;
        case DEPRESSION:
            printf("DEPRESSION\n");
            break;
        case MIGRAINES:
            printf("MIGRAINES\n");
            break;
        case ANEMIA:
            printf("ANEMIA\n");
            break;
        case OBESITY:
            printf("OBESITY\n");
            break;
        case ALLERGIES:
            printf("ALLERGIES\n");
            break;
        default:
            printf("Unknown\n");
    }
}
