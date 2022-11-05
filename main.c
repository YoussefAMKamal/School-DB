/*
 *  Youssef Ahmed Mohamed
 *  C programming Project
 */

#include <stdio.h>
#include <stdlib.h>

static int count,list[10];
int main()
{
    int id, year, sub[3], s_g[3], t,n,d;

    while(1)
    {
        printf("Choose The Number Of Operation U Want To Do:\n1- Check If The Database Is Full\
               \t2- Get The Number Of Entries In The Database\n3- Add A New Entry\t\t\t\t4- Delete Entry With A Given ID\
               \n5- Read An Entry With A Given ID\t\t6- Get The List Of Existed IDs\n7- Checks If An ID Exists\t\t\t8- Exit The Program\n");
        scanf("%i",&n);
        system("CLS");
        switch(n)
        {
        case 1: //Check If The Database Is Full
            {
                t = SDB_isFull();
                if(t == 1)
                    printf("Database Is Full\n");
                else
                    printf("Database Is Not Full\n");
                break;
            }
        case 2: //Get The Number Of Entries In The Database
            {
                t = SDB_GetUsedSize();
                printf("The Number Of Entries In The Database Is %i Entries\n",t);
                break;
            }
        case 3: //Add A New Entry
            {
                printf("Enter The Student ID : ");
                scanf("%i",&id);
                printf("Enter The Student Year : ");
                scanf("%i",&year);
                printf("Enter The Course 1 ID: ");
                scanf("%i",&sub[0]);
                printf("Enter The Course 1 Grade : ");
                scanf("%i",&s_g[0]);
                printf("Enter The Course 2 ID : ");
                scanf("%i",&sub[1]);
                printf("Enter The Course 2 Grade : ");
                scanf("%i",&s_g[1]);
                printf("Enter The Course 3 ID : ");
                scanf("%i",&sub[2]);
                printf("Enter The Course 3 Grade : ");
                scanf("%i",&s_g[2]);
                t = SDB_AddEntry(id, year, &sub, &s_g);
                if(t == 1)
                    printf("Adding Entry Succeeded\n");
                else
                    printf("Adding Entry Failed\n");
                break;
            }
        case 4: //Delete Entry With A Given ID
            {
                printf("Enter The ID That U Want To Delete Its Entry: ");
                scanf("%i",&d);
                SDB_DeleteEntry(d);

                break;
            }
        case 5: //Read An Entry With A Given ID
            {
                printf("Enter The ID That U Want To Read Its Entry: ");
                scanf("%i",&d);
                t = SDB_ReadEntry(d);
                if(t == 0)
                    printf("Error: Entry With This ID Do Not Exist\n");
                break;
            }
        case 6: //Get The List Of Existed IDs
            {
                SDB_GetIdList(count,&list);
                break;
            }
        case 7: //Checks If An ID Exists
            {
                printf("Enter The ID That U Want To Check If It Exists: ");
                scanf("%i",&d);
                t = SDB_IsIdExist(d);
                if(t == 1)
                    printf("ID Exists\n");
                else if(t == 0)
                    printf("ID Do Not Exist\n");
                break;
            }
        case 8: //Exit The Program
            {
                return 0;
            }
        }
        printf("\n");
    }
}
