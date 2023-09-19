#ifndef SDB_H
#define SDB_H
#include "STD.h"



typedef struct SimpleDb
{
    uint32 Student_ID;
    uint32 Student_year;

    uint32 Course1_ID;
    uint32 Course1_grade;

    uint32 Course2_ID;
    uint32 Course2_grade;

    uint32 Course3_ID;
    uint32 Course3_grade;

} student;

typedef struct n //Node declaration
{

    student info;

    struct n * Link;

} Node ;

// functions prototypes

void ScanData(student* dataPtr);
void PrintData(student* dataPtr);
bool SDB_IsFull(void);
uint8 SDB_GetUsedSize(void);
bool SDB_AddEntry(void);
void SDB_DeletEntry (uint32 id);
bool SDB_IsIdExist (uint32 id);
void SDB_APP ();
void SDB_action (uint8 choice);


#endif // SDB_H
