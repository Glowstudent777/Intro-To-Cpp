/*****
 * Author: Glowstudent
 * Program: Chips and Salsa
 *****/

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <iomanip>

using namespace std;

string capFirstLetter(string str)
{
    str[0] = toupper(str[0]);
    return str;
}

int main()
{
    string salsaNames[] = {"mild", "medium", "sweet", "hot", "zesty"};
    int salsaJars[] = {0, 0, 0, 0, 0};
    int highestSelling, lowestSelling;

    cout << "Enter the sales for each type of salsa for the past month." << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << "Enter the number of jars sold for " << salsaNames[i] << " salsa: ";
        cin >> salsaJars[i];

        while (salsaJars[i] < 0 || cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "The number of jars sold must be at least 0." << endl;
            cout << "Enter the number of jars sold for " << salsaNames[i] << " salsa: ";
            cin >> salsaJars[i];
        }
    }

    int totalJars = 0;

    for (int i = 0; i < 5; i++)
    {
        totalJars += salsaJars[i];

        if (i == 0)
        {
            highestSelling = i;
            lowestSelling = i;
        }
        else
        {
            if (salsaJars[i] > salsaJars[highestSelling])
            {
                highestSelling = i;
            }

            if (salsaJars[i] < salsaJars[lowestSelling])
            {
                lowestSelling = i;
            }
        }
    }

    cout << endl;
    cout << "Sales Report" << endl;
    cout << "--------------------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << left << setw(10) << capFirstLetter(salsaNames[i]) << ": " << salsaJars[i] << " jars" << endl;
    }
    cout << "--------------------" << endl;
    cout << left << setw(10) << "Total" << ": " << totalJars << " jars" << endl;
    cout << endl;
    cout << left << setw(10) << "Highest selling" << ": " << capFirstLetter(salsaNames[highestSelling]) << " salsa" << endl;
    cout << left << setw(10) << "Lowest selling" << ": " << capFirstLetter(salsaNames[lowestSelling]) << " salsa" << endl;
    cout << endl;

    return 0;
}