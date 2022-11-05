#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef unsigned int uint8;

int n = 0,i,d=0;

struct SimpleDb
{
    uint8 student_id;
    uint8 student_year;
    uint8 course_1_id;
    uint8 course_1_grade;
    uint8 course_2_id;
    uint8 course_2_grade;
    uint8 course_3_id;
    uint8 course_3_grade;
    struct SimpleDb *link;
}*ptr;

bool SDB_isFull(void);
uint8 SDB_GetUsedSize(void);
bool SDB_AddEntry(uint8 id, uint8 year, uint8* subjects, uint8* grades);
void SDB_DeleteEntry(uint8 id);
bool SDB_ReadEntry(uint8 id);
void SDB_GetIdList(uint8 count, int* list);
bool SDB_IsIdExist(uint8 ID);

#endif // FUNCTIONS_H_INCLUDED
