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
#include <map>

using namespace std;

void printMenu(int menu);
void getRandomName(string &rname);
void playGame();
void mainMenu();
void exitGame();
void writeAttempts(bool win, int attempts);
void viewAttempts();
void viewWinners();
void writeWinners(string name);

void exitGame()
{
    exit(0);

    return;
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

    return;
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

    // Free up memory?
    emptyVector(names);

    normalizeString(rname);

    return;
}

void writeAttempts(bool win, int attempts)
{
    ofstream outFile;
    outFile.open("attempts.txt", ios::app);

    if (!outFile)
    {
        cout << "Error opening file." << endl;
        return;
    }

    outFile << win << "," << attempts << endl;

    outFile.close();

    return;
}

void writeWinners(string name)
{
    ofstream outFile;
    ifstream inFile;
    string s;
    map<string, int> winners;

    inFile.open("winners.txt");

    if (!inFile)
    {
        outFile.open("winners.txt");
        if (!outFile)
        {
            cout << "Error opening file." << endl;
            return;
        }
        outFile.close();
    }

    while (getline(inFile, s))
    {
        if (s == "")
            continue;

        vector<string> data = splitString(s, ',');
        if (data[0] == name)
        {
            data[1] = stoi(data[1]) + 1;
        }

        winners[data[0]] = stoi(data[1]);
    }

    if (!winners[name])
    {
        winners[name] = 1;
    }

    inFile.close();

    outFile.open("winners.txt");

    if (!outFile)
    {
        cout << "Error opening file." << endl;
        return;
    }

    for (auto winner : winners)
    {
        outFile << winner.first << "," << winner.second << endl;
    }

    outFile.close();

    return;
}

void viewAttempts()
{
    clearScreen();

    ifstream inFile;
    string s;
    int wins = 0, losses = 0, totalAttempts = 0, attempts = 0;

    inFile.open("attempts.txt");

    if (!inFile)
    {
        fullLine(40, '*');
        printText("Attempts", 40, Alignment::center, 0);
        fullLine(40, '*');
        printText("No attempts have been made yet.", 40, Alignment::center, 4);
        fullLine(40, '*');
    }
    else
    {

        while (getline(inFile, s))
        {
            if (s == "")
                continue;

            attempts++;

            vector<string> data = splitString(s, ',');

            if (data[0] == "1")
            {
                wins++;
            }
            else
            {
                losses++;
            }

            totalAttempts += stoi(data[1]);
        }

        inFile.close();

        fullLine(40, '*');
        printText("Attempts", 40, Alignment::center, 0);
        fullLine(40, '*');
        printText(append_string("Wins: ", to_string(wins)), 40, Alignment::left, 4);
        printText(append_string("Losses: ", to_string(losses)), 40, Alignment::left, 4);
        printText(append_string("Total Attempts: ", to_string(totalAttempts)), 40, Alignment::left, 4);
        printText(append_string("Average Attempts: ", stringPrecision(((double)totalAttempts / attempts), 2)), 40, Alignment::left, 4);
        fullLine(40, '*');
    }

    cout << endl;
    cout << "Press ENTER to return to the main menu." << endl;

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get();

    mainMenu();

    return;
}

void viewWinners()
{
    clearScreen();

    ifstream inFile;
    string s;
    int count = 0;

    inFile.open("winners.txt");

    if (!inFile)
    {
        fullLine(50, '*');
        printText("Winners", 50, Alignment::center, 0);
        fullLine(50, '*');
        printText("No Winners have been recorded yet.", 50, Alignment::center, 4);
        fullLine(50, '*');
    }
    else
    {
        fullLine(50, '*');
        printText("Winners", 50, Alignment::center, 0);
        fullLine(50, '*');

        while (getline(inFile, s))
        {
            if (s == "")
                continue;

            vector<string> data = splitString(s, ',');

            printText(append_string("- ", append_string(data[0], append_string(": ", data[1]))), 50, Alignment::left, 4);
            count++;
        }

        inFile.close();

        if (count == 0)
            printText("No Winners have been recorded yet.", 50, Alignment::center, 4);
        fullLine(50, '*');
    }

    cout << endl;
    cout << "Press ENTER to return to the main menu." << endl;

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get();

    mainMenu();

    return;
}

void playGame()
{
    string name, guess, playerName;
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
        writeAttempts(true, attempts);

        cout << "Enter your name: ";
        getline(cin, playerName);
        writeWinners(playerName);
    }
    else
    {
        cout << "Sorry, you did not guess the name." << endl;
        cout << "The name was: " << name << endl;

        writeAttempts(false, attempts);
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

    return;
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
        viewAttempts();
        break;
    case 3:
        viewWinners();
        break;
    case 4:
        cout << "Goodbye!" << endl;
        exitGame();
        break;
    default:
        break;
    }

    return;
}

int main()
{
    setTitle("The Guessing Game");
    mainMenu();

    return 0;
}