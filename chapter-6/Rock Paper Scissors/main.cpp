/*****
 * Author: Glowstudent
 * Program: Rock Paper Scissors
 *****/

#include <iostream>
#include <random>
#include <limits>
#include <string>

using namespace std;

int getComputerChoice()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 3);

    return dis(gen);
}

int getUserChoice()
{
    int choice;

    cout << "1. Rock" << endl;
    cout << "2. Paper" << endl;
    cout << "3. Scissors" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    while (choice < 1 || choice > 3 || cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;
        cout << "Invalid choice. Please enter 1, 2, or 3." << endl;
        cout << "Enter your choice: ";
        cin >> choice;
    }

    return choice;
}

string choiceToString(int num)
{
    switch (num)
    {
    case 1:
        return "Rock";
        break;
    case 2:
        return "Paper";
        break;
    case 3:
        return "Scissors";
        break;
    default:
        return "";
        break;
    }
}

int main()
{
    int userChoice, computerChoice;

    cout << "=== Rock Paper Scissors ===" << endl;

    computerChoice = getComputerChoice();
    userChoice = getUserChoice();

    cout << endl;

    cout << "Computer's choice: " << choiceToString(computerChoice) << endl;
    cout << "Your choice: " << choiceToString(userChoice) << endl;

    if (userChoice == computerChoice)
    {
        cout << "It's a tie!" << endl;
    }
    else if ((userChoice == 1 && computerChoice == 3) ||
             (userChoice == 2 && computerChoice == 1) ||
             (userChoice == 3 && computerChoice == 2))
    {
        cout << "You win!" << endl;
    }
    else
    {
        cout << "You lose!" << endl;
    }

    return 0;
}