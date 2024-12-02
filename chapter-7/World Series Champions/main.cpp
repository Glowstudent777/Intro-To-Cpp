/*****
 * Author: Glowstudent
 * Program: World Series Champions
 *****/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
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

string toUpper(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = toupper(str[i]);
    }

    return str;
}

void displayTeams()
{
    ifstream inFile;
    vector<string> teams;
    string teamName;

    inFile.open("Teams.txt");

    if (!inFile)
    {
        cout << "Error opening file" << endl;
        return;
    }

    while (getline(inFile, teamName))
    {
        if (teamName == "")
        {
            continue;
        }

        teams.push_back(teamName);
    }
    inFile.close();

    // Format into two columns
    for (int i = 0; i < teams.size(); i++)
    {
        cout << teams[i] << setw(30 - teams[i].length()) << " ";
        if (i % 2 == 1)
        {
            cout << endl;
        }
    }
}

int main()
{
    string teamName;
    string correctTeamName;
    vector<string> winnerArr;
    ifstream inFile;

    inFile.open("WorldSeriesWinners.txt");
    if (!inFile)
    {
        cout << "Error opening file" << endl;
        return 0;
    }
    while (getline(inFile, teamName))
    {
        if (teamName == "")
        {
            continue;
        }

        winnerArr.push_back(teamName);
    }
    inFile.close();

    while (true)
    {
        clearScreen();
        correctTeamName.clear();

        cout << "World Series Champions:" << endl;
        cout << "-----------------------" << endl;
        displayTeams();
        cout << "\n\n";
        cout << "Enter the name of the team you want to see the number of wins for (exit to exit): ";
        getline(cin, teamName);

        while (teamName == "" || teamName == " ")
        {
            cout << "Please enter a valid team name: ";
            getline(cin, teamName);
        }

        if (toUpper(teamName) == "EXIT")
        {
            break;
        }

        int count = 0;
        for (int i = 0; i < winnerArr.size(); i++)
        {
            if (toUpper(winnerArr[i]) == toUpper(teamName))
            {
                correctTeamName = winnerArr[i];
                count++;
            }
        }

        if (!correctTeamName.empty())
            teamName = correctTeamName;

        if (count == 0)
        {
            cout << "The team " << teamName << " has never won the World Series." << endl;
        }
        else
        {
            cout << "The team " << teamName << " has won the World Series " << count << " times." << endl;
        }

        cout << endl;
        cout << "Press enter to continue...";
        cin.ignore();
    }

    return 0;
}