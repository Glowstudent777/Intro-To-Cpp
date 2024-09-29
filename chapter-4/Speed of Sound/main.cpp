/*****
 * Author: Glowstudent
 * Speed of Sound
 *****/

#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

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
    if (choice == 0)
    {
        cout << "Select a medium for sound to travel through:" << endl;
        cout << "1. Air" << endl;
        cout << "2. Water" << endl;
        cout << "3. Steel" << endl;
    }
    else
    {
        if (choice == 1)
        {
            cout << "You have selected Air" << endl;
        }
        else if (choice == 2)
        {
            cout << "You have selected Water" << endl;
        }
        else if (choice == 3)
        {
            cout << "You have selected Steel" << endl;
        }
    }
}

int main()
{
    const int AIR_SPEED = 1100;
    const int WATER_SPEED = 4900;
    const int STEEL_SPEED = 16400;

    int choice;
    double distance, time;

    clearScreen();
    printMenu(0);

    cout << "Enter your choice: ";
    cin >> choice;

    while (cin.fail() || choice < 1 || choice > 3)
    {
        clearScreen();
        printMenu(0);
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Select a medium for sound to travel through: ";
        cin >> choice;
    }

    clearScreen();
    printMenu(choice);
    cout << "Enter the distance that the sound wave will travel (in feet): ";
    cin >> distance;

    while (cin.fail() || distance < 0)
    {
        clearScreen();
        printMenu(choice);
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Enter the distance that the sound wave will travel (in feet): ";
        cin >> distance;
    }

    switch (choice)
    {
    case 1:
        time = distance / AIR_SPEED;
        break;
    case 2:
        time = distance / WATER_SPEED;
        break;
    case 3:
        time = distance / STEEL_SPEED;
        break;
    }

    cout << setprecision(2) << fixed;
    cout << "The sound wave will travel " << distance << "ft in approximately " << setprecision(4) << time << " seconds" << endl;

    return 0;
}