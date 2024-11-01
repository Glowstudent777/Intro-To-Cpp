/*****
 * Author: Glowstudent
 * Program: Population
 *****/

#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main()
{
    int startingPopulation, averageDailyIncrease, days;

    cout << "Enter the starting population: ";
    cin >> startingPopulation;

    while (startingPopulation < 2 || cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "The starting population must be at least 2." << endl;
        cout << "Enter the starting population: ";
        cin >> startingPopulation;
    }

    cout << "Enter the average daily population increase (as a percentage): ";
    cin >> averageDailyIncrease;

    while (averageDailyIncrease < 0 || cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "The average daily population increase must be at least 0." << endl;
        cout << "Enter the average daily population increase (as a percentage): ";
        cin >> averageDailyIncrease;
    }

    cout << "Enter the number of days to multiply: ";
    cin >> days;

    while (days < 1 || cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "The number of days must be at least 1." << endl;
        cout << "Enter the number of days: ";
        cin >> days;
    }

    cout << endl;

    cout << "Day\tApproximate Population" << endl;
    cout << "------------------------------" << endl;

    cout << fixed << setprecision(0);
    for (int i = 1; i <= days; i++)
    {
        cout << i << "\t\t" << startingPopulation << endl;
        startingPopulation += startingPopulation * averageDailyIncrease / 100;
    }

    return 0;
}