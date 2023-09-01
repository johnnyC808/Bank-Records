/*****************************************************************
//
//  NAME:        Johanthan Callejo
//
//  HOMEWORK:    Project2
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        Nov 16, 2022
//
//  FILE:        user_interface.cpp
//
//  DESCRIPTION:
//   Display an introductory message and display options to user for the menu. 
//   User will be able to type the option name of the menu items, and collect
//   the appropriate information from user. 
//
//  REFERENCES:
//    None
//
****************************************************************/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <limits>

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
//  Function name: getaddress
//
//  DESCRIPTION:   Displays the intro message and menu options. Allows 
//                 the user to interact with the menu by typing the option.
//                 Calls functions to collect data
//
//  Parameters:    str (char[]) : A character array of user data.
//                 size (int) : size of array str
//
//  Return values:  Void
//
****************************************************************/

void getaddress (char str[], int size)
{
    int count = 0;
    char characters;

    cout << "Please enter in your address.\n";
    cout << "Type '+' when you are finished.\n";

        for (count = 0; count < 60;)
        {
            cin.get(characters);
            str[count] = characters;
            if (characters == '+')
            {
                str[count + 1] = '\0';
                count = 60;
            }
            count = count + 1;
        }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   Prints a table of numbers from 0 to a user specified
//                 number by calling specified functions.
//                 
//
//  Parameters:    argc (int) : The number of elements in argv
//                 argv (char*[]) : An array of arguments passed
//                                  to the program.
//
//  Return values:  0 : Success
//
****************************************************************/

int main(int argc, char* argv[])
{
    int count = 0;
    int pass = 0;
    int accountNum = 0;
    int i = 0;

    string str;
    char addStr[4] = "add";
    char printallStr[9] = "printall";
    char findStr[5] = "find";
    char deleteStr[7] = "delete";
    char quitStr[5] = "quit";
    char copyInput[10] = "";
    char copyWord[10] = "";
    char name[30];
    char cpyName[30];
    char address[60];

    #ifdef DEBUG
        cout << "Entered DEBUG Mode" << endl;
    #endif

    llist list;

    cout << "\nWelcome to the bank records. All data that is entered is safely kept within the database.\n\n";
    cout << "----------------------------------\n";
    cout << "Please type the menu option to select it.\n\n";
    cout << "add - Add a new record into the database\n";
    cout << "printall - Print all the records in the database\n";
    cout << "find - Finds records with a specified account number\n";
    cout << "delete - Delete existing records from the database using the account number\n";
    cout << "quit - Exit the database\n\n";

    do
    {
        cout << "Please type in your option: ";

        getline(cin, str);
        
        if ((str.size() > 0) && (str[0] == 'a'))
        {
            count = 1;
            while ((str[count - 1] != '\0') && (count < 4))
            {
                strncpy(copyInput, str.c_str(), count);
                strncpy(copyWord, addStr, count);
                count = count + 1;
            }

            if (strncmp(copyInput, str.c_str(), count) != 0)
            {
                cout << "Invalid input\n";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else if (strncmp(copyInput, copyWord, count) == 0)
            {
                do
                {
                    pass = 0;
                    accountNum = 0;
                    cout << "Enter in your account number: " << endl;
                    cin >> accountNum;
                    if (!cin || accountNum <= 0)
                    {
                        cout << "Invalid input\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        pass = 0;
                    }
                    else
                    {
                        pass = 1;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                } while (pass == 0);

                cout << "Please enter in your name: ";
                cin.getline(name, 30);
 
                for (i = 0; i < 30; i++) 
                {
                    if (name[i] == '\n')
                    {
                        cpyName[i] = '\0';
                        i = 30;
                    }
                    else
                    {
                        strncpy(cpyName, name, i + 1);
                    }
                }

                getaddress(address, 60);

                list.addRecord(accountNum, cpyName, address);

                memset(address, 0, 60);

                cout << "Record has been added.\n\n";
            }
            else
            {
                count = 0;
                cout << "Please enter in a valid input.\n";
            }
            pass = 0;
        }
        else if ((str.size() > 0) && (str[0] == 'p'))
        {
            count = 1;
            while ((str[count - 1] != '\0') && (count < 9))
            {
                strncpy(copyInput, str.c_str(), count);
                strncpy(copyWord, printallStr, count);
                count = count + 1;
            }
            count = count - 1;

            if (strncmp(copyInput, str.c_str(), count) != 0)
            {
                cout << "Invalid input\n";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else if (strcmp(copyInput, copyWord) == 0)
            {
                cout << "\n";
                list.printAllRecords();
            }
            else
            {
                cout << "Invalid input\n";
                count = sizeof(str);
            }
        }
        else if ((str.size() > 0) && (str[0] == 'f'))
        {
            count = 1;
            while ((str[count - 1] != '\0') && (count < 5))
            {
                strncpy(copyInput, str.c_str(), count);
                strncpy(copyWord, findStr, count);
                count = count + 1;
            }
            count = count - 1;

            if (strncmp(copyInput, str.c_str(), count) != 0)
            {
                cout << "Invalid input\n";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else if (strcmp(copyInput, copyWord) == 0)
            {
                cout << "\n";              
                do
                {
                    pass = 0;
                    accountNum = 0;
                    cout << "Enter in your account number: " << endl;
                    cin >> accountNum;
                    if (!cin || accountNum <= 0)
                    {
                        cout << "Invalid input\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        pass = 0;
                    }
                    else
                    {
                        pass = 1;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                } while (pass == 0);

                list.findRecord(accountNum);

            }
            else
            {
                cout << "Invalid input\n";
                count = sizeof(str);
            }
            pass = 0;
        }
        else if ((str.size() > 0) && (str[0] == 'd'))
        {
            count = 1;
            while ((str[count - 1] != '\0') && (count < 7))
            {
                strncpy(copyInput, str.c_str(), count);
                strncpy(copyWord, deleteStr, count);
                count = count + 1;
            }
            count = count - 1;

            if (strncmp(copyInput, str.c_str(), count) != 0)
            {
                cout << "Invalid input\n";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else if (strcmp(copyInput, copyWord) == 0)
            {
                cout << "\n";      
                do
                {
                    pass = 0;
                    accountNum = 0;
                    cout << "Enter in your account number: " << endl;
                    cin >> accountNum;
                    if (!cin || accountNum <= 0)
                    {
                        cout << "Invalid input\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        pass = 0;
                    }
                    else
                    {
                        pass = 1;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                } while (pass == 0);

                list.deleteRecord(accountNum);

            }
            else
            {
                cout << "Invalid input\n";
                count = sizeof(str);
            }
            pass = 0;
        }
        else if ((str.size() > 0) && (str[0] == 'q'))
        {
            count = 1;
            while ((str[count - 1] != '\0') && (count < 5))
            {
                strncpy(copyInput, str.c_str(), count);
                strncpy(copyWord, quitStr, count);
                count = count + 1;
            }
            count = count - 1;

            if (strncmp(copyInput, str.c_str(), count) != 0)
            {
                cout << "Invalid input\n";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                pass = 0;
            }
            else if (strcmp(copyInput, copyWord) == 0)
            {
                pass = 1;

                #ifdef DEBUG
                    cout << "Exiting Database" << endl;
                #endif

                cout << "\n";
            }
            else
            {
                pass = 0;
                cout << "Invalid input\n";
                count = sizeof(str);
            }
        }
        else
        {
            pass = 0;
            cout << "Invalid input\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (pass == 0);

    return 0;
}