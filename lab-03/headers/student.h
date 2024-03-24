#include <stdio.h>
#include <stdlib.h>

#ifndef LAB_03_STUDENT_H
#define LAB_03_STUDENT_H
enum Quality{GOOD,BAD,OTHER};
typedef struct
{
    char  title[25];
    int year;
    enum Quality quality;
}FILM;

void readFilms(FILM *film);
void printFilms(FILM film);
#endif //LAB_03_STUDENT_H

