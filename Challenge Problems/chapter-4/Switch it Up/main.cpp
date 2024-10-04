/*****
 * Author: Glowstudent
 * Switch It Up
 *****/

#include <iostream>
#include <limits>
#include <iomanip>
#include <string>

using namespace std;

// Should never see this. Used in the default section of the switch statements.
string errormsg = "There was an error. Please try again.";

// Let the other functions see these before the full logic function is implemented.
void getInt(int &choice, int program, int min, int max, bool clearOnFail);
void getChar(char &input, int program, bool clearOnFail);
void printMenu(int choice);

// Collection of four programs.
// One takes a day of the week and tells you if it's a weekday or a weekend day
// One takes a number 1 - 7 and tells me what day it is
// One takes a month of the year and tells you what season it is
// One takes a letter and tells me if it is a vowel or a consonant
void WeekDayOrEnd();
void DayofTheWeek();
void MonthSeasons();
void VowelOrCon();

void clearScreen()
{
    // Clear the screen
#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#elif defined(__linux__)
    system("clear");
#elif defined(__APPLE__)
    system("clear");
#endif
}

void printMenu(int choice)
{
    switch (choice)
    {
    case 0:
        cout << "Select a Program to Run:" << endl;
        cout << "1. Weekday or Weekend" << endl;
        cout << "2. Day of the Week" << endl;
        cout << "3. What Season is a Month" << endl;
        cout << "4. Vowel or Consonant" << endl;
        break;
    case 1:
        cout << "Select a Day: " << endl;
        cout << "1. Sunday" << endl;
        cout << "2. Monday" << endl;
        cout << "3. Tuesday" << endl;
        cout << "4. Wednesday" << endl;
        cout << "5. Thursday" << endl;
        cout << "6. Friday" << endl;
        cout << "7. Saturday" << endl;
        break;
    case 2:
        cout << "Enter a number 1-7 to see its corrisponding day of the week." << endl;
        break;
    case 3:
        cout << "Select a Month to See What Season it is Part of:" << endl;
        cout << "1. January       7. July" << endl;
        cout << "2. Febraury      8. August" << endl;
        cout << "3. March         9. September" << endl;
        cout << "4. April         10. October" << endl;
        cout << "5. May           11. November" << endl;
        cout << "6. June          12. December" << endl;
        break;
    case 4:
        cout << "Enter a letter to see if it's a vowel or a consonant: " << endl;
        break;
    default:
        clearScreen();
        printMenu(0);
        getInt(choice, 0, 1, 4, true);
        break;
    }
}

// Later maybe add min/max optional to just get an int no matter what
// Later maybe add string cmessage for a custom message other than "Enter your choice: "
void getInt(int &input, int program, int min, int max, bool clearOnFail = false)
{
    cout << "Enter your choice: ";
    cin >> input;

    while (cin.fail() || input < min || input > max)
    {
        if (clearOnFail == true)
        {
            clearScreen();
            printMenu(program);
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid Input. Please enter a valid input: ";
        cin >> input;
    }
}

void getChar(char &input, int program, bool clearOnFail = false)
{
    cout << "Enter your choice: ";
    cin >> input;

    while (cin.fail() || !isalpha(input))
    {
        if (clearOnFail == true)
        {
            clearScreen();
            printMenu(program);
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid Input. Please enter a valid input: ";
        cin >> input;
    }
}

int main()
{
    int choice;

    clearScreen();
    printMenu(0);

    getInt(choice, 0, 1, 4, true);

    // Set the stage for the programs
    clearScreen();
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (choice)
    {
    case 1:
        WeekDayOrEnd();
        break;
    case 2:
        DayofTheWeek();
        break;
    case 3:
        MonthSeasons();
        break;
    case 4:
        VowelOrCon();
        break;
    default:
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        main();
        break;
    }

    return 0;
}

void WeekDayOrEnd()
{
    int input;

    printMenu(1);
    getInt(input, 1, 1, 7);

    switch (input)
    {
    case 1:
        cout << "Sunday is a Weekend" << endl;
        break;
    case 2:
        cout << "Monday is a Weekday" << endl;
        break;
    case 3:
        cout << "Tuesday is a Weekday" << endl;
        break;
    case 4:
        cout << "Wednesday is a Weekday" << endl;
        break;
    case 5:
        cout << "Thursday is a Weekday" << endl;
        break;
    case 6:
        cout << "Friday is a Weekday" << endl;
        break;
    case 7:
        cout << "Saturday is a Weekend" << endl;
        break;
    default:
        cout << errormsg << endl;
        break;
    }
}

void DayofTheWeek()
{
    int input;

    printMenu(2);
    getInt(input, 2, 1, 7);

    switch (input)
    {
    case 1:
        cout << "That day is Sunday." << endl;
        break;
    case 2:
        cout << "That day is Monday." << endl;
        break;
    case 3:
        cout << "That day is Tuesday." << endl;
        break;
    case 4:
        cout << "That day is Wednesday." << endl;
        break;
    case 5:
        cout << "That day is Thursday" << endl;
        break;
    case 6:
        cout << "That day is Friday." << endl;
        break;
    case 7:
        cout << "That day is Saturday." << endl;
        break;
    default:
        cout << errormsg << endl;
        break;
    }
}

void MonthSeasons()
{
    int input;

    printMenu(3);
    getInt(input, 3, 1, 12);

    switch (input)
    {
    case 1:
        cout << "January is in Winter." << endl;
        break;
    case 2:
        cout << "February is in Winter." << endl;
        break;
    case 3:
        cout << "March is in Spring." << endl;
        break;
    case 4:
        cout << "April is in Spring." << endl;
        break;
    case 5:
        cout << "May is in Spring." << endl;
        break;
    case 6:
        cout << "June is in Summer." << endl;
        break;
    case 7:
        cout << "July is in Summer." << endl;
        break;
    case 8:
        cout << "August is in Summer." << endl;
        break;
    case 9:
        cout << "September is in Fall." << endl;
        break;
    case 10:
        cout << "October is in Fall." << endl;
        break;
    case 11:
        cout << "November is in Fall." << endl;
        break;
    case 12:
        cout << "December is in Winter." << endl;
        break;
    default:
        cout << errormsg << endl;
        break;
    }
}

void VowelOrCon()
{
    char input;

    printMenu(4);
    getChar(input, 4);

    input = tolower(input);

    switch (input)
    {
    case 'a':
        cout << "You entered a vowel." << endl;
        break;
    case 'e':
        cout << "You entered a vowel." << endl;
        break;
    case 'i':
        cout << "You entered a vowel." << endl;
        break;
    case 'o':
        cout << "You entered a vowel." << endl;
        break;
    case 'u':
        cout << "You entered a vowel." << endl;
        break;
    case 'y':
        cout << "'Y' is sometimes a vowel but mostly a consonant." << endl;
        break;
    default:
        cout << "You entered a consonant." << endl;
        break;
    }
}