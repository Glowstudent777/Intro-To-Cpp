/*****
 * Author: Glowstudent
 * Program: The Guessing Game
 *****/

#include <iostream>
#include <string>
#include <limits>
#include "consoleUtils.h"
#include <fstream>
#include <set>

using namespace std;

void printMenu(int menu);
void getRandomName(string &rname);
void playGame();
void mainMenu();
void exitGame();

void exitGame()
{
    cout << "Goodbye!" << endl;
    exit(0);
}

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

void getRandomName(string &rname)
{
    ifstream inFile;
    string s, name;
    int count = 0, random;
    vector<string> names;

    inFile.open("names.txt");
    if (!inFile)
    {
        cout << "Error opening file." << endl;
        return;
    }

    while (getline(inFile, s))
    {
        if (s == "")
            continue;

        count++;
        names.push_back(s);
    }
    inFile.close();

    randomInt(random, 1, count);

    rname = (names[random - 1]);
    normalizeString(rname);

    return;
}

void playGame()
{
    string name, guess;
    int attempts = 0;

    clearScreen();
    getRandomName(name);

    cout << "Welcome to the Guessing Game, the theme is Sesame Street & Muppets!" << endl;
    cout << "I have a name in mind. Can you guess it?" << endl;
    cout << "You have 10 tries to guess the name." << endl;
    cout << endl;

    cout << "[DEBUG] The name is: " << name << endl;

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    do
    {
        cout << "Enter your guess (" << (10 - attempts) << (attempts != 9 ? " tries" : " try") << " left): ";

        getline(cin, guess);
        normalizeString(guess);

        attempts++;
    } while (toUpper(guess) != toUpper(name) && attempts < 10);

    cout << endl;

    if (toUpper(guess) == toUpper(name))
    {
        cout << "Congratulations! You guessed the name in " << attempts << (attempts != 1 ? " tries!" : " try!") << endl;
    }
    else
    {
        cout << "Sorry, you did not guess the name." << endl;
        cout << "The name was: " << name << endl;
    }

    cout << "Play again? (Y/N): ";

    char playAgain;
    cin >> playAgain;

    if (toupper(playAgain) == 'Y')
    {
        playGame();
    }
    else
    {
        mainMenu();
    }
}

void mainMenu()
{
    const int menu = 0;
    int choice;

    printMenu(menu);
    getInt_Menu(choice, menu, &printMenu, 1, 4, "", true);

    switch (choice)
    {
    case 1:
        playGame();
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        cout << "Goodbye!" << endl;
        exitGame();
        break;
    default:
        break;
    }
}

int main()
{
    mainMenu();

    return 0;
}