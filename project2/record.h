/*****************************************************************
//
//  NAME:        Johnathan Callejo
//
//  HOMEWORK:    3b
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        September 21, 2022
//
//  FILE:        record.h
//
//  DESCRIPTION:
//   Is a array record of the user information.
//
//  REFERENCES:
//    None
//
****************************************************************/

struct record
{
    int accountno;
    char name[30];
    char address[60];
    struct record *next;
};
