/*****************************************************************
//
//  NAME:        Johnathan Callejo
//
//  HOMEWORK:    Project2
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        Nov 20, 2022
//
//  FILE:        llist.cpp
//
//  DESCRIPTION:
//   Contains all class member functions of llist.h
//
//  REFERENCES:  https://cplusplus.com/forum/beginner/198057/
//               https://cplusplus.com/doc/tutorial/basic_io/#cout
//
****************************************************************/

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>

#ifndef RECORD_H
#define RECORD_H

#include "record.h"

#endif

#ifndef LLIST_H
#define LLIST_H

#include "llist.h"

#endif

using namespace std;

/*****************************************************************
//
//  Function name: addRecord
//
//  DESCRIPTION:   Adds a record to the linked list
//
//  Parameters:    uaccountno (int) : Account number entered by user.
//                 uname (char[]) : The name entered by the user.
//                 uaddress (char[]) : Address entered by the user.
//                 this (llist*) : Pointer to current record.
//
//  Return values: void : none
//
****************************************************************/

void llist::addRecord(int uaccountno, char uname[], char uaddress[])
{
    struct record * temp;
    struct record * prev;
    struct record * userRecord;
    int tempNum, pass;

    userRecord = new struct record;
    temp = start;
    tempNum = 0;
    pass = 0;

    userRecord->accountno = uaccountno;
    strcpy(userRecord->name, uname);
    strcpy(userRecord->address, uaddress);

    if (start == NULL || (start->accountno <= uaccountno))
    {
        temp = start;
        start = userRecord;
        userRecord->next = temp;
    }
    else
    {
        while (temp != NULL)
        {
            prev = temp;
            temp = temp->next;
            if (temp != NULL)
            {
                tempNum = temp->accountno;
           
                if (tempNum <= uaccountno && pass != 1)
                {
                    userRecord->next = temp;
                    prev->next = userRecord;
                    prev = userRecord;
                    pass = 1;
                }
                else
                {
                    tempNum = 0;
                }
            }
            else if (temp == NULL && pass == 1) 
            {
                pass = 0;
            }
            else
            {
                prev->next = userRecord;
                userRecord->next = NULL;
            }
        }
    }

    #ifdef DEBUG
        cout << "Added Record No:" << uaccountno <<endl;
        cout << "Added Record Name:" << uname <<endl;
        cout << "Added Record Address:" << uaddress <<endl;
    #endif

    temp = NULL;
    prev = NULL;
    userRecord = NULL;
}

/*****************************************************************
//
//  Function name: findRecord
//
//  DESCRIPTION:   Prints out a record of the same account number entered.
//
//  Parameters:    uaccountno (int) : Account number entered by user.
//                 this (llist*) : Pointer to current record.
//
//  Return values: -1 : fail
//                 0 : success
//
****************************************************************/

int llist::findRecord(int uaccountno)
{
    struct record * temp;
    int tempNum;
    int pass;
    int count;
    char tempaddress[60];
    char uaddress[60];

    tempNum = 0;

    if (start == NULL)
    {
        cout << "Record does not exist.\n\n";
        pass = -1;
    }
    else if (start->accountno == uaccountno || start->next == NULL)
    {
        tempNum = start->accountno;
        temp = start;

        if (tempNum == uaccountno)
        {
            while (uaccountno == tempNum && temp != NULL)
            { 
               strcpy(uaddress, temp->address);

                for (count = 0; count < 60;)
                {
                    tempaddress[count] = uaddress[count];
                    if (uaddress[count] == '+')
                    {
                        tempaddress[count] = '\0';
                        count = 60;
                    }
                    count = count + 1;
                }

                cout << "-------------------------\n";
                cout << "Record account number:  " << uaccountno << endl;
                cout << "Name: " << temp->name << endl;
                cout << "Address: " << tempaddress << endl;
                cout << "-------------------------\n";

                temp = temp->next;
                if (temp != NULL)
                {
                    tempNum = temp->accountno;
                }
            }
            pass = 0;
        }
        else
        {
            cout << "Record does not exist.\n\n";
            pass = -1;
        }
    }
    else
    {
        temp = start->next;

        do
        {
            tempNum = temp->accountno;

            if (tempNum == uaccountno)
            {
                while (uaccountno == tempNum && temp != NULL)
                {
                    strcpy(uaddress, temp->address);

                    for (count = 0; count < 60;)
                    {
                        tempaddress[count] = uaddress[count];
                        if (uaddress[count] == '+')
                        {
                            tempaddress[count] = '\0';
                            count = 60;
                        }
                        count = count + 1;
                    }
                    cout << "-------------------------\n";
                    cout << "Record account number:  " << uaccountno << endl;
                    cout << "Name: " << temp->name << endl;
                    cout << "Address: " << tempaddress << endl;
                    cout << "-------------------------\n";

                    temp = temp->next;
                    if (temp != NULL)
                    {
                        tempNum = temp->accountno;
                    }
                }
                pass = 0;
            }
            else
            {
                temp = temp->next;
                pass = -1;
            }
        } while (temp != NULL && pass == -1);
        if (pass == -1)
        {
            cout << "Record does not exist.\n\n";
        }
    }

    return pass;
}

/*****************************************************************
//
//  Function name: printAllRecords
//
//  DESCRIPTION:   Prints out all records in the linked list
//
//  Parameters: this (llist*) : Pointer to current record.
//
//  Return values: void : none
//
****************************************************************/

void llist::printAllRecords()
{
    struct record * temp;
    char uaddress[60];
    char tempaddress[60];
    int count, track;

    temp = start;
    track = 0;

    if (temp == NULL)
    {
        cout << "There are no records.\n";
    }

    while (temp != NULL)
    {
        strcpy(uaddress, temp->address);

        for (count = 0; count < 60;)
        {
            tempaddress[count] = uaddress[count];
            if (uaddress[count] == '+')
            {
                tempaddress[count] = '\0';
                count = 60;
            }
            count = count + 1;
        }

        cout << "-------------------------\n";
        cout << "Record account number:  " << temp->accountno << endl;
        cout << "Name: " << temp->name << endl;
        cout << "Address: " << tempaddress << endl;
        cout << "-------------------------\n";

        temp = temp->next;
        track = track + 1;

        #ifdef DEBUG
            cout << "Ammont of records: " << track << endl;
        #endif
    }
}

/*****************************************************************
//
//  Function name: deleteRecord
//
//  DESCRIPTION:   Deletes record with the given account number.
//
//  Parameters:    uaccountno (int) : Account number entered by user.
//                 this (llist*) : Pointer to current record.
//
//  Return values: -1 : fail
//                 0 : success
//
****************************************************************/

int llist::deleteRecord(int uaccountno)
{
    struct record * temp;
    struct record * prev;
    struct record * del;
    int tempNum;
    int pass;

    tempNum = 0;
    temp = start;

    if (start == NULL)
    {
        cout << "Record does not exist.\n\n";
        pass = -1;
    }
    else if (temp->accountno == uaccountno || temp->next == NULL)
    {
        tempNum = temp->accountno;

        if (tempNum == uaccountno)
        {
            while (uaccountno == tempNum && temp != NULL)
            {
                cout << "Record Found! Deleting record #" << tempNum << endl << endl;
                #ifdef DEBUG
                    cout << "Deleted Record No:" << uaccountno <<endl;
                    cout << "Deleted Record Name:" << temp->name <<endl;
                    cout << "Deleted Record Address:" << temp->address <<endl;
                #endif
                prev = temp;
                temp = temp->next;
                delete prev;
                prev = NULL;

                if (temp != NULL)
                {
                    tempNum = temp->accountno;
                }
            }
            start = temp;
            pass = 0;
        }
        else
        {
            cout << "Record does not exist.\n\n";
            pass = -1;
        }
    }
    else
    {
        prev = temp;
        temp = temp->next;
        tempNum = temp->accountno;

        do
        {
            if (tempNum == uaccountno)
            {
                while (uaccountno == tempNum && temp != NULL)
                {
                    cout << "Record Found! Deleting record #" << tempNum << endl << endl;
                    #ifdef DEBUG
                        cout << "Deleted Record No:" << uaccountno <<endl;
                        cout << "Deleted Record Name:" << temp->name <<endl;
                        cout << "Deleted Record Address:" << temp->address <<endl;
                    #endif
                    del = temp;
                    prev->next = temp->next;
                    temp = temp->next;
                    delete del;
                    del = NULL;

                    if (temp != NULL)
                    {
                        tempNum = temp->accountno;
                    }
                }
                pass = 0;
            }
            else
            {
                prev = temp;
                temp = temp->next;
                pass = -1;
                if (temp != NULL)
                {
                    tempNum = temp->accountno;
                }
            }
        } while (temp != NULL && pass == -1);
        if (pass == -1)
        {
            cout << "Record does not exist.\n\n";
        }
    }

    return pass;
}

/*****************************************************************
//
//  Function name: readfile
//
//  DESCRIPTION:   Reads the file
//
//  Parameters: this (llist*) : Pointer to current record.
//
//  Return values: -1 : fail
//                 0 : success
//
****************************************************************/

int llist::readfile()
{
    int pass, i, size, num, r;
    int uaccountno;
    char uname[30];
    char uaddress[60];
    char cpyName[30];
    char character;
    string trash;

    memset(uaddress, 0, 60);
    memset(uname, 0, 30);


    ifstream ifs (filename, ifstream::in);

    pass = 0;

    ifs >> num;

    while(ifs.peek() != EOF)
    {
        uaccountno = num;
        getline(ifs, trash);

        i = 0;
        do
        {
            ifs.get(character);
            uname[i] = character;
            i = i + 1;
        } while(character != '\n');

        uname[i - 1] = '\0';

        r = 0;
        do
        {
            getline(ifs, trash, '\n');
            size = trash.length();
            for(i = 0; i < size; i++)
            {
                uaddress[r] = trash[i];
                r++;
            }
        } while(uaddress[r - 1] != '+');

        uaddress[r] = '\0';

        strcat(uaddress, "\n");

        for (i = 0; i < 30; i++) 
        {
            if (uname[i] == '\n')
            {
                cpyName[i] = '\0';
                i = 30;
            }
            else
            {
                strncpy(cpyName, uname, i + 1);
            }
        }
            
        addRecord(uaccountno, cpyName, uaddress);

        memset(uaddress, 0, 60);
        memset(uname, 0, 30);

        ifs >> num;
    }
    ifs.close();
    return pass;
}

/*****************************************************************
//
//  Function name: writefile
//
//  DESCRIPTION:   Writes to the file
//
//  Parameters: this (llist*) : Pointer to current record.
//
//  Return values: -1 : fail
//                 0 : success
//
****************************************************************/

int llist::writefile()
{
    int pass;
    struct record * temp;

    ofstream ofs (filename, ofstream::out);

    temp = start;
    pass = 0;

    while (temp != NULL)
    {

        ofs << temp->accountno << "\n";
        ofs << temp->name << "\n";
        ofs << temp->address << "\n";
        temp = temp->next;
    }

    ofs.close();

    return pass;
}

/*****************************************************************
//
//  Function name: cleanup
//
//  DESCRIPTION:   Deallocates all the space in the linked list.
//
//  Parameters: this (llist*) : Pointer to current record.
//
//  Return values: void : None
//
****************************************************************/


void llist::cleanup()
{
    struct record * temp;
    struct record * del;

    temp = start;

    if (temp == NULL)
    {
        cout << "There are no records to cleanup.\n";
    }
    while (temp != NULL)
    {
        del = temp;
        temp = temp->next;
        delete del;
        del = NULL;
    }
    start = NULL;
}


/* Constructors and Deconstructors */

llist::llist()
{
    start = NULL;
    strcpy(filename, "test.txt");
    readfile();
}

llist::llist(char userFile[])
{
    start = NULL;
    strcpy(filename, userFile);
    readfile();
}

llist::~llist()
{
    writefile();
    cleanup();
}
