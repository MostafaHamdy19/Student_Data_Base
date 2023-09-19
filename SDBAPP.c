#include <stdio.h>
#include <stdlib.h>
#include "STD.h"
#include "SDB.h"


/***************************************************SDB_APP***************************************************************/

void SDB_APP () //starting the program and printing the choices for the user
{
    uint8 choice;

    do
    {
        printf("Please Enter your choice:\n\n");
        printf("1-Add New Student\n");
        printf("2-Number of students\n");
        printf("3-Read student data\n");
        printf("4-Get the list of student IDs\n");
        printf("5-check if ID is existed\n");
        printf("6-Delete student\n");
        printf("7-Check if database is full\n");
        printf("\nTo Exsit enter 0\n");
        printf("\nChoice: ");
        scanf("%d",&choice);
        printf("\n");

        SDB_action (choice);

    }
    while (choice!=0);


}
/***************************************************SDB_action***************************************************************/

void SDB_action (uint8 choice) // call the required function according to the user's choice
{
    uint32 ID;
    uint8 ELementsNumbers;
    uint32 List[10];
    uint8 counter;
    uint8 listCount;

    switch (choice)
    {
    case 0: // exsit
        printf("Thank You\n");
        break;

    case 1://add entry
        ELementsNumbers = SDB_GetUsedSize();
        if (10==ELementsNumbers)
        printf("The List is Full\n\n");

       else if (ELementsNumbers<3)
        {
            while ( ELementsNumbers < 3 )
            {
                if( false== SDB_AddEntry())
                    printf("Error in Adding new Element\n\n");

                ELementsNumbers = SDB_GetUsedSize();
            }
        }
        else if( false== SDB_AddEntry())
            printf("Error in Adding new Element\n\n");

        break;


    case 2: // get used size
        ELementsNumbers=SDB_GetUsedSize();
        printf("Size of the list:%d\n\n",ELementsNumbers);
        break;


    case 3: // Read entry
        printf("Enter student ID: ");
        scanf("%d",&ID);
        printf("\n");
        if( false==SDB_ReadEntry (ID) )
        {
            printf("Element does not exist\n\n");
        }

        break;


    case 4: //get list
        ELementsNumbers=SDB_GetUsedSize();
        if (0==ELementsNumbers)
            printf("The List is empty\n\n");
        else
        {
            printf("Enter the number of elements you need to List: ");
            scanf("%d",&listCount);
            printf("\n");
            if (listCount>ELementsNumbers)
            {
                printf("There are only %d Elements in the list\n\n",ELementsNumbers);
                break;
            }
            else
            {
                SDB_GetList (&listCount, &List);
                for (counter=0; counter<listCount; counter++)
                {
                    printf("Student number %d ID : %d\n",(counter+1),List[counter]);
                }
                printf("\n");
            }
        }
        break;


    case 5: // is id exist
        printf("Enter student ID: ");
        scanf("%d",&ID);
        printf("\n");
        if ( true ==SDB_IsIdExist (ID))
            printf("ID exists\n\n");
        else
            printf("ID does not exist\n\n");
        break;


    case 6: // delete entry
        printf("Enter the number of the ID: ");
        scanf("%d",&ID);
        printf("\n");
        SDB_DeletEntry (ID);
        break;


    case 7: // is full
        if (true == SDB_IsFull())
            printf("The List is full\n\n");
        else
            printf("The List is not full\n\n");

        break;

    default: // wrong choice
        printf("please Enter a valid choice\n\n");
        break;


    }
}
