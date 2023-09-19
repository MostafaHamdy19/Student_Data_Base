#include <stdio.h>
#include <stdlib.h>
#include "SDB.h"



/***************************************************ScanData***************************************************************************************/

void ScanData(student* dataPtr) //scan the student information
{

    uint32 id;

    printf("Enter Student ID   : ");
    scanf("%d",&id);
    while(true== SDB_IsIdExist (id))
    {
        printf("Repeated ID\n\n");
        printf("Enter Student ID   : ");
        scanf("%d",&id);
    }
    (dataPtr->Student_ID)=id;

    printf("Enter Student_year : ");
    scanf("%d",&(dataPtr->Student_year));

    printf("Enter Course1_ID   : ");
    scanf("%d",&(dataPtr->Course1_ID));

    printf("Enter Course1_grade: ");
    scanf("%d",&(dataPtr->Course1_grade));

    printf("Enter Course2_ID   : ");
    scanf("%d",&(dataPtr->Course2_ID));

    printf("Enter Course2_grade: ");
    scanf("%d",&(dataPtr->Course2_grade));

    printf("Enter Course3_ID   : ");
    scanf("%d",&(dataPtr->Course3_ID));

    printf("Enter Course3_grade: ");
    scanf("%d",&(dataPtr->Course3_grade));
    printf("\n");
}

/***************************************************PrintData***************************************************************************************/

void PrintData(student* dataPtr) //print student information
{
    printf("Student ID    : %d\n",(dataPtr->Student_ID));

    printf("Student_year  : %d\n",(dataPtr->Student_year));

    printf("Course1_ID    : %d\n",(dataPtr->Course1_ID));

    printf("Course1_grade : %d\n",(dataPtr->Course1_grade));

    printf("Course2_ID    : %d\n",(dataPtr->Course2_ID));

    printf("Course2_grade : %d\n",(dataPtr->Course2_grade));

    printf("Course3_ID    : %d\n",(dataPtr->Course3_ID));

    printf("Course3_grade : %d\n\n",(dataPtr->Course3_grade));
}


Node*start=NULL; // global declaration of start of the linked list

/***************************************************GetUsedSize***************************************************************************************/

uint8 SDB_GetUsedSize() //returns the size of the list
{
    Node * ptr=start;
    uint8 counter=0;
    if (start==NULL)
    {
        return 0;
    }
    else
    {
        while(ptr != NULL)
        {

            counter++;
            ptr = ptr->Link;

        }

    }
    return counter;
}
/***************************************************IsFull********************************************************************************************/

bool SDB_IsFull() // check if the list is full or not
{
    uint8 NumberOfElements= SDB_GetUsedSize();

    if (10 == NumberOfElements )
        return true;
    else
        return false;

}
/***************************************************AddEntry*****************************************************************************************/

bool SDB_AddEntry() //Create a list if it's empty and Add new student at the end of the list
{
    Node * ptr=start;

    if (true == SDB_IsFull() )
        return false;

    else if (SDB_GetUsedSize()==0)
    {
        Node * NewNode=(Node*) malloc(sizeof(Node));
        if (NewNode != NULL)
        {
            NewNode->Link=start;
            start= NewNode;
            student *dataPtr;
            dataPtr=&(NewNode->info);
            ScanData(dataPtr);

        }
    }

    else
    {
        Node * NewNode=(Node*) malloc(sizeof(Node));
        if (NewNode != NULL)
        {
            while(ptr->Link!=NULL)
            {
                ptr=ptr->Link;
            }

            ptr->Link=NewNode;
            NewNode-> Link=NULL;
            student *dataPtr;
            dataPtr=&(NewNode->info);
            ScanData(dataPtr);







        }
        else
            return false;


    }

    return true;

}
/***************************************************DeletEntry***************************************************************************************/

void SDB_DeletEntry (uint32 id) //Delete a student of a list given its ID
{
    Node* ptr=start;
    Node* temp=NULL;
    uint8 flag=0;
    if (ptr!=NULL)
    {
        if ((ptr->info).Student_ID==id)
        {

            start=ptr->Link;
            free(ptr);
            flag=1;


        }


        else
        {


            while(ptr->Link!=NULL)
            {
                if((ptr->Link->info).Student_ID==id)
                {
                    temp=ptr->Link;
                    ptr->Link=ptr->Link->Link;
                    free(temp);
                    flag=1;
                    break;

                }
                ptr=ptr->Link;

            }


        }
        if(flag==0)
            printf("The Element does not exsist \n");


    }

}
/***************************************************ReadEntry****************************************************************************************/

bool SDB_ReadEntry (uint32 id) //print student data given its ID
{

    uint8 found=0;

    Node* ptr=start;

    if (ptr==NULL)
    {
        return false;
    }

    else
    {
        while ( found==0 && (ptr!=NULL) )
        {



            if(((ptr->info).Student_ID)==id)
            {
            student * ptrStudent=&(ptr -> info);
            PrintData(ptrStudent);
            found=1;
            }

            ptr=ptr->Link;
        }

        if (found==0)
            return false;
        else
            return true;

    }



}
/***************************************************GetList*****************************************************************************************/

void SDB_GetList (uint8 * count, uint32 * list) // update a given array with specific number of student ID list
{

    Node*ptr=start;
    uint8 counter = SDB_GetUsedSize();

    for (counter=0; counter<(*count); counter++)
    {
        list[counter]=((ptr->info).Student_ID);
        ptr=ptr->Link;
    }

}
/***************************************************IsIdExist****************************************************************************************/

bool SDB_IsIdExist (uint32 id) //check if the given ID exists or not
{
    Node* ptr=start;

    if (ptr==NULL)
    {
        return false;
    }

    else
    {
        while (ptr !=NULL)
        {
            if (((ptr->info).Student_ID)==id)
                return true;

            ptr=ptr->Link;
        }

        return false;


    }
}
