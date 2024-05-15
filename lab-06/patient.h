
#ifndef LAB_06_PATIENT_H
#define LAB_06_PATIENT_H

enum Disease {
    INFLUENZA, DIABETES, CANCER, HYPERTENSION, ASTHMA, HEPATITIS, DEPRESSION, MIGRAINES, ANEMIA, OBESITY, ALLERGIES
};

struct Date {
    int day, month, year;
};

struct Patient {
    char fullName[41];
    char CNP[11];
    struct Date birthDate;
    enum Disease disease;
};

void readPatient(struct Patient *patient);
void printPatient(const struct Patient *patient);

#endif //LAB_06_PATIENT_H
