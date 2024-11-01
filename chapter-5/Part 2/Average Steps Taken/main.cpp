/*****
 * Author: Glowstudent
 * Program: Average Steps Taken
 *****/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

int getDaysInMonth(int month)
{
    if (month == 2)
    {
        return 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        return 30;
    }
    else
    {
        return 31;
    }
}

int main()
{
    ifstream inFile;
    string s;
    int month = 1, day = 1;
    vector<vector<double>> steps = {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}, {8, 0}, {9, 0}, {10, 0}, {11, 0}, {12, 0}};

    inFile.open("steps.txt");

    if (!inFile)
    {
        cout << "Error opening file." << endl;
        return 1;
    }

    while (getline(inFile, s))
    {
        steps[month - 1][1] += stod(s);

        day++;

        if (month == 2 && day > 28)
        {
            month++;
            day = 1;
        }
        else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        {
            month++;
            day = 1;
        }
        else if (day > 31)
        {
            month++;
            day = 1;
        }
    }
    inFile.close();

    cout << "Month\tAverage Steps" << endl;

    for (int i = 0; i < steps.size(); i++)
    {
        cout
            << fixed << setprecision(0) << steps[i][0] << "\t" << setprecision(2) << (steps[i][1] / getDaysInMonth(i + 1))
            << endl;
    }

    return 0;
}