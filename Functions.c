#include "Functions.h"

bool SDB_isFull(void)
{
    if(n >= 10)
        return true;
    return false;
}

uint8 SDB_GetUsedSize(void)
{
    return n;
}

bool SDB_AddEntry(uint8 id, uint8 year, uint8* subjects, uint8* grades)
{
    for(i=0;i<3;i++)
        if(grades[i] < 0 || grades[i] > 100)
            {
                printf("Error : The Grade Of Course Number %i Is Not Between 0 And 100\n",i+1);
                return 0;
            }
    struct SimpleDb* temp = ptr;
    while(temp != NULL)
    {
        if(temp->student_id == id)
        {
            printf("Error: There Is An Existed Entry With The Same ID\n");
            return 0;
        }
        temp = temp->link;
    }
    if(SDB_isFull() == 0)
    {
        struct SimpleDb* std = (struct SimpleDb*) malloc(sizeof(struct SimpleDb));
        std->student_id = id;
        std->student_year = year;
        std->course_1_id = subjects[0];
        std->course_1_grade = grades[0];
        std->course_2_id = subjects[1];
        std->course_2_grade = grades[1];
        std->course_3_id = subjects[2];
        std->course_3_grade = grades[2];
        std->link = NULL;
        if(ptr == NULL)
            ptr = std;
        else
        {
            std->link = ptr;
            ptr = std;
        }
        printf("%i\n",std->student_id);
        n++;
        printf("Entry Number %i Has Been Made\n",n);
        return 1;
    }
    else
    {
        printf("Error : The Database Is Full(The Max. Number Of Entries Has Been Reached)\n");
        return 0;
    }
}

void SDB_DeleteEntry(uint8 id)
{
    struct SimpleDb* temp = ptr;
    while(temp != NULL)
    {
        if(temp->student_id == id)
        {
         temp->student_id = NULL;
         temp->student_year = NULL;
         temp->course_1_id = NULL;
         temp->course_1_grade = NULL;
         temp->course_2_id = NULL;
         temp->course_2_grade = NULL;
         temp->course_3_id = NULL;
         temp->course_3_grade = NULL;
         n--;
         d++;
         printf("Entry With ID %i Has Been Deleted Successfully\n",id);
         break;
        }
        temp = temp->link;
    }
    printf("Error Deleting Entry With ID %i\n",id);
}

bool SDB_ReadEntry(uint8 id)
{
    struct SimpleDb* temp = ptr;
    while(temp != NULL)
    {
        if(temp->student_id == id)
        {
            printf("Student ID: %i\n",temp->student_id);
            printf("Student Year: %i\n",temp->student_year);
            printf("Course 1 ID: %i\n",temp->course_1_id);
            printf("Course 1 Grade: %i\n",temp->course_1_grade);
            printf("Course 2 ID: %i\n",temp->course_2_id);
            printf("Course 2 Grade: %i\n",temp->course_2_grade);
            printf("Course 3 ID: %i\n",temp->course_3_id);
            printf("Course 3 Grade: %i\n",temp->course_3_grade);
            return 1;
        }
        temp = temp->link;
    }
    return 0;
}

void SDB_GetIdList(uint8 count, int* list)
{
    count = 0;
    struct SimpleDb* temp = ptr;
    while(temp!= NULL)
    {
        list[count] = temp->student_id;
        count++;
        temp = temp->link;
    }
    count-=d;
     printf("The Number Of IDs In The Database Is %i Which Are:\n",count);
        for(i=0;i<10;i++)
            if(list[i] != 0)
                printf("%i \n",list[i]);
}

bool SDB_IsIdExist(uint8 ID)
{
    struct SimpleDb* temp = ptr;
    while(temp != NULL)
    {
        if(temp->student_id == ID)
            return 1;
        temp = temp->link;
    }
    return 0;
}

