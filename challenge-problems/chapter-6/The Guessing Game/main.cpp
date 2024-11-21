/*****
 * Author: Glowstudent
 * Program: The Guessing Game
 *****/

#include <iostream>
#include <string>
#include <limits>
#include "consoleUtils.h"

using namespace std;

void printMenu(int menu)
{
    switch (menu)
    {
    case 0:
        clearScreen();
        fullLine(40, '*');
        printText("The Guessing Game", 40, Alignment::center, 0);
        fullLine(40, '*');
        printText("1. Start Game", 40, Alignment::left, 4);
        printText("2. View Attempts", 40, Alignment::left, 4);
        printText("3. View Wins", 40, Alignment::left, 4);
        printText("4. Exit", 40, Alignment::left, 4);
        fullLine(40, '*');
        break;
    default:
        break;
    }
}

int main()
{
    const int menu = 0;
    int choice;

    printMenu(menu);
    getInt_Menu(choice, menu, &printMenu, 1, 4, "", true);

    cout << "You chose: " << choice << endl;

    return 0;
}